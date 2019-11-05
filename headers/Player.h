/*
Player.h
DEFINISI ABSTRAKSI GAME
*/

//id, 

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Building.h"
#include "Skill.h"

typedef struct {
    List ListOfBuildings;
    Skill S;
} Player;

/* Selektor */
#define ListOfBuildings(P) (P).ListOfBuildings
#define S(P) (P).S

#endif