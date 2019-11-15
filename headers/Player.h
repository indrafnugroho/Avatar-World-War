/*
Player.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Building.h"
#include "Skill.h"

#define Nil 0

typedef struct {
    ArrayDin Buildings;
    Skill S;
    int CH;    // Critical Hit attribute
    int SH;    // Shielded Building attribute (jumlah turn aktif)
    bool AU;    // Attack Up attribute
    bool ET;    // Extra Turn attribute
} Player;

/* Selektor */
#define Buildings(P) (P).Buildings
#define Skill(P) (P).S
#define CHs(P) (P).CH
#define SHs(P) (P).SH
#define AUs(P) (P).AU
#define ETs(P) (P).ET

void CreateNewPlayer(Player P);
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

#endif