/*
Player.c
IMPLEMENTASI ABSTRAKSI Player
*/

#include "Player/Player.h"
#include <stdio.h>
#include "Art/Art.h"

void CreateNewPlayer(Player* P)
/*
I.S.
    Parameter-parameter player belum terisi
F.S.
    Parameter-parameter player terisi, keadaan awal player belum memiliki building apapun dan hanya memiliki skill IU.
*/
{
    QueueCreate(&Skills(*P));
    ListCreate(&Buildings(*P));
    QueueAdd(&Skills(*P), 1);
    CHs(*P) = 0;
    SHs(*P) = 0;
    AUs(*P) = false;
    ETs(*P) = false;
}

int NbOfBuildings(Player P)
/* Mengembalikan banyaknya bangunan yang dimiliki pemain*/
{
    return ListSize(Buildings(P));
}

void ClonePlayer(Player Pin, Player* Pout)
/*
I.S.
    Terdapat sembarang player Pin dan Pout.
F.S.
    Pout memiliki seluruh skill dan building yang dimiliki Pin tanpa tambahan lain*/
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    Buildings(*Pout) = CopyList(Buildings(Pin));
    Skills(*Pout) = CopyList(Skills(Pin));
    SHs(*Pout) = SHs(Pin);
    CHs(*Pout) = CHs(Pin);
    AUs(*Pout) = AUs(Pin);
    ETs(*Pout) = ETs(Pin);
}

void AddSkill(Player* P, int skill) {
    /* Add skill by SkillNum to List Queue*/
    /* Skill List: 
    1. Instant Upgrade (IU)         :   Default skill awal
    2. Shield (SH)                  :   Setelah sebuah lawan menyerang, bangunan pemain
                                        berkurang 1 menjadi sisa 2
    3. Extra Turn (ET)              :   Fort pemain tersebut direbut lawan
    4. Attack Up (AU)               :   Pemain baru saja menyerang Tower lawan dan
                                        jumlah towernya menjadi 3
    5. Critical Hit (CH)            :   Lawan baru saja mengaktifkan skill Extra Turn
    6. Instant Reinforcement (IR)   :   Semua bangunan yang dimiliki memiliki level 4
    7. Barrage (BR)                 :   Lawan baru saja bertambah bangunannya 
                                        menjadi 10 bangunan */
    if (ListSize(Skills(*P)) <= 10) {
        QueueAdd(&Skills(*P),skill);
    } else {
        printf("Your skill queue is full\n");
    }
}

void DisplaySkill(Player* P) {
    /* Menampilkan skill yang tersedia pada terminal */
    if (!QueueIsEmpty(Skills(*P))) {
        int(*skill) = (int*)QueueValueHead(Skills(*P));

        switch ((int)skill) {  // Sesuai skill ID
            case 0:
                printf("-\n");
                break;
            case 1:
                printf("Instant Upgrade\n");
                break;
            case 2:
                printf("Shield\n");
                break;
            case 3:
                printf("Extra Turn\n");
                break;
            case 4:
                printf("Attack Up\n");
                break;
            case 5:
                printf("Critical Hit\n");
                break;
            case 6:
                printf("Instant Reinforcement\n");
                break;
            case 7:
                printf("Barrage\n");
                break;
            default:
                printf("Skill Id Invalid\n");
                break;  // Debugging
        }
    }
    else {
        printf("No Skill Available!\n");
    }
}

void UseSkill(Player* P, Player* PEnemy) {
    /* Menggunakan skill yang tersedia */
    QueueVal_t SkillID;

    if (!QueueIsEmpty(Skills(*P))) {
        QueueDel(&Skills(*P), &SkillID);
        printf("Using skill %d\n", SkillID);
        switch ((int)SkillID) {
            case 1:
                IU(P);
                break;
            case 2:
                SH(P);
                break;
            case 3:
                ET(P);
                break;
            case 4:
                AU(P);
                break;
            case 5:
                CH(P);
                break;
            case 6:
                IR(P);
                break;
            case 7:
                BR(PEnemy);
                break;
            default:
                printf("Invalid Skill\n");
                break;
        }
    } else {
        printf("Skill empty!\n");
    }
}

/****** CEK SKILL ******/
void CheckSkill(Player* P, Player* PEnemy, Word LastCommand) {
    /* Kamus */
    int i;
    bool isLevel4;
    int NbOfTower;
    ListElement* p;

    /* Cek skill IR */
    isLevel4 = true;
    i = 0;
    while (i < NbOfBuildings(*P)) {
        if (Level(*(Building*)(ListElementVal(ListIdx(Buildings(*P), i)))) != 4) {
            isLevel4 = false;
        }
        i++;
    }
    if (isLevel4 && WordEqualsString(LastCommand, "END_TURN")) {
        AddSkill(P, 6);
        AddWarning("You gained INSTANT REINFORCEMENT skill\n");
    }

    /* Cek skill CH */
    if (WordEqualsString(LastCommand, "SKILL") && ETs(*P)) { /* Ada potensi bug */
        AddSkill(PEnemy, 5);
        AddWarning("Your enemy gained CRITICAL HIT skill\n");
    }
}

/****** IMPLEMENTASI EFEK SKILL ******/
void IU(Player* P) {
    /* Instant Upgrade (ID: 1)*/
    /* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
    /* Representasi Array */
    Building* B;
    
    printf("IU Activated\n");
    ListElement* p;
    ListTraversal(p, ListFirstElement(Buildings(*P)), p != Nil) {
        B = ListElementVal(p);
        if(Level(*B) < 4) {
            Level(*B)++;
     
            switch (Type(*B)) {
            case 'C' :
                switch (Level(*B)) {
                case 2 :
                    A(*B) = 15;
                    M(*B) = 60;
                    Pb(*B) = false;
                    break;
                case 3 :
                    A(*B) = 20;
                    M(*B) = 80;
                    Pb(*B) = false;
                    break;
                case 4 :
                    A(*B) = 25;
                    M(*B) = 100;
                    Pb(*B) = false;
                    break;
                }
                break;
            case 'T' :
                switch (Level(*B)) {
                case 2 :
                    A(*B) = 10;
                    M(*B) = 30;
                    Pb(*B) = true;
                    break;
                case 3 :
                    A(*B) = 20;
                    M(*B) = 40;
                    Pb(*B) = true;
                    break;
                case 4 :
                    A(*B) = 30;
                    M(*B) = 50;
                    Pb(*B) = true;
                    break;
                }
                break;
            case 'F' :
                switch (Level(*B)) {
                case 2 :
                    A(*B) = 20;
                    M(*B) = 40;
                    Pb(*B) = false;
                    break;
                case 3 :
                    A(*B) = 30;
                    M(*B) = 60;
                    Pb(*B) = true;
                    break;
                case 4 :
                    A(*B) = 40;
                    M(*B) = 80;
                    Pb(*B) = true;
                    break;
                }
                break;
            case 'V' :
                switch (Level(*B)) {
                case 2 :
                    A(*B) = 10;
                    M(*B) = 30;
                    Pb(*B) = false;
                    break;
                case 3 :
                    A(*B) = 15;
                    M(*B) = 40;
                    Pb(*B) = false;
                    break;
                case 4 :
                    A(*B) = 20;
                    M(*B) = 50;
                    Pb(*B) = false;
                    break;
                }
                break;
            }
        }
    }
}

void SH(Player* P) {
    /* Shield (ID: 2)*/
    /* Bangunan pemain sisa 2 setelah diserang lawan */
    /* Seluruh bangunan yang dimiliki oleh pemain akan memiliki 
    pertahanan selama 2 turn */
    /* Apabila skill ini digunakan 2 kali berturut-turut, 
    durasi tidak akan bertambah, namun menjadi nilai maksimum (2 turn) */
    printf("SH Activated\n");
    SHs(*P) = 4;
}

void ET(Player* P) {
    /* Extra Turn (ID: 3)*/
    /* Fort pemain direbut lawan */
    /* Pemain pada turn selanjutnya tetap pemain yang sama */
    printf("ET Activated\n");
    ETs(*P) = true;
}

void AU(Player* P) {
    /* Attack Up (ID: 4)*/
    /* Pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
    printf("AU Activated\n");
    AUs(*P) = true;
}

void CH(Player* P) {
    /* Critical Hit (ID: 5)*/
    /* Jumlah Troops pada bangunan yang melakukan serangan tepat 
    selanjutnya hanya berkurang ½ dari jumlah seharusnya */
    printf("CH Activated\n");
    CHs(*P) = 1;
}

void IR(Player* P) { /* to ally */
    /* Instant Reinforcement (ID: 6)*/
    /* Bangunan yang dimiliki memiliki level 4 */
    /* Seluruh bangunan mendapatkan tambahan 5 Troops */
    printf("IR Activated\n");
    ListElement* p;
    ListTraversal(p, ListFirstElement(Buildings(*P)), p != Nil) {
        Troops(*(Building*)ListElementVal(p)) += 5;
    }
}

void BR(Player* P) { /* to enemy */
    /* Barrage (ID: 7)*/
    /* Jumlah Troops pada seluruh bangunan musuh akan berkurang
    sebanyak 10 Troops */
    ListElement* p;
    Building* B;

    printf("BR Activated\n");    
    ListTraversal(p, ListFirstElement(Buildings(*P)), p != Nil) {
        B = ListElementVal(p);
        if (10 <= Troops(*B)) Troops(*B) -= 10;
        else Troops(*B) = 0;
    }
}

int CheckNbOfTower(Player P) {
/*  Menghitung jumlah tower yang dimiliki Player */
    int NbOfTower, i;
    
    NbOfTower = 0;
    i = 0;
    while (i < NbOfBuildings(P)) {
        if (Type(*(Building*)(ListElementVal(ListIdx(Buildings(P), i)))) == 'T') NbOfTower++;
        i++;
    }
    return NbOfTower;
}