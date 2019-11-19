/*
Game.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "Building.h"
#include "Player.h"

#include "ArrayDin.h"
#include "GameMap.h"
#include "GameState.h"
#include "Stack.h"
#include "Command.h"
#include "WordProcessor.h"
#include "Graph.h"
typedef struct {
    Player P1;
    Player P2;
    Player* turn;
    ArrayDin Buildings;
    Stack stkGameState;
    Graph grpBuildingAdjacency;
    GameMap map;
} Game;

void GameLoadInitConfig(Game* game, char* filename);
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
    /*
    I.S.
        Game sudah diinisiasi atau turn pemain sebelumnya sudah selesai
    F.S.
        Ganti turn pemain, kemudian menjalankan command yang dimasukkan
        oleh pemain.
    */

void GameLoop(Game* game);
    /*
    I.S.
        Game sudah diinisiasi.
    F.S.
        Satu turn pemain dijalankan.
    */

void GameFinish(Game* game);
    /*
    I.S.
        Game sudah diinisiasi.
    F.S.
        Game sudah selesai dan pesan ditampilkan beserta pemenang game.
    */

#endif
