#include "Art.h"
#include <stdio.h>
#include "pcolor.h"

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
    printf("  [][][][][][]  []  []  []      []  []  []  [][][][][][]\n");
    printf("                 [][][][]        [][][][]\n");
    printf("                  []  []          []  []\n\n");
    reset_print_color();
}
void DisplayMainMenu() {
    set_print_color(YELLOW);
    set_print_color(BOLD);
    printf("                        MAIN MENU\n");
    printf("                   START | LOAD | QUIT \n\n");
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

