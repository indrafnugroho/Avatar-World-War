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

void DisplayMainMenu() {
    set_print_color(BLUE);
    set_print_color(BOLD);
    printf("AVATAR\n");
    reset_print_color();
    set_print_color(RED);
    set_print_color(UNDERLINE);
    printf("World War\n");
    reset_print_color();
}

void DisplayPrompt() {
    set_print_color(BG_RED);
    set_print_color(BOLD);
    printf(" Command ");
    reset_print_color();
}

int main() {
    Word w;
    DisplayMainMenu();
    DisplayPrompt();
    ScanWord(&w); 
    PrintWord(w);
    ScanWord(&w); 
    PrintWord(w);

}
