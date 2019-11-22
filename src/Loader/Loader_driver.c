#include "Loader/Loader.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Load config\n");
    int i;
    ArrayDin buildings, buildings2;
    Graph connect, connect2;
    GameMap map, map2;
    Player P1, P2, P3, P4, *Pturn;
    ListElement* p;

    CreateNewPlayer(&P3);
    CreateNewPlayer(&P4);
    
    ReadConfigFile("config.txt", &buildings, &connect, &map);
    printf("\nBuildings:\n");
    for (i = GetFirstIdx(buildings); i < Neff(buildings); i++) {
        PrintBuilding(*(Building*)Elmt(buildings, i));
    } 
    PrintMap(map, P3, P4);
    printf("\n\nLoad Save\n");
    LoadGameFile("save.txt", &P1, &P2, &buildings2, &connect2, &map2, &Pturn);
    printf("\nBuildings:\n");
    for (i = GetFirstIdx(buildings2); i < Neff(buildings2); i++) {
        PrintBuilding(*(Building*)Elmt(buildings2, i));
    } 
    PrintMap(map2, P1, P2);
    printf("Player1's buildings:\n");
    ListTraversal(p, ListFirstElement(Buildings(P1)), p != Nil) {
        PrintBuilding(*(Building*)ListElementVal(p));
    }
    printf("Player2's buildings:\n");
    ListTraversal(p, ListFirstElement(Buildings(P2)), p != Nil) {
        PrintBuilding(*(Building*)ListElementVal(p));
    }

}
