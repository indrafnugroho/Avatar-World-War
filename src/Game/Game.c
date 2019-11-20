/*
Game.c
IMPLEMENTASI ABSTRAKSI GAME
*/

#include "Game/Game.h"
#include "Loader/Loader.h"
#include "Art/Art.h"
#include <stdio.h>
#include <stdlib.h>
#include "pcolor/pcolor.h"

void GameLoadInitConfig(Game* game, char* filename) {
    /*
    I.S.
        isi map dan arrBuilding pada game sebarang
    F.S.
        map dan arrBuilding pada game diisi dengan bangunan yang telah
	didefinisikan di file "filename"
    */
    /* Algoritma */
    ReadConfigFile(filename, &(game->Buildings), &(game->grpBuildingAdjacency), &(game->map));
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
    CreateNewPlayer(&(game->P1));
    ListAddLast(&Buildings(game->P1), Elmt(game->Buildings, 0));
    CreateNewPlayer(&(game->P2));
    ListAddLast(&Buildings(game->P2), Elmt(game->Buildings, 1));
    game->turn = &(game->P1);
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
    GameLoop(game);
    if (game->turn == &(game->P1)) {
        game->turn = &(game->P2);
    } else {
        game->turn = &(game->P1);
    } 
}

void GameLoop(Game* game) {
    /*
    I.S.
        Game sudah diinisiasi.
    F.S.
        Satu turn pemain dijalankan.
    */
    /* Algoritma */
    Word w;
    PrintMap(game->map, game->P1, game->P2);
    if (game->turn == &(game->P1)) {
        DisplayPrompt2(1, "COMMAND");
    } else {
        DisplayPrompt2(2, "COMMAND");
    }
    ScanWord(&w);
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


