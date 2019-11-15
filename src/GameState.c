#include "GameState.h"

/******** GAME STATE ********/
address CreateGameState(GameState* GS){
    /* Membuat alokasi GameState */
    address P;

    P = (GameState*)malloc(sizeof(GameState));
    if(P != Nil){
        return P;
    }
    else{
        return Nil;
    }    
}

void DeleteGameState(GameState* GS){
    /* Menghapus alokasi GameState */
    free(*GS);
}

GameState CaptureGameState(Game GG, Word RC){
    /* Mengakuisisi GameState saat prosedur dijalankan */
    GameState GS;

    CreateGameState(GS);
    RecentCom(*GS) = RC;
    ClonePlayer(GG->P1,&P1(GS));
    ClonePlayer(GG->P2,&P2(GS));
    StateBuildings(GS) = GG->Buildings;
}


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
