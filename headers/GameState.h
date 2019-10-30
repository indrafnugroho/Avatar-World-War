/*
    ADT GameState.h
    Menyimpan command yang dilakukan selama 1 turn dalam stack
*/

#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#define Nil 0
#define MaxEl 100

#include "bool.h"
#include "Stack.h"

/* Type Definition */
typedef int infotype;
typedef int address;
typedef Stack GameStack;
typedef GameState* ListElement;

/* Recent command */
typedef struct {
    char RecentCom[50];
    Building BuildingState; // Reference to ADT Building
    /* .... another state? */
} GameState;

// typedef struct {
//     GameState State[MaxEl+1];
//     address Top;
// } GameStack;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(GS) ListFirstElement(s)
#define StateTop(GS) ListValueFirst(GS)
#define RecentCom(GS) ListValueFirst(GS).RecentCom


/******** GAME STATE ********/
void CaptureFirstGameState(GameState* G);
/* Mengakuisisi game state pertama setelah memulai turn */

void CaptureGameState(GameState* G);
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