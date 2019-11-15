/*
Game.c
IMPLEMENTASI ABSTRAKSI GAME
*/

#include "Game.h"
#include <stdio.h>
#include "pcolor.h"

void GameLoadInitConfig(Game* game, const char* filename) {
    /*
    I.S.
        isi map dan arrBuilding pada game sebarang
    F.S.
        map dan arrBuilding pada game diisi dengan bangunan yang telah
	didefinisikan di file "filename"
    */
    /* Algoritma */
    LoadConfig(&(game->arrBuilding), &(game->grpBuildingAdjacency));
    GenerateMap();
}

void GameInit(Game* game) {
    /*
    I.S.
        Atribut pada game sembarang
    F.S.
        Atribut didefinisikan sesuai kondisi awal permainan dalam
	spesifikasi. pemain P1 akan memiliki bangunan pada arrBuilding
	indeks pertama, P2 memiliki bangunan indeks kedua, dan gsStack
        kosong
    */
    /* Kamus Lokal */

    /* Algoritma */
    game->P1 = (Player*) malloc(sizeof(Player));
    game->P2 = (Player*) malloc(sizeof(Player));
    PlayerCreate(game->P1, ListElementVal(ListFirstElement(game->arrBuilding)));
    PlayerCreate(game->P2, ListElementVal(ListElementNext(ListFirstElement(game->arrBuilding))));
    game->turn = game->P1;
    StackCreate(&(game->stkGameState));
}

void GameTurn(Game* game) { 
    /*
    I.S.
        Game sudah diinisiasi atau turn pemain sebelumnya sudah selesai
    F.S.
        Ganti turn pemain, kemudian menjalankan command yang dimasukkan
        oleh pemain.
    */
    /* Algoritma */
    // Minta variabel Next turn buat skill Extra Turn
}

void GameLoop(Game* game) {
    /*
    I.S.
        Game sudah diinisiasi.
    F.S.
        Satu turn pemain dijalankan.
    */
    /* Algoritma */
}

void GameFinish(Game* game) {
    /*
    I.S.
        Game sudah diinisiasi.
    F.S.
        Game sudah selesai dan pesan ditampilkan beserta pemenang game.
    */
    /* Algoritma */
}


