#include "GameState/GameState.h"
#include "stdio.h"
#include "stdlib.h"

/******** GAME STATE ********/
GameState* CreateGameState(Player* P1x, Player* P2x, ArrayDin BuildingsState, GameState* GS){
    /* Membuat alokasi GameState */
    Player P1t, P2t;
    ArrayDin Bs;
    GameState* P;

    P = (GameState*)malloc(sizeof(GameState));
    CreateNewPlayer(&P1t);
    CreateNewPlayer(&P2t);
    MakeEmpty(&Bs,100);
    ClonePlayer(P1t,&P1s(*GS));
    ClonePlayer(P2t,&P2s(*GS));
    CopyTab(Bs,&StateBuildings(*GS));
    
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

void CaptureGameState(Player P1x, Player P2x, ArrayDin BuildingsState, Stack GameStack, Word RC){
    /* Mengakuisisi GameState saat prosedur dijalankan */
    GameState GS;

    RecentCom(GS) = RC;
    ClonePlayer(P1x,&P1s(GS));
    ClonePlayer(P2x,&P2s(GS));
    CopyTab(BuildingsState,&StateBuildings(GS));
    PushStkGameState(GS,&GameStack);
}

void RevertGameState(GameState* GS, Player* P1x, Player* P2x, ArrayDin BuildingsState, Stack* GameStack){
    /* Mengembalikan GameState sebelumnya ke Game */
    PopStkGameStack(P1x,P2x,BuildingsState,GameStack);
    ClonePlayer(P1s(*GS),P1x);
    ClonePlayer(P2s(*GS),P2x);
    CopyTab(StateBuildings(*GS),&BuildingsState);
}

/******** GAME STACK ********/
void PushStkGameState(GameState GS, Stack* GameStack){
    /* Push GameState ke stack setiap command selesai dijalankan */
    StackPush(GameStack,CreateGameState(&P1s(GS),&P2s(GS),StateBuildings(GS),&GS));
}

void PopStkGameStack(Player* P1x, Player* P2x, ArrayDin BuildingsState, Stack* GameStack){
    /* Pop GameState terakhir yang disimpan di stack (Top) */
    /* IS: GS berisi GameState Terakhir */
    GameState* GS;
    StackPop(GameStack,&GS);
    (*P1x) = P1s(*GS);
    (*P2x) = P2s(*GS);
    BuildingsState = StateBuildings(*GS);
}

void FlushStkGameState(Stack* GameStack){
    /* Flush semua GameState dan dealokasi GameState setiap selesai turn */
    GameState* GSdump;
    Player P1dump,P2dump;
    ArrayDin Bdump;

    while(!StackIsEmpty(*GameStack)){
        PopStkGameStack(&P1dump,&P2dump,Bdump,GameStack);
        DeleteGameState(GSdump);
    }
}

void InfoStkGameState(Player* P1x, Player* P2x, ArrayDin BuildingsState, Stack* GameStack){
    /* Memberi informasi isi stack GameState */
    printf("Recent Command: ");
    PrintWord(RecentCom(*(GameState*)StackValueTop(*GameStack)));
    printf("Command count: %d\n",ListSize(*(List*)StackValueTop(*GameStack)));
}
