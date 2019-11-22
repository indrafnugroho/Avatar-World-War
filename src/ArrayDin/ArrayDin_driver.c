#include "ArrayDin/ArrayDin.h"
#include "Building/Building.h"
#include <stdio.h>

int main() {
    Building b1, b2, b3, b4, b5;
    ArrayDin buildings, buildings2;
    Building* dump;
    int i;
    Type(b1) = 'C';
    PointCreate(&Koordinat(b1), 1, 2); 
    InitializationBuilding(&b1);
    Type(b2) = 'T';
    PointCreate(&Koordinat(b2), 2, 3); 
    InitializationBuilding(&b2);
    Type(b3) = 'F';
    PointCreate(&Koordinat(b3), 3, 4); 
    InitializationBuilding(&b3);
    Type(b4) = 'C';
    PointCreate(&Koordinat(b4), 4, 5); 
    InitializationBuilding(&b4);
    Type(b5) = 'V';
    PointCreate(&Koordinat(b5), 5, 6); 
    InitializationBuilding(&b5);
    MakeEmpty(&buildings, 4);
    AddAsLastEl(&buildings, &b1);
    AddAsLastEl(&buildings, &b3);
    AddAsLastEl(&buildings, &b2);
    AddAsLastEl(&buildings, &b4);
    GrowTab(&buildings, 2);
    AddAsLastEl(&buildings, &b5);
    CompactTab(&buildings);
    printf("Array 1\nNbElmt: %d\nMaxEl: %d\nIsFull: %d \n", NbElmt(buildings), MaxElement(buildings), IsFull(buildings));
    for (i = GetFirstIdx(buildings); i < Neff(buildings); i++) {
        PrintBuilding(*Elmt(buildings, i));
    }

    printf("Array 2 : copy of 1, delete 3rd element\n");
    CopyTab(buildings, &buildings2);
    DelEli(&buildings2, 2, &dump);
    for (i = GetFirstIdx(buildings2); i < Neff(buildings2); i++) {
        PrintBuilding(*Elmt(buildings2, i));
    }
    printf("%d\n", Search1(buildings, Elmt(buildings, 2)));
    printf("Buildings in (3, 4);\n");
    PrintBuilding(SearchBuilding(buildings2, 3, 4));
     
}
