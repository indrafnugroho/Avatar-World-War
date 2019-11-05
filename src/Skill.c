#include "Skill.h"
#include "Queue.h"

void CreateSkillQueue(Player* P) {
    /* Define queue skill awal yang berisi IU */
    int new = 1;
    QueueCreate(SkillQueue(Skill(P)));  // Reference to player adt P.Skill
    QueueAdd(SkillQueue(Skill(P)), &new);
}

void AddSkill(int SkillNum, Player* P) {
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
    QueueAdd(SkillQueue(Skill(P)), &SkillNum);
}

void DisplaySkill(Player P) {
    /* Menampilkan skill yang tersedia pada terminal */
    switch ((int*)QueueValueHead(SkillQueue(Skill(P)))) {  // Sesuai skill ID
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

void UseSkill(Player* P) {
    /* Menggunakan skill yang tersedia */
    int SkillID;

    if (!SkillIsEmpty(Skill(*P))) {
        QueueDel(Skill(P), &(int*)SkillID);
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
            BR(P);
            break;
        default:
            printf("Invalid Skill\n");
            break;
    }
}

bool SkillIsEmpty(Player P) {
    /* Mengecek apakah skill sudah habis */
    return QueueIsEmpty(Skill(P));
}

/****** CEK SKILL ******/
void CheckSkill(Player* P) {
    if (BangunanCount(*P) == 2) {
        AddSkill(2, P);  // Shield
    }

    // Add more
}

/****** IMPLEMENTASI EFEK SKILL ******/
void IU(Player* P) {
    /* Instant Upgrade (ID: 1)*/
    /* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
    /* Representasi Array */
    int i;
    for (i = GetFirstIdx(Bangunan(*P)); i <= GetLastIdx(Bangunan(*P)); i++) {
        if (Level(Bangunan(*P)[i]) < 4) {
            Level(Bangunan(*P)[i]) += 1;
        }
    }
}

void SH(Player* P, GameState* GS) {
    /* Shield (ID: 2)*/
    /* Bangunan pemain sisa 2 setelah diserang lawan */
    /* Seluruh bangunan yang dimiliki oleh pemain akan memiliki 
   pertahanan selama 2 turn */
    /* Apabila skill ini digunakan 2 kali berturut-turut, 
   durasi tidak akan bertambah, namun menjadi nilai maksimum (2 turn) */
}

void ET(Player* P) {
    /* Extra Turn (ID: 3)*/
    /* Fort pemain direbut lawan */
    /* Pemain pada turn selanjutnya tetap pemain yang sama */
}

void AU(Player* P) {
    /* Attack Up (ID: 4)*/
    /* Pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
}

void CH(Player* P) {
    /* Critical Hit (ID: 5)*/
    /* Jumlah pasukan pada bangunan yang melakukan serangan tepat 
   selanjutnya hanya berkurang ½ dari jumlah seharusnya */
}

void IR(Player* P) {
    /* Instant Reinforcement (ID: 6)*/
    /* Bangunan yang dimiliki memiliki level 4 */
    /* Seluruh bangunan mendapatkan tambahan 5 pasukan */
}

void BR(Player* P) {
    /* Barrage (ID: 7)*/
    /* Jumlah pasukan pada seluruh bangunan musuh akan berkurang
   sebanyak 10 pasukan */
}
