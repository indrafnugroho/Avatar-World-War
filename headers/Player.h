/*
Player.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Building.h"
#include "List.h"
#include "Queue.h"
#include "bool.h"

#define Nil 0

typedef struct {
    List Buildings;
    Queue S;
    int CH;    // Critical Hit attribute
    int SH;    // Shielded Building attribute (jumlah turn aktif)
    bool AU;    // Attack Up attribute
    bool ET;    // Extra Turn attribute
} Player;

/* Selektor */
#define Buildings(P) (P).Buildings
#define Skills(P) (P).S
#define CHs(P) (P).CH
#define SHs(P) (P).SH
#define AUs(P) (P).AU
#define ETs(P) (P).ET

void CreateNewPlayer(Player *P);
/*
I.S.
    Parameter-parameter player belum terisi
F.S.
    Parameter-parameter player terisi, keadaan awal building dan skill player belum ada
*/

int NbOfBuildings(Player P);
/* Mengembalikan banyaknya bangunan yang dimiliki player*/

void ClonePlayer(Player Pin,Player *Pout);
/*
I.S.
    Terdapat sembarang player Pin dan Pout.
F.S.
    Pout memiliki seluruh skill dan building yang dimiliki Pin tanpa tambahan lain.
*/

void AddSkill(Player *P, int skill);
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

void DisplaySkill(Player PP);
/* Menampilkan skill yang tersedia pada terminal */

void UseSkill(Player* P);
/* Menggunakan skill yang tersedia */


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
