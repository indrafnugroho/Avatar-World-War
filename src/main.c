/* main.c */

#include <stdio.h>
#include "bool.h"
#include "List.h"
#include "pcolor.h"
#include "WordProcessor.h"
#define GAMESTATE_MENU 0
#define GAMESTATE_LOAD 1
#define GAMESTATE_GAME 2

int gameState = GAMESTATE_MENU;

void DisplayTitle() {
    set_print_color(BLUE);
    set_print_color(BOLD);
    printf("      []                                   [][][][][]\n");
    printf("     [][]                                  []       []\n");
    printf("    []  [] []      [] [] [][][][][] []     []       []\n");
    printf("   []    [] []    [] [][]    []    [][]    [][][][][]\n");
    printf("  []      [] []  [] []  []   []   []  []   []     []\n");
    printf(" []        [] [][] []    []  []  []    []  []      []\n");
    printf("[]          [] [] []      [] [] []      [] []       []\n\n");
    reset_print_color();
    set_print_color(RED);
    set_print_color(BOLD);
    printf("            []          []  []          []\n");
    printf("             []        []    []        []\n");
    printf("              []  []  []      []  []  []\n");
    printf("               [][][][]        [][][][]\n");
    printf("                []  []          []  []\n\n");
    reset_print_color();
}

void DisplayPrompt() {
    set_print_color(BG_RED);
    set_print_color(BOLD);
    printf(" Command ");
    reset_print_color();
    printf(" ");
}

int main() {
    Word w;
    DisplayTitle();
    while (gameState == GAMESTATE_MENU) {
        DisplayPrompt();
        ScanWord(&w);
        if (WordEqualsString(w, "START") || WordEqualsString(w, "start")) {
            printf("Game Starts!\n");
            gameState = GAMESTATE_LOAD;
        } else if (WordEqualsString(w, "QUIT") || WordEqualsString(w, "quit")) {
            printf("Quitting, huh?\n");
            gameState = -1;
        }  
    }

}
