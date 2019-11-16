/*
    ADT GameState.h
    Menyimpan command yang dilakukan selama 1 turn dalam stack
*/

#ifndef _SKILL_H
#define _SKILL_H

#include "GameState.h"
#include "Queue.h"
#include "bool.h"
#include "stdio.h"

#define MaxSkill 10
typedef struct {
    Queue SkillQueue;
    int SkillCount;
} Skill;

#define SkillQueue(S) (S).SkillQueue
#define SkillCount(S) (S).SkillCount

void CreateSkillQueue(Player* P);
/* Define queue skill awal yang berisi IU */

void AddSkill(int SkillNum, Player* P);
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
                                        menjadi 10 bangunan
*/

void DisplaySkill(Player P);
/* Menampilkan skill yang tersedia pada terminal */

void UseSkill(Player* P, Player* PEnemy);
/* Menggunakan skill yang tersedia */

bool SkillIsEmpty(Player P);
/* Mengecek apakah skill sudah habis */

/****** CEK SKILL ******/
void CheckSkill(Player* P, Player* PEnemy, GameState* GS);
/* Mengecek apakah suatu player mendapatkan skill ketika selesai melakukan command */
/* Dijalankan setiap selesai melakukan command yang berpotensi mendapatkan skill */

/****** IMPLEMENTASI EFEK SKILL ******/
void IU(Player* P);  // ADT Reference to Player
/* Instant Upgrade */
/* Seluruh bangunan yang dimiliki pemain akan naik 1 level */

void SH(Player* P);  // ADT Reference to Player
/* Shield */
/* Seluruh bangunan yang dimiliki oleh pemain akan memiliki 
   pertahanan selama 2 turn */
/* Apabila skill ini digunakan 2 kali berturut-turut, 
   durasi tidak akan bertambah, namun menjadi nilai maksimum (2 turn) */

void ET(Player* P);  // ADT Reference to Player
/* Extra Turn */
/* Pemain pada turn selanjutnya tetap pemain yang sama */

void AU(Player* P);  // ADT Reference to Player **
/* Attack Up */
/* Pertahanan bangunan musuh tidak akan mempengaruhi penyerangan */

void CH(Player* P);  // ADT Reference to Player & Bangunan **
/* Critical Hit */
/* Jumlah pasukan pada bangunan yang melakukan serangan tepat 
   selanjutnya hanya berkurang ½ dari jumlah seharusnya */

void IR(Player* P);  // ADT Reference to Player.Bangunan
/* Instant Reinforcement */
/* Seluruh bangunan mendapatkan tambahan 5 pasukan */

void BR(Player* P);  // ADT Reference to Player
/* Barrage */
/* Jumlah pasukan pada seluruh bangunan musuh akan berkurang
   sebanyak 10 pasukan */

#endif