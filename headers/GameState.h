/*
    ADT GameState.h
    Menyimpan command yang dilakukan selama 1 turn dalam stack
*/

#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#define Nil 0
#define MaxEl 100

#include "Player.h"
#include "Building.h"
#include "Stack.h"
#include "bool.h"

/* Type Definition */
typedef int infotype;
typedef int address;
typedef Stack GameStack;
typedef GameState* ListElement;

/* Recent command */
typedef struct {
    char RecentCom[50];
    Player P1x,P2x;
    /* .... another state? */
} GameState;

// typedef struct {
//     GameState State[MaxEl+1];
//     address Top;
// } GameStack;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(GS) ListFirstElement(GS)
#define StateTop(GS) ListValueFirst(GS)
#define RecentCom(GS) ListValueFirst(GS).RecentCom
#define P1(GS) (GS)->P1
#define P2(GS) (GS)->P2

/******** GAME STATE ********/
void CaptureFirstGameState(GameState* G);
/* Mengakuisisi game state pertama setelah memulai turn */

void CaptureGameState(GameState* G, Player* P);
/* Mengakuisisi game state saat prosedur dijalankan */


/******** GAME STACK ********/
void CreateGameStack(GameStack* GS);
/* IS: Kondisi GameStack sembarang */
/* FS: Terbentuk GameStack kosong */

bool GameStackIsEmpty(GameStack GS);
/* Mengecek kondisi stack */

void PushGameState(GameStack* GS, GameState G);
/* Push game state ke stack setiap command selesai dijalankan */

void PopGameState(GameStack* GS, GameState* G);
/* Pop game state terakhir yang disimpan di stack (Top) */
/* IS: G berisi GameState Terakhir */

#endif