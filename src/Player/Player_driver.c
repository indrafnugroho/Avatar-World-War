#include "Player.h"
#include "stdio.h"

int main() {
    /* Kamus */
    Player P1, P2;

    /* Algoritma */
    CreateNewPlayer(&P1);
    CreateNewPlayer(&P2);
    printf("SkillP1: %d | SkillP2: %d\n", (int*)QueueValueHead(Skills(P1)), (int*)QueueValueHead(Skills(P2)));
    printf("NbP1: %d | NbP2: %d\n", NbOfBuildings(P1), NbOfBuildings(P2));
    for (int i = 2; i <= 7; i++) {
        printf("Adding skill i: %d\n",i);
        AddSkill(&P1, i);
        AddSkill(&P2, i);
        printf("NbOfSkill: %d\n",ListSize(Skills(P1)));
    }
    for (int i = 1; i <= 20; i++) {
        printf("Available skill: ");
        DisplaySkill(&P1);
        printf("NbOfSkill: %d\n",ListSize(Skills(P1)));
        UseSkill(&P1, &P2);
    }
}