/*
Player.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Building.h"
#include "Skill.h"
#include "List.h"

typedef struct {
    Building B[30];
    Queue SkillQueue;
} Player;

/* Selektor */
#define B(P) (P).B
#define SkillQueue(P) (P).SkillQueue
#define Nil 0

void CreateSkillQueue(Player* P);
/*
I.S.
    Pada awal permainan, pemain belum memiliki skill.
F.S.
    Queue skill pemain dibuat, dengan skill awal hanya berisi IU.
*/

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