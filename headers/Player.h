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
    Building B[];
    Skill S;
} Player;

#endif