#include "Player.h"
#include "Building/Building.h"
#include "stdio.h"

int main() {
    /* Kamus */
    Player P1, P2;
    Building B1, B2;

    /* Algoritma */
    CreateNewPlayer(&P1);
    CreateNewPlayer(&P2);

    Type(B1) = 'C';
    InitializationBuilding(&B1);

    Type(B2) = 'V';
    InitializationBuilding(&B2);
    
    ListAddLast(&Buildings(P1),&B1);
    ListAddLast(&Buildings(P2),&B2);

    printf("SkillP1: %d | SkillP2: %d\n", (int*)QueueValueHead(Skills(P1)), (int*)QueueValueHead(Skills(P2)));
    printf("NbP1: %d | NbP2: %d\n", NbOfBuildings(P1), NbOfBuildings(P2));
    for (int i = 2; i <= 7; i++) {
        printf("Adding skill i: %d\n",i);
        AddSkill(&P1, i);
        printf("NbOfSkill: %d\n",ListSize(Skills(P1)));
    }

    for (int i = 1; i <= 7; i++) {
        printf("Available skill: ");
        DisplaySkill(&P1);
        printf("NbOfSkill: %d\n",ListSize(Skills(P1)));
        UseSkill(&P1, &P2);
        PrintBuilding(B1);
        PrintBuilding(B2);
    }

    AddSkill(&P1, 2);
    ClonePlayer(P1,&P2);
    printf("SkillP1: %d | SkillP2: %d\n", (int*)QueueValueHead(Skills(P1)), (int*)QueueValueHead(Skills(P2)));
    printf("NbP1: %d | NbP2: %d\n", NbOfBuildings(P1), NbOfBuildings(P2));
    printf("SHs(P1) : %d | SHs(P2) : %d\n",SHs(P1),SHs(P2));
    printf("CHs(P1) : %d | CHs(P2) : %d\n",CHs(P1),CHs(P2));
    printf("AUs(P1) : %d | AUs(P2) : %d\n",AUs(P1),AUs(P2));
    printf("ETs(P1) : %d | ETs(P2) : %d\n",ETs(P1),ETs(P2));

    return 0;
}