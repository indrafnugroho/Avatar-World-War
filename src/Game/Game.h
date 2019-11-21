/*
Game.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "Building/Building.h"
#include "Player/Player.h"

#include "ArrayDin/ArrayDin.h"
#include "GameMap/GameMap.h"
#include "GameState/GameState.h"
#include "Stack/Stack.h"
#include "Command/Command.h"
#include "WordProcessor/WordProcessor.h"
#include "Graph/Graph.h"
typedef struct {
    Player P1;
    Player P2;
    Player* turn;
    ArrayDin Buildings;
    Stack stkGameState;
    Graph grpBuildingAdjacency;
    GameMap map;
} Game;

#define GameP1(g) (g).P1
#define GameP2(g) (g).P2
#define GamePTurn(g) (g).turn
#define GameBuildings(g) (g).Buildings
#define GameStateStack(g) (g).stkGameState
#define GameBAdj(g) (g).grpBuildingAdjacency
#define GameMatrixMap(g) (g).map

void GameLoadInitConfig(Game* game, char* filename);
    /*
    I.S.
        isi atribut pada game sebarang
    F.S.
        atribut pada game diisi dengan nilai yang telah
	didefinisikan di file "filename"
    */

void GameLoadSave(Game* game, char* filename);
    /*
    I.S.
        isi atribut pada game sebarang
    F.S.
        Sesi game yang telah disimpan dimuat dalam atribut game
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
