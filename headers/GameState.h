/*
    ADT GameState.h
    Menyimpan command yang dilakukan selama 1 turn dalam stack
*/

#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include "Game.h"
#include "bool.h"

typedef int address;

/* Recent state */
typedef struct {
    Word RecentCom;
    Player P1;
    Player P2;
    ArrayDin Buildings;
} GameState;

/* Definisi akses dengan Selektor : Set dan Get */
#define RecentCom(GS) (GS)->RecentCom
#define P1(GS) (GS)->P1
#define P2(GS) (GS)->P2
#define StateBuildings(GS) (GS)->Buildings

/******** GAME STATE ********/
void CreateGameState(GameState* GS);
/* Membuat alokasi GameState */

void DeleteGameState(GameState* GS);
/* Menghapus alokasi GameState */

void CaptureGameState(GameState* GS, Game GG, Word RC);
/* Mengakuisisi GameState saat prosedur dijalankan */

void RevertGameState(GameState* GS, Game* GG);
/* Mengembalikan GameState sebelumnya ke Game */

/******** GAME STACK ********/
void PushStkGameState(GameState GS, Game* GG);
/* Push GameState ke stack setiap command selesai dijalankan */

void PopStkGameStack(GameState *GS, Game* GG);
/* Pop GameState terakhir yang disimpan di stack (Top) */
/* IS: GS berisi GameState Terakhir */

void FlushStkGameState(GameState* GS, Game* GG);
/* Flush semua GameState dan dealokasi GameState setiap selesai turn */

void InfoStkGameState(Game* GG);
/* Memberi informasi isi stack GameState */

#endif