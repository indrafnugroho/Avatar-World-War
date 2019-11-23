#include "GameMap.h"
#include <stdio.h>

int main () {
    GameMap Maps;
    ArrayDin Bldgs;
    Player P1, P2; 
    Building B1,B2,B3,B4;

    CreateEmptyMap(&Maps,10,10);
    MakeEmpty(&Bldgs, 4);
    CreateNewPlayer(&P1);
    CreateNewPlayer(&P2);

    Type(B1) = 'C';
    PointCreate(&Koordinat(B1),10,1);
    InitializationBuilding(&B1);
    AddAsLastEl(&Bldgs,&B1);
    ListAddFirst(&Buildings(P1),&B1);

    Type(B2) = 'T';
    PointCreate(&Koordinat(B2),1,10);
    InitializationBuilding(&B2);
    AddAsLastEl(&Bldgs,&B2);
    ListAddFirst(&Buildings(P2),&B2);

    Type(B3) = 'F';
    PointCreate(&Koordinat(B3),3,3);
    InitializationBuilding(&B3);
    AddAsLastEl(&Bldgs,&B3);

    Type(B4) = 'V';
    PointCreate(&Koordinat(B4),7,7);
    InitializationBuilding(&B4);
    AddAsLastEl(&Bldgs,&B4);

    SetMap(&Maps, Bldgs);

    PrintMap(Maps,P1,P2);
    return 0;
}