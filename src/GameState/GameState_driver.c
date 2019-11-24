#include "Art/Art.h"
#include "Game/Game.h"
#include "GameState.h"

void printAllBuildings(Game g) {    
    for (int i = 0; i < Neff(GameBuildings(g)); i++) {
        PrintBuilding(*Elmt(GameBuildings(g), i));
    }
}

void levelUpAllBuildings(Game g){
    for (int i = 0; i < Neff(GameBuildings(g)); i++) {
        LevelAdd(Elmt(GameBuildings(g), i));
    }
}

int main() {
    /* Kamus */
    GameState GS;
    Player P1, P2;
    ArrayDin Bld;
    Building B1, B2, B3;
    Word RecentCommand;
    Game game;
    char word[20];

    /* Algoritma */
    AddWarning("Game 1 : Start");
    GameLoadInitConfig(&game, "config.txt");
    GameInit(&game);
    CreateEmpty(&RecentCommand);
    /* ... */
    printf("Command 0: ");
    ScanWord(&RecentCom(GS));
    CaptureGameState(GameP1(game), GameP2(game), GameBuildings(game), &GameStateStack(game), RecentCom(GS));

    /* Level up */
    printf("Command 1: ");
    ScanWord(&RecentCom(GS));
    levelUpAllBuildings(game);
    printAllBuildings(game);
    CaptureGameState(GameP1(game), GameP2(game), GameBuildings(game), &GameStateStack(game), RecentCom(GS));
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printf("RecentCom: ");
    PrintWord(RecentCom(GS));
    printf("------------------------\n\n");

    /* Level up 2 */
    printf("Command 2: ");
    ScanWord(&RecentCom(GS));
    levelUpAllBuildings(game);
    printAllBuildings(game);
    CaptureGameState(GameP1(game), GameP2(game), GameBuildings(game), &GameStateStack(game), RecentCom(GS));
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printf("------------------------\n\n");

    /* Revert 1 */
    printf("Reverting...\n");
    RevertGameState(&GameP1(game), &GameP2(game), &GameBuildings(game), &GameStateStack(game));
    printAllBuildings(game);
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printf("------------------------\n\n");

    /* Revert 2 */
    printf("Reverting...\n");
    RevertGameState(&GameP1(game), &GameP2(game), &GameBuildings(game), &GameStateStack(game));
    printAllBuildings(game);
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printf("------------------------\n\n");

    /* Revert 3 */
    printf("Reverting...\n");
    RevertGameState(&GameP1(game), &GameP2(game), &GameBuildings(game), &GameStateStack(game));
    printAllBuildings(game);
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printf("------------------------\n\n");

    /* Flushing */
    /* printf("Flushing...\n");
    FlushStkGameState(&GameStateStack(game));
    printf("Stack size: %d\n", ListSize(GameStateStack(game)));
    printAllBuildings(game);
    printf("------------------------\n\n"); */

    return 0;
}