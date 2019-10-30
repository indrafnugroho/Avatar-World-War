#include "Skill.h"
#include "Queue.h"

void CreateSkillQueue(Skill* S, Player* P) {
    /* Define queue skill awal yang berisi IU */
    int new = 1;
    QueueCreate(Skill(P));  // Reference to player adt P.Skill
    QueueAdd(Skill(P), &new);
}

void AddSkill(int SkillNum, Skill* S, Player* P) {
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
    QueueAdd(Skill(P), &SkillNum);
}

void DisplaySkill(Skill S, Player P) {
    /* Menampilkan skill yang tersedia pada terminal */
    switch ((int*)QueueValueHead(Skill)) {  // Sesuai skill ID
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

void UseSkill(Skill* S) {
    /* Menggunakan skill yang tersedia */
    int SkillID;

    if (!SkillIsEmpty(*Skill)) {
        QueueDel(Skill, &(int*)SkillID);
    }
}

bool SkillIsEmpty(Skill S) {
    /* Mengecek apakah skill sudah habis */
    return QueueIsEmpty(Skill);
}

/****** IMPLEMENTASI EFEK SKILL ******/
void IU(Player* P) {
    /* Instant Upgrade */
    /* Seluruh bangunan yang dimiliki pemain akan naik 1 level */
}

void SH(Player* P) {
    /* Shield */
    /* Seluruh bangunan yang dimiliki oleh pemain akan memiliki 
   pertahanan selama 2 turn */
    /* Apabila skill ini digunakan 2 kali berturut-turut, 
   durasi tidak akan bertambah, namun menjadi nilai maksimum (2 turn) */
}

void ET(Player* P) {
    /* Extra Turn */
    /* Pemain pada turn selanjutnya tetap pemain yang sama */
}

void AU(Player* P) {
    /* Attack Up */
    /* Pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */
}

void CH(Player* P) {
    /* Critical Hit */
    /* Jumlah pasukan pada bangunan yang melakukan serangan tepat 
   selanjutnya hanya berkurang ½ dari jumlah seharusnya */
}

void IR(Player* P) {
    /* Instant Reinforcement */
    /* Seluruh bangunan mendapatkan tambahan 5 pasukan */
}

void BR(Player* P) {
    /* Barrage */
    /* Jumlah pasukan pada seluruh bangunan musuh akan berkurang
   sebanyak 10 pasukan */
}
