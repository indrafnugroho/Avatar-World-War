/* main.c */

#include <stdio.h>
#include "bool.h"
#include "List.h"
#include "pcolor.h"
#include "Loader.h"
#include "WordProcessor.h"
#define GAMESTATE_MENU 0
#define GAMESTATE_LOAD 1
#define GAMESTATE_GAME 2

int gameState = GAMESTATE_MENU;
void clrscr() {
    printf("\e[1;1H\e[2J"); 
}
void DisplayTitle() {
    clrscr();
    set_print_color(BLUE);
    set_print_color(BOLD);
    printf("\n");
    printf("        []                                   [][][][][]\n");
    printf("       [][]                                  []       []\n");
    printf("      []  [] []      [] [] [][][][][] []     []       []\n");
    printf("     []    [] []    [] [][]    []    [][]    [][][][][]\n");
    printf("    []      [] []  [] []  []   []   []  []   []     []\n");
    printf("   []        [] [][] []    []  []  []    []  []      []\n");
    printf("  []          [] [] []      [] [] []      [] []       []\n\n");
    set_print_color(RED);
    printf("              []          []  []          []\n");
    printf("               []        []    []        []\n");
    printf("                []  []  []      []  []  []\n");
    printf("                 [][][][]        [][][][]\n");
    printf("                  []  []          []  []\n\n");
    set_print_color(YELLOW);
    printf("                   START | LOAD | QUIT \n");
    reset_print_color();
}

void DisplayPrompt(const char* info) {
    set_print_color(BG_YELLOW);
    set_print_color(BLACK);
    set_print_color(BOLD);
    printf(" %s ", info);
    reset_print_color();
    printf(" ");
}

int main() {
    Word w;
    DisplayTitle();
    while (gameState == GAMESTATE_MENU) {
        DisplayPrompt("MENU");
        ScanWord(&w);
        if (WordEqualsString(w, "START") || WordEqualsString(w, "start")) {
            printf("Game Starts!\n");
            ReadConfigFile("config.txt");
            gameState = GAMESTATE_LOAD;
        } else if (WordEqualsString(w, "QUIT") || WordEqualsString(w, "quit")) {
            printf("Quitting, huh?\n");
            gameState = -1;
        } else {
            DisplayPrompt("!");
            printf("Invalid Command\n");
        }
    }

}
