#include "Building.h"
#include <stdio.h>

int main() {
    Building B;
    PointX(Koordinat(B)) = 5;
    PointY(Koordinat(B)) = 4;
    Type(B) = 'C';
    InitializationBuilding(&B);
    Troops(B) = 150;
    PrintBuilding(B);
    printf("Level Add\n");
    LevelAdd(&B);
    PrintBuilding(B);
    printf("Level Add\n");
    LevelAdd(&B);
    PrintBuilding(B);
    printf("Level Add\n");
    LevelAdd(&B);
    PrintBuilding(B);
    printf("Level Add\n");
    LevelAdd(&B);
    PrintBuilding(B);
    printf("Level Add\n");
    LevelAdd(&B);
    PrintBuilding(B);
    printf("After Next Turn:\n");
    AddPasukanNextTurn(&B);
    PrintBuilding(B); 
    printf("Back to level 1\n");
    SetLvBuildingToLv1(&B);
    PrintBuilding(B);


}
