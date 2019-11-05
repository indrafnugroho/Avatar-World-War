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
    List ListOfBuildings;
    Skill S;
} Player;

/* Selektor */
#define ListOfBuildings(P) (P).ListOfBuildings
#define S(P) (P).S

int NbOfBuildings();
/* Mengembalikan banyaknya bangunan yang dimiliki pemain*/

#endif