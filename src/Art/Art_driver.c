#include "Art.h"
#include <stdio.h>

int main() {
    clrscr();
    DisplayTitle();
    DisplayPrompt("TEST");
    DisplayTitleMini();
    printf("\n");
    SetPlayerPrompt(1);
    DisplayPrompt2("PLAYER 1"); 
    printf("\n");
    SetPlayerPrompt(2);
    DisplayPrompt2("PLAYER 2");
    printf("\n");
    AddWarning("Warning!");
    printf("Test Warning\n");
    DisplayWarning(); 
    printf("\n");
    return 0;
}
