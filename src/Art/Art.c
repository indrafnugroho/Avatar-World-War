#include "Art/Art.h"
#include <stdio.h>
#include "pcolor/pcolor.h"
#include "bool/bool.h"
#include <string.h>

int _Art_p = 1;
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
    set_print_color(YELLOW);
    set_print_color(BOLD);
    printf("\n");
    printf("                       - wrgmavow -\n");
    set_print_color(BLUE);
    printf("        []                                   [][][][][]\n");
    printf("       [][]                                  []       []\n");
    printf("      []  [] []      [] [] [][][][][] []     []       []\n");
    printf("     []    [] []    [] [][]    []    [][]    [][][][][]\n");
    printf("    []      [] []  [] []  []   []   []  []   []     []\n");
    printf("   []        [] [][] []    []  []  []    []  []      []\n");
    printf("  []          [] [] []      [] [] []      [] []       []\n\n");
    set_print_color(RED);
    printf("   [] [] []      []==[]==[]        []         \\_\\_/_|__\\ \n");
    printf("  =[]=[]=[]=     []==[]==[]    ====[]====     |_|_| |    \n");
    printf("   [] []=[]      []==[]==[]       [][]        |_|_|  |/  \n");
    printf("   []            __======__      []  []       __|__  |   \n");
    printf("   []=======      //    []     []      []       |  _/|_/ \n\n");
    reset_print_color();
}

void DisplayTitleMini() {
    //clrscr();
    set_print_color(YELLOW);
    set_print_color(BOLD);
    printf("\n   wrgmavow ");
    set_print_color(BLUE);
    printf("AᴠᴀᴛᴀR ");
    set_print_color(RED);
    printf("世界大戦\n\n");
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

void SetPlayerPrompt(int p) {
    _Art_p = p;
}

void DisplayPrompt2(const char* info) {
    if (_Art_p == 1) {
        set_print_color(BG_BLUE);
        set_print_color(BLACK);
    } else {
        set_print_color(BG_RED);
        set_print_color(WHITE); 
    }
    set_print_color(BOLD);
    printf(" %s ", info);
    reset_print_color();
    printf(" ");
}



