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
#include "Command/Command.h"

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
    CreateNewPlayer(&GameP1(*game));
    ListAddLast(&Buildings(GameP1(*game)), Elmt(GameBuildings(*game), 0));
    CreateNewPlayer(&GameP2(*game));
    ListAddLast(&Buildings(GameP2(*game)), Elmt(GameBuildings(*game), 1));
    GamePTurn(*game) = &GameP1(*game);
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
    if (GamePTurn(*game) == &GameP1(*game)) {
        GamePTurn(*game) = &GameP2(*game);
    } else {
        GamePTurn(*game) = &GameP1(*game);
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
    int pn;
    Player* enemy;
    ListElement* p;
    do {
        PrintMap(game->map, GameP1(*game), GameP2(*game));
        set_print_color(BLUE);
        set_print_color(BOLD);
        printf("  PLAYER1    %d ", ListSize(Buildings(GameP1(*game))));
        set_print_color(WHITE);
        printf("|");
        set_print_color(RED);
        printf(" %d    PLAYER2\n\n", ListSize(Buildings(GameP2(*game))));
        if (GamePTurn(*game) == &GameP1(*game)) {
            SetPlayerPrompt(1);
            enemy = &GameP2(*game);
        } else {
            SetPlayerPrompt(2);
            enemy = &GameP1(*game);
        }
        DisplayPrompt2("BUILDINGS");
        printf("\n\n");
        set_print_color(BOLD);
        ListTraversal (p, ListFirstElement(Buildings(*GamePTurn(*game))), p != Nil) {
            printf("  ");
            PrintBuilding(*(Building*)ListElementVal(p));
        }
        reset_print_color();
        printf("\n");
        DisplayPrompt2("SKILL");
        if (!StackIsEmpty(Skills(*GamePTurn(*game)))) {
            DisplaySkill(*GamePTurn(*game));
        } else {
            printf("No Available Skills\n");
        }
        //DisplayPrompt2("COMMAND");
    } while (InputCommand(GamePTurn(*game), enemy, &GameBuildings(*game), &GameStateStack(*game), GameBAdj(*game)));
    //ScanWord(&w);
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


