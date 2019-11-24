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
    AddAToAllBuilding(&GameP1(*game));
}

void GameLoadSave(Game* game, char* filename) {
    /*
    I.S.
        isi atribut pada game sebarang
    F.S.
        Sesi game yang telah disimpan dimuat dalam atribut game
    */
    LoadGameFile("save.txt", &GameP1(*game), &GameP2(*game), &GameBuildings(*game), &GameBAdj(*game), &GameMatrixMap(*game), &GamePTurn(*game)); 
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
    if (!ETs(*GamePTurn(*game))) {
        AddWarning("Next Player's turn");
        if (GamePTurn(*game) == &GameP1(*game)) {
            GamePTurn(*game) = &GameP2(*game);
        } else {
            GamePTurn(*game) = &GameP1(*game);
        } 
    } else {
        AddWarning("Extra Turn Activated!");
        ETs(*GamePTurn(*game)) = false;
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
    int loop;
    do {
        clrscr();
        PrintMap(game->map, GameP1(*game), GameP2(*game));
        set_print_color(BLUE);
        set_print_color(BOLD);
        if (CHs(GameP1(*game))) printf("[CH]");
        if (SHs(GameP1(*game))) printf("[SH]");
        if (AUs(GameP1(*game))) printf("[AU]");
        if (ETs(GameP1(*game))) printf("[ET]");
        printf("  PLAYER1    %d ", ListSize(Buildings(GameP1(*game))));
        set_print_color(WHITE);
        printf("|");
        set_print_color(RED);
        printf(" %d    PLAYER2", ListSize(Buildings(GameP2(*game))));
        if (ETs(GameP2(*game))) printf("[ET]");
        if (AUs(GameP2(*game))) printf("[AU]");
        if (SHs(GameP2(*game))) printf("[SH]");
        if (CHs(GameP2(*game))) printf("[CH]");
        set_print_color(WHITE);

        printf("\n  [UNDO : %d]\n\n", ListSize(GameStateStack(*game)));
        if (ListSize(Buildings(GameP2(*game))) == 0) {
            DisplayPrompt("GAME FINISH");
            printf("Player 1 Wins!\n");
            exit(0);
        } else if (ListSize(Buildings(GameP1(*game))) == 0) {
            DisplayPrompt("GAME FINISH");
            printf("Player 2 Wins!\n");
            exit(0);
        }

        if (GamePTurn(*game) == &GameP1(*game)) {
            SetPlayerPrompt(1);
            pn = 1;
            enemy = &GameP2(*game);
        } else {
            SetPlayerPrompt(2);
            pn = 2;
            enemy = &GameP1(*game);
        }
        DisplayWarning();
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
            DisplaySkill(GamePTurn(*game));
        } else {
            printf("No Available Skills\n");
        }
        //DisplayPrompt2("COMMAND");
        loop = InputCommand(GamePTurn(*game), enemy, &GameBuildings(*game), &GameStateStack(*game), GameBAdj(*game));
        if (loop == 2) {
            SaveGameFile("save.txt", GameP1(*game), GameP2(*game), GameBuildings(*game), GameBAdj(*game), GameMatrixMap(*game), pn);
        }
    } while (loop);
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


