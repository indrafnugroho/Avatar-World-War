#include "GameState/GameState.h"
#include "stdio.h"
#include "stdlib.h"

/******** GAME STATE ********/
GameState* CreateGameState(Player P1x, Player P2x, ArrayDin BuildingsState){
    /* Membuat alokasi GameState */
    Player P1t, P2t;
    ArrayDin Bs;
    GameState* P;
    ListElement* k;

    P = (GameState*)malloc(sizeof(GameState));
    CreateNewPlayer(&P1t);
    CreateNewPlayer(&P2t);
    MakeEmpty(&Bs,100);
    ClonePlayer(P1x,&P1s(*P));
    ClonePlayer(P2x,&P2s(*P));

    CopyTab(BuildingsState,&StateBuildings(*P));
    
    if(P != Nil){
        return P;
    }
    else{
        return Nil;
    }
}

void DeleteGameState(GameState* GS){
    /* Menghapus alokasi GameState */
    free(GS);
}

void CaptureGameState(Player P1x, Player P2x, ArrayDin BuildingsState, Stack* GameStack, Word RC){
    /* Mengakuisisi GameState saat prosedur dijalankan */
    GameState GS;
    ListElement* k;
    ClonePlayer(P1x,&P1s(GS));
    ClonePlayer(P2x,&P2s(GS));
    CopyWord(RC,&RecentCom(GS));

    CopyTab(BuildingsState,&StateBuildings(GS));
    PushStkGameState(GS,GameStack);
}

void RevertGameState(Player* P1x, Player* P2x, ArrayDin *BuildingsState, Stack* GameStack){
    /* Mengembalikan GameState sebelumnya ke Game */
    GameState* GS;
    if (!StackIsEmpty(*GameStack)) {
        Player P1t, P2t;
        ArrayDin Bs;
        PopStkGameStack(&GS,GameStack);
        ClonePlayer(P1s(*GS),P1x);
        ClonePlayer(P2s(*GS),P2x);
        RevertTab(StateBuildings(*GS),BuildingsState);
    } 
}

/******** GAME STACK ********/
void PushStkGameState(GameState GS, Stack* GameStack){
    /* Push GameState ke stack setiap command selesai dijalankan */
    StackPush(GameStack,CreateGameState(P1s(GS),P2s(GS),StateBuildings(GS)));
}

void PopStkGameStack(GameState** GS, Stack* GameStack){
    /* Pop GameState terakhir yang disimpan di stack (Top) */
    /* IS: GS berisi GameState Terakhir */
    StackPop(GameStack,GS);
}

void FlushStkGameState(Stack* GameStack){
    /* Flush semua GameState dan dealokasi GameState setiap selesai turn */
    GameState* GSdump;
    Player P1dump,P2dump;
    ArrayDin Bdump;

    while(!StackIsEmpty(*GameStack)){
        PopStkGameStack(&GSdump,GameStack);
        DeleteGameState(GSdump);
    }
}
