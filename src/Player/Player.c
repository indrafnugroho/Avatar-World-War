/*
Player.c
IMPLEMENTASI ABSTRAKSI Player
*/

#include "Player/Player.h"
#include <stdio.h>

void CreateNewPlayer(Player *P)
/*
I.S.
    Parameter-parameter player belum terisi
F.S.
    Parameter-parameter player terisi, keadaan awal player belum memiliki building apapun dan hanya memiliki skill IU.
*/
{
    QueueCreate(&Skills(*P));
    ListCreate(&Buildings(*P));
    QueueAdd(&Skills(*P), (int*)1);
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

void ClonePlayer(Player Pin,Player *Pout)
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
        QueueAdd(&Skills(*P), skill);
    } else {
        printf("Queue skill penuh\n");
    }
}

void DisplaySkill(Player P) {
    /* Menampilkan skill yang tersedia pada terminal */
    switch ((int)QueueValueHead(Skills(P))) {  // Sesuai skill ID
        case 0:
            printf("-\n");
            break;
        case 1:
            printf("IU\n");
            break;
        case 2:
            printf("SH\n");
            break;
        case 3:
            printf("ET\n");
            break;
        case 4:
            printf("AU\n");
            break;
        case 5:
            printf("CH\n");
            break;
        case 6:
            printf("IR\n");
            break;
        case 7:
            printf("BR\n");
            break;
        default:
            printf("Skill Id Invalid\n");
            break;  // Debugging
    }
}

void UseSkill(Player* P,Player* PEnemy) {
    /* Menggunakan skill yang tersedia */
    int SkillID;

    if (!QueueIsEmpty(Skills(*P))) {

        QueueDel(&Skills(*P), &SkillID);
    }

    switch (SkillID) {
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
}


/****** CEK SKILL ******/
void CheckSkill(Player* P, Player* PEnemy, Word LastCommand) {
    /* Kamus */
    int i;
    bool isLevel4;
    int NbOfTower;

    /* Cek skill SH */
    if (WordEqualsString(LastCommand, "ATTACK") && NbOfBuildings(*PEnemy) == 2) {
        AddSkill(PEnemy, 2);  // Shield
        printf("Enemy player gained SHIELD skill\n");
    }

    /* Cek skill IR */
    isLevel4 = true;
    i = 1;
    while (i <= NbOfBuildings(*P)) {
        if (Level(*(Building*)(ListElementVal(ListIdx(Buildings(*P), i)))) != 4) {
            isLevel4 = false;
        }
        i++;
    }
    if (isLevel4) {
        AddSkill(PEnemy, 6);
        printf("Enemy player gained INSTANT REINFORCEMENT skill\n");
    }

    /* Cek skill CH */
    if (WordEqualsString(LastCommand, "SKILL") && ETs(*P)) { /* Ada potensi bug */
        AddSkill(PEnemy, 5);
        printf("Enemy player gained CRITICAL HIT skill\n");
    }

    /* Cek skill AU - Ambigu player ally atau enemy? */
    if (WordEqualsString(LastCommand, "ATTACK")) {
        NbOfTower = 0;
        i = 1;
        while (i <= NbOfBuildings(*P)) {
            if (Type(*(Building*)(ListElementVal(ListIdx(Buildings(*P), i)))) == 'T') {
                NbOfTower += 1;
            }
            i++;
        }
        if (NbOfTower == 3) {
            AddSkill(P, 4);
            printf("Player gained ATTACK UP skill\n");
        }
    }

    /* Cek skill BR */
    if (WordEqualsString(LastCommand, "ATTACK") && (NbOfBuildings(*PEnemy) == 10)) { /* Ada potensi bug */
        AddSkill(P, 7);
        printf("Player gained BARRAGE skill\n");
    }

    /* Cek skill ET */
    /*
    if ( fort direbut lawan ) {
        AddSkill(3, P)
            printf("Player gained EXTRA TURN skill\n");
    }
    */
}

/****** IMPLEMENTASI EFEK SKILL ******/
void IU(Player* P) {
    /* Instant Upgrade (ID: 1)*/
    /* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
    /* Representasi Array */
    ListElement* p;
    ListTraversal (p, ListFirstElement(Buildings(*P)), p != Nil) {
        if (Level(*(Building*)ListElementVal(p)) < 4) {
            Level(*(Building*)ListElementVal(p)) += 1;
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
    SHs(*P) = 2;
    /* 
        Logic: if(SHs(*P) || Ps(B)) 
    */
}

void ET(Player* P) {
    /* Extra Turn (ID: 3)*/
    /* Fort pemain direbut lawan */
    /* Pemain pada turn selanjutnya tetap pemain yang sama */
    ETs(*P) = true;
}

void AU(Player* P) {
    /* Attack Up (ID: 4)*/
    /* Pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
    AUs(*P) = true;
    /* 
        Logic: if(!AUs(*P) && Ps(B)) 
    */
}

void CH(Player* P) {
    /* Critical Hit (ID: 5)*/
    /* Jumlah Troops pada bangunan yang melakukan serangan tepat 
    selanjutnya hanya berkurang ½ dari jumlah seharusnya */
    CHs(*P) = 1;
    /* 
        Logic: Troops(Elmt(B,i)) -= ((float)1 - (float)CHs(*P)/2) * NAttack
    */
}

void IR(Player* P) { /* to ally */
    /* Instant Reinforcement (ID: 6)*/
    /* Bangunan yang dimiliki memiliki level 4 */
    /* Seluruh bangunan mendapatkan tambahan 5 Troops */
    ListElement* p;
    ListTraversal (p, ListFirstElement(Buildings(*P)), p != Nil) {
        Troops(*(Building*)ListElementVal(p)) += 5;
    }
}

void BR(Player* P) { /* to enemy */
    /* Barrage (ID: 7)*/
    /* Jumlah Troops pada seluruh bangunan musuh akan berkurang
    sebanyak 10 Troops */
    ListElement* p;
    ListTraversal (p, ListFirstElement(Buildings(*P)), p != Nil) {
        Troops(*(Building*)ListElementVal(p)) -= 10;
    }
}
