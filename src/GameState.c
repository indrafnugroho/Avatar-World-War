#include "GameState.h"

/******** GAME STATE ********/
void CreateGameState(GameState* GS){
    /* Membuat alokasi GameState */
    Player P1s, P2s;
    ArrayDin Bs;
    
    CreateNewPlayer(&P1s);
    CreateNewPlayer(&P2s);
    MakeEmpty(&Bs,100);
    P1(GS) = P1s;
    P2(GS) = P2s;
    StateBuildings(GS) = Bs;
}

void DeleteGameState(GameState* GS){
    /* Menghapus alokasi GameState */
    free(*GS);
}

void CaptureGameState(Game GG, Word RC){
    /* Mengakuisisi GameState saat prosedur dijalankan */
    GameState GS;

    CreateGameState(GS);
    RecentCom(GS) = RC;
    ClonePlayer(GG->P1,&P1(GS));
    ClonePlayer(GG->P2,&P2(GS));
    StateBuildings(GS) = GG->Buildings;
    PushStkGameState(&GS,*GG);
}

void RevertGameState(GameState* GS, Game* GG){
    /* Mengembalikan GameState sebelumnya ke Game */
    PopStkGameStack(GS,GG);
    GG->P1 = P1(*GS);
    GG->P2 = P2(*GS);
    GG->Buildings = StateBuildings(*GS);
}

/******** GAME STACK ********/
void PushStkGameState(GameState GS, Game* GG){
    /* Push GameState ke stack setiap command selesai dijalankan */
    StackPush(GG->stkGameState,&GS);
}

void PopStkGameStack(GameState* GS, Game* GG){
    /* Pop GameState terakhir yang disimpan di stack (Top) */
    /* IS: GS berisi GameState Terakhir */
    StackPop(GG->stkGameState,GS);
}

void FlushStkGameState(Game* GG){
    /* Flush semua GameState dan dealokasi GameState setiap selesai turn */
    GameState GSdump;

    while(!StackIsEmpty(GG->stkGameState)){
        PopStkGameStack(GG->stkGameState,&GSdump);
        DeleteGameState(&GSdump);
    }
}

void InfoStkGameState(Game* GG){
    /* Memberi informasi isi stack GameState */
    printf("Recent Command: ");
    PrintWord(RecentCom(StackTop(GG->stkGameState)));
    printf("Command count: %d\n",ListSize(StackTop(GG->stkGameState)));
}
