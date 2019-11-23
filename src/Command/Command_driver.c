#include <stdio.h>
#include "Command/Command.h"

int test;
int succeedCounter;
Player P1;
Player P2;
ArrayDin Buildings;
Building B1, B2, B3, B4, B5;
GameState* State1;
Graph Connection;

void print_state() {
    ListElement* El;
    Building* B;
    int i;
    printf("Player 1:\n");
    printf("    Buildings:\n");
    i = 1;
    ListTraversal (El, ListFirstElement(Buildings(P1)), El != Nil) {
        B = ListElementVal(El);

        printf("    %d. ", i);
        PrintBuilding(*B);
        i++;
    }
    if (!QueueIsEmpty(Skills(P1))) printf("    Queue Head: %d\n", ListElementVal(QueueHead(Skills(P1))));
    printf("Player 2:\n");
    printf("    Buildings:\n");
    i = 1;
    ListTraversal (El, ListFirstElement(Buildings(P2)), El != Nil) {
        B = ListElementVal(El);

        printf("    %d. ", i);
        PrintBuilding(*B);
        i++;
    }
    if (!QueueIsEmpty(Skills(P2))) printf("    Queue Head: %d\n", ListElementVal(QueueHead(Skills(P1))));
    printf("\n");
}

void start_test(const char* name) {
    test++;
    print_state();
    printf("Memulai tes %d: %s\n", test, name);
    printf("--------------------------------------------\n");
}

void end_test() {
    printf("--------------------------------------------\n");
    printf("Tes %d berhasil diselesaikan.\n", test);
    printf("\n");
    print_state();
    succeedCounter++;
}

void print_result() {
    printf("Telah dilaksanakan %d tes, semuanya berhasil!\n", test);
}

int main() {

    test = 0;
    succeedCounter = 0;

    printf("Driver Command (Perintah)\n\n");

    // --------------------------------------------------------------------------------

    // SETUP KONDISI PENGUJIAN

    // --------------------------------------------------------------------------------
    
    // setup wajib awal

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    // p1
    CreateNewPlayer(&P1);

    // p2
    CreateNewPlayer(&P2);
    
    // states
    Stack* States;
    StackCreate(States);

    //
    //   6         V
    //   5       C
    //   4     F
    //   3   T
    //   2 C
    //   1   
    //     1 2 3 4 5
    //
    // yang sebelahan ceritanya nyambung / bisa nyerang

    // buildings
    Type(B1) = 'C';
    PointCreate(&Koordinat(B1), 1, 2); 
    InitializationBuilding(&B1);
    Type(B2) = 'T';
    PointCreate(&Koordinat(B2), 2, 3); 
    InitializationBuilding(&B2);
    Type(B3) = 'F';
    PointCreate(&Koordinat(B3), 3, 4); 
    InitializationBuilding(&B3);
    Type(B4) = 'C';
    PointCreate(&Koordinat(B4), 4, 5); 
    InitializationBuilding(&B4);
    Type(B5) = 'V';
    PointCreate(&Koordinat(B5), 5, 6); 
    InitializationBuilding(&B5);
    MakeEmpty(&Buildings, 5);
    AddAsLastEl(&Buildings, &B1); // 0
    AddAsLastEl(&Buildings, &B3); // 1
    AddAsLastEl(&Buildings, &B2); // 2
    AddAsLastEl(&Buildings, &B4); // 3
    AddAsLastEl(&Buildings, &B5); // 4

    // graph
    GraphCreate(&Connection);
    int i;
    for (i = 0; i < 5; i++) {
        GraphNewVertexLast(&Connection);
    }
    for (i = 0; i < 4; i++) {
        GraphAddEdgeIdx(&Connection, i, i+1);
        GraphAddEdgeIdx(&Connection, i+1, i);
    }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    // keadaan dulu

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    // player 1 punya skill
    AddSkill(&P1, 2);

    // b3 dan b5 level up
    Troops(B3) = M(B3);
    LevelAdd(&B3);
    Troops(B5) = M(B5);
    LevelAdd(&B5);

    // punya p1
    ListAddLast(&Buildings(P1), &B1);
    ListAddLast(&Buildings(P1), &B2);

    // punya p2
    ListAddLast(&Buildings(P2), &B3);
    ListAddLast(&Buildings(P2), &B4);
    ListAddLast(&Buildings(P2), &B5);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    // save state dulu

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    State1 = CreateGameState(P1, P2, Buildings);
    StackPush(States, State1);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    // keadaan sekarang

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    
    // player 1 dipake 2 skill pertamanya
    int s;
    QueueDel(&Skills(P1), &s);
    AddSkill(&P1, 3);

    // b1, b2, dan b4 level up
    Troops(B1) = M(B1);
    LevelAdd(&B1);
    Troops(B2) = M(B2);
    LevelAdd(&B2);
    Troops(B2) = M(B2);
    LevelAdd(&B2);
    Troops(B4) = M(B4);
    LevelAdd(&B4);
    Troops(B4) = M(B4);
    LevelAdd(&B4);
    Troops(B4) = M(B4);
    LevelAdd(&B4);
    printf("\n");

    // b3 dan b5 siap level up
    Troops(B3) = M(B3)/2;
    Troops(B5) = M(B5)/2;

    // p1 menang 2 building, b3 dan b4
    ListAddLast(&Buildings(P1), &B3);
    ListAddLast(&Buildings(P1), &B4);

    // p2 kalah 2 building, b3 dan b4
    ListDelVal(&Buildings(P2), &B3);
    ListDelVal(&Buildings(P2), &B4);

    // --------------------------------------------------------------------------------

    // int InputCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState, Graph Connect);
    /* Melakukan input Command menggunakan Word Processor */

    // --------------------------------------------------------------------------------

    start_test("Input perintah.");
    // Isi parameter:
    // PTurn = &P1
    // PEnemy = &P2
    // Bldgs = &Buildings
    // GState = States
    // Connect = Connection

    printf("Command List: ATTACK LEVEL_UP SKILL UNDO END_TURN SAVE MOVE EXIT\n");
    printf(" - Bangunan yang sebelahan bisa move / attack\n");
    printf(" - Bangunan Fort dan Village siap level up\n");
    int a = InputCommand(&P1, &P2, &Buildings, States, Connection);
    printf("--------------------------------------------\n");
    printf("Output perintah: %d\n", a);

    end_test();

    // --------------------------------------------------------------------------------

    print_result();
}