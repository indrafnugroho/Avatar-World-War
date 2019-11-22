#include "Game.h"
#include "Art/Art.h"

int main() {
    Game game, game2;
    AddWarning("Game 1 : Start");
    GameLoadInitConfig(&game, "config.txt");
    GameInit(&game);
    GameTurn(&game);
    GameTurn(&game);
    AddWarning("Game 2 : Load");
    GameLoadSave(&game2, "sav.txt");
    GameTurn(&game);
    GameTurn(&game);
    return 0;
}

