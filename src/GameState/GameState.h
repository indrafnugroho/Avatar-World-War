/*
    ADT GameState.h
    Menyimpan command yang dilakukan selama 1 turn dalam stack
*/

#ifndef _GAMESTATE_H
#define _GAMESTATE_H

//#include "Game.h"
#include "bool/bool.h"
#include "Stack/Stack.h"
#include "WordProcessor/WordProcessor.h"
#include "Player/Player.h"
#include "ArrayDin/ArrayDin.h"

typedef int address;

/* Recent state */
typedef struct {
    Word RecentCom;
    Player P1s;
    Player P2s;
    ArrayDin Buildings;
} GameState;

/* Definisi akses dengan Selektor : Set dan Get */
#define RecentCom(GS) (GS).RecentCom
#define P1s(GS) (GS).P1s
#define P2s(GS) (GS).P2s
#define StateBuildings(GS) (GS).Buildings

/******** GAME STATE ********/
GameState* CreateGameState(Player P1x, Player P2x, ArrayDin BuildingsState);
/* Membuat alokasi GameState */

void DeleteGameState(GameState* GS);
/* Menghapus alokasi GameState */

void CaptureGameState(Player P1x, Player P2x, ArrayDin BuildingsState, Stack* GameStack, Word RC);
/* Mengakuisisi GameState saat prosedur dijalankan */

void RevertGameState(Player* P1x, Player* P2x, ArrayDin* BuildingsState, Stack* GameStack);
/* Mengembalikan GameState sebelumnya ke Game */

/******** GAME STACK ********/
void PushStkGameState(GameState GS, Stack* GameStack);
/* Push GameState ke stack setiap command selesai dijalankan */

void PopStkGameStack(GameState** GS, Stack* GameStack);
/* Pop GameState terakhir yang disimpan di stack (Top) */
/* IS: GS berisi GameState Terakhir */

void FlushStkGameState(Stack* GameStack);
/* Flush semua GameState dan dealokasi GameState setiap selesai turn */

#endif
