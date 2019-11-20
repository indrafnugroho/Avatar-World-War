#include "Art.h"
#include <stdio.h>

int main() {
    clrscr();
    DisplayTitle();
    DisplayPrompt("TEST");
    printf("\n");
    DisplayPrompt2(1, "PLAYER 1"); 
    printf("\n");
    DisplayPrompt2(2, "PLAYER 2");
    printf("\n");
    AddWarning("Warning!");
    DisplayWarning(); 
    printf("\n");
    return 0;
}
