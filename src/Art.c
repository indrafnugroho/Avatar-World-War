#include "Art.h"
#include <stdio.h>
#include "pcolor.h"
#include "bool.h"
#include <string.h>

bool warn = false;
char warnmsg[50];
void clrscr() {
    printf("\e[1;1H\e[2J"); 
}

void AddWarning(const char* w) {
    warn = true;
    strcpy(warnmsg, w);    
}

void DisplayWarning() {
    if (warn) {
        DisplayPrompt("!");
        printf("%s\n", warnmsg);
        warn = false;
    }
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
    printf("                 [][][][] RGMAVO [][][][]\n");
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

