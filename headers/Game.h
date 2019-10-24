/*
Game.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "Building.h"
#include "Player.h"

#include "IArray.h"
#include "GameMap.h"
#include "GameState.h"
#include "Stack.h"
#include "Command.h"
#include "TokenProcessor.h"

typedef struct {
    Player* P1;
    Player* P2;
    Player* turn;
    IArray arrBuilding;
    Stack gsStack;
    GameMap map;
}

void GameLoadInitConfig(Game* game, const char* filename);
    /*
    I.S.
        isi map dan arrBuilding pada game sebarang
    F.S.
        map dan arrBuilding pada game diisi dengan bangunan yang telah
	didefinisikan di file "filename"
    */

void GameInit(Game* game);
    /*
    I.S.
        Atribut pada game sembarang
    F.S.
        Atribut didefinisikan sesuai kondisi awal permainan dalam
	spesifikasi. pemain P1 akan memiliki bangunan pada arrBuilding
	indeks pertama, P2 memiliki bangunan indeks kedua, dan gsStack
        kosong
    */

void GameTurn(Game* game);

void GameLoop(Game* game);

void GameFinish(Game* game);

#endif
