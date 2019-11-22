#include <stdio.h>
#include "Command/Command.h"

int test;
int succeedCounter;

void start_test(const char* name) {
    test++;
    printf("Memulai tes %d: %s\n", test, name);
    printf("--------------------------------------------\n");
}

void end_test() {
    printf("--------------------------------------------\n");
    printf("Tes %d berhasil diselesaikan.\n", test);
    printf("\n");
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

    // p1
    Player P1;
    CreateNewPlayer(&P1);

    // p2
    Player P2;
    CreateNewPlayer(&P2);
    
    // states
    Stack* States;
    StackCreate(States);

    // buildings
    ArrayDin Buildings;
    Building B1, B2, B3, B4, B5;
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

    // keadaan dulu

    // player 1 punya skill
    AddSkill(&P1, 1);
    AddSkill(&P1, 2);

    // punya p1
    ListAddLast(&Buildings(P1), &B1);
    ListAddLast(&Buildings(P1), &B2);

    // punya p2
    ListAddLast(&Buildings(P2), &B3);
    ListAddLast(&Buildings(P2), &B4);
    ListAddLast(&Buildings(P2), &B5);

    GameState* State1 = CreateGameState(P1, P2, Buildings);
    StackPush(States, State1);

    // keadaan sekarang
    
    // player 1 dipake skill pertamanya
    int s;
    QueueDel(&Skills(P1), &s);

    // p1 menang 2 building, b3 dan b4
    ListAddLast(&Buildings(P1), &B3);
    ListAddLast(&Buildings(P1), &B4);

    // p2 kalah 2 building, b3 dan b4
    ListDelVal(&Buildings(P2), &B3);
    ListDelVal(&Buildings(P2), &B4);

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

    // graph
    Graph Connection;
    GraphCreate(&Connection);
    int i;
    for (i = 0; i < 5; i++) {
        GraphNewVertexLast(&Connection);
    }
    for (i = 0; i < 4; i++) {
        GraphAddEdgeIdx(&Connection, i, i+1);
    }


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

    int a = InputCommand(&P1, &P2, &Buildings, States, Connection);
    printf("Hasil: %d\n", a);

    end_test();

    // --------------------------------------------------------------------------------

    // void AttackCommand(Player* PTurn, Player* PEnemy, ArrayDin Bldgs, Graph Connect);
    /* Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */

    // --------------------------------------------------------------------------------

    start_test("Perintah attack di giliran player 1.");
    // Isi parameter:
    // PTurn = &P1
    // PEnemy = &P2
    // Bldgs = Buildings
    // Connect = Connection



    end_test();

    // --------------------------------------------------------------------------------

    // void LevelUpCommand(Player* PSelf);
    /* Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
    yaitu mencetak daftar bangunan yang dimliki user,
    opsi untuk level up bangunan yang mana,
    dan hasil akhir level up. */

    // --------------------------------------------------------------------------------

    start_test("Perintah level up di player 1.");
    // Isi parameter:
    // PSelf = &P1



    end_test();

    // --------------------------------------------------------------------------------

    // void SkillCommand(Player* PTurn, Player* PEnemy);
    /* Melakukan mekanisme Skill apabila user menginput command Skill,
    yang disesuaikan dengan efek Skill masing-masing */

    // --------------------------------------------------------------------------------

    start_test("Perintah gunakan skill di giliran player 1.");
    // Isi parameter:
    // PTurn = &P1
    // PEnemy = &P2



    end_test();

    // --------------------------------------------------------------------------------

    // void UndoCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState);
    /* Melakukan mekanisme Undo apabila user menginput command Undo.
    User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
    Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

    // --------------------------------------------------------------------------------

    start_test("Perintah undo di giliran player 1.");
    // Isi parameter:
    // PTurn = &P1
    // PEnemy = &P2
    // Bldgs = &Buildings
    // GState = States



    end_test();

    // --------------------------------------------------------------------------------

    // void EndTurnCommand(Player* PTurn, Player* PEnemy);
    /* Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

    // --------------------------------------------------------------------------------

    start_test("Perintah end turn di giliran player 1.");
    // Isi parameter:
    // PTurn = &P1
    // PEnemy = &P2



    end_test();

    // --------------------------------------------------------------------------------

    // void MoveCommand(Player* PSelf, ArrayDin Bldgs, Graph Connect);
    /* Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */

    // --------------------------------------------------------------------------------

    start_test("Perintah move di giliran player 1");
    // Isi parameter:
    // PSelf = &P1
    // Bldgs = &Buildings
    // Connect = Connection



    end_test();

    // --------------------------------------------------------------------------------

    // void ExitCommand();
    /* Melakukan mekanisme Exit, yaitu keluar dari permainan */

    // --------------------------------------------------------------------------------

    start_test("Perintah exit di giliran player 1.");



    end_test();

    // --------------------------------------------------------------------------------

    // void AddAToAllBuilding (Player* P);
    /* Melakukan penambahan pasukan (A) terhadap bangunan player */

    // --------------------------------------------------------------------------------

    start_test("Perintah penambahan pasukan kepada player 1.");
    // Isi parameter:
    // P = &P



    end_test();

    // --------------------------------------------------------------------------------

    // void SetToFalse (Player* P);
    /*  I.S. Player terdefinisi.
        F.S. Set All AfterAttack and AfterMove All Player's Building to False
    */

    // --------------------------------------------------------------------------------

    start_test("SetToFalse pada player 1.");
    // Isi parameter:
    // P = &P1



    end_test();

    // --------------------------------------------------------------------------------

    print_result();
}