/* main.c */

#include <stdio.h>
#include "bool.h"
#include "Game.h"
#include "List.h"
#include "Loader.h"
#include "WordProcessor.h"
#include "Art.h"
#include "pcolor.h"
#define GAMESTATE_MENU 0
#define GAMESTATE_LOAD 1
#define GAMESTATE_GAME 2

int gameState = GAMESTATE_MENU;

int main() {
    Word w;
    GameMap map;
    ArrayDin b;
    Graph g;
    Game game;
    while (gameState >= 0) {
        if (gameState == GAMESTATE_MENU) {
            DisplayTitle();
            DisplayMainMenu();
            DisplayWarning();
            DisplayPrompt("MENU");
            ScanWord(&w);
            if (WordEqualsString(w, "START") || WordEqualsString(w, "start")) {
                printf("Game Starts!\n");
                set_print_color(BOLD);
                //ReadConfigFile("config.txt", &b, &g, &map);
                GameLoadInitConfig(&game, "config.txt");
                GameInit(&game);
                gameState = GAMESTATE_GAME;
                reset_print_color();
            } else if (WordEqualsString(w, "QUIT") || WordEqualsString(w, "quit")) {
                printf("Quitting, huh?\n");
                gameState = -1;
            } else {
                AddWarning("Invalid Command");
            }
        } else if (gameState == GAMESTATE_GAME) {
            GameTurn(&game);
        }
    }

}
