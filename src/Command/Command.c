/* Command.c
   Implementasi Command.h */
#ifdef _WIN32
#include <Windows.h>
#define u_sleep Sleep(1000)
#else
#include <unistd.h>
#define u_sleep sleep(1)
#endif
#include "bool/bool.h"
#include "Command.h"
#include "Art/Art.h"
#include <stdio.h>
#include <stdlib.h>

int InputCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState, Graph Connect) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    bool loop;
    loop = true;
        DisplayPrompt2("COMMAND");
        ScanWord(&input);
        if (WordEqualsString(input, "ATTACK")) {
            CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
            AttackCommand(PTurn,PEnemy,*Bldgs,Connect);
            CheckSkill(PTurn,PEnemy,input);
        }
        else if (WordEqualsString(input, "LEVEL_UP")) {
            CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
            LevelUpCommand(PTurn);
        }
        else if (WordEqualsString(input, "SKILL")) {
            SkillCommand(PTurn,PEnemy);
            CheckSkill(PTurn,PEnemy,input);
            FlushStkGameState(GState);
        }
        else if (WordEqualsString(input, "UNDO")) UndoCommand(PTurn,PEnemy,Bldgs,GState);
        else if (WordEqualsString(input, "END_TURN")) {
            EndTurnCommand(PTurn,PEnemy);
            CheckSkill(PTurn,PEnemy,input);
            FlushStkGameState(GState);
            u_sleep;
            return 0;
        }
        else if (WordEqualsString(input, "SAVE")) return 2;
        else if (WordEqualsString(input, "MOVE")) {
            CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
            MoveCommand(PTurn,*Bldgs,Connect);
        }
        else if (WordEqualsString(input, "EXIT")) ExitCommand();
        else AddWarning("Invalid Command");
        return 1;
}

void AttackCommand(Player* PTurn, Player* PEnemy, ArrayDin Bldgs, Graph Connect) {
/*  Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */
    ListElement *El, *El2;
    Building *B, *BT, *CB, *BE;
    int NbBEnemyInit, NbBEnemyFinal;
    int NbTowerPlayerInit, NbTowerPlayerFinal;
    int NbBPlayerInit, NbBPlayerFinal;
    int i=1, j=1;
    int InpBSelf, InpBEnemy, InpTroopsNum;

    DisplayPrompt2("OWNED BUILDINGS");
    printf("\n\n");
    ListTraversal (El, ListFirstElement(Buildings(*PTurn)), El != Nil) {
        B = ListElementVal(El);

        printf("  %d. ", i);
        PrintBuilding(*B);
        i++;
    }
    printf("\n");

    DisplayPrompt2("BUILDING TO USE");
    if (ScanInt(&InpBSelf)) {
        if (InpBSelf < i && InpBSelf > 0) {
            i=1;
            ListTraversal(El, ListFirstElement(Buildings(*PTurn)), El != Nil && i != InpBSelf) i++;
            BT = ListElementVal(El);

            if (!AfterAttack(*BT)) {
                if (!ListIsEmpty(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT))))) {
                    DisplayPrompt2("NEAREST NEUTRAL AND ENEMY BUILDINGS");
                    printf("\n\n");
                    j=1;
                    ListTraversal(El2, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT)))), El2 != Nil) {
                        CB = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El2)));

                        if (ListSearch(Buildings(*PTurn), CB) == Nil) {
                            printf("  %d. ", j);
                            PrintBuilding(*CB);
                            j++;
                        }
                    }
                    printf("\n");
                    if (j > 1) {
                        DisplayPrompt2("BUILDING TO ATTACK");
                        if (ScanInt(&InpBEnemy)) {
                            if (InpBEnemy > 0 && InpBEnemy <= ListSize(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT)))) && InpBEnemy < j) {
                                i=1;
                                ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT)))), El != Nil && i <= InpBEnemy) {
                                    BE = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El)));
                                    if (ListSearch(Buildings(*PTurn), BE) == Nil) i++;
                                }
                                DisplayPrompt2("NUMBER OF TROOPS");
                                if (ScanInt(&InpTroopsNum)) {
                                    if (InpTroopsNum > 0 && InpTroopsNum <= Troops(*BT)) {
                                        //Cek apakah bangunan yang diserang milik lawan
                                        j=1;
                                        ListTraversal(El, ListFirstElement(Buildings(*PEnemy)), ListElementVal(El) != BE && ListElementNext(El) != Nil) j++;                            
                            
                                        NbBPlayerInit = NbOfBuildings(*PTurn);
                                        //Bangunan yang diserang milik lawan
                                        if (ListElementVal(El) == BE) {
                                            NbBEnemyInit = NbOfBuildings(*PEnemy);
                                            NbTowerPlayerInit = CheckNbOfTower(*PTurn);
                                            //Bangunan yang diserang tidak punya pertahanan
                                            //Dapat disebabkan juga oleh skill 
                                            if ((!Pb(*BE) && SHs(*PEnemy)==0) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                                if (CHs(*PTurn)==0) {
                                                    if (InpTroopsNum < Troops(*BE)) {
                                                        Troops(*BE) -= InpTroopsNum;
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        AddWarning("Failed to capture building\n");
                                                    }
                                                    else {
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        ListDelVal(&Buildings(*PEnemy),BE);
                                                        Troops(*BE) = InpTroopsNum - Troops(*BE);
                                                        SetLvBuildingToLv1(BE);
                                                        ListAddLast(&Buildings(*PTurn),BE);
                                                        //Check if Enemy might gain Extra Turn Skill
                                                        if (Type(*BE)=='F') {
                                                            AddSkill(PEnemy,3);
                                                            AddWarning("Building captured!\nYour enemy gained EXTRA TURN Skill");   
                                                        }
                                                        else AddWarning("Building captured!\n");
                                                    }
                                                }
                                                else {
                                                    if (InpTroopsNum < (int) (Troops(*BE)/2)) {
                                                        Troops(*BE) = ((int) (Troops(*BE)/2) - InpTroopsNum)*2;
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        AddWarning("Failed to capture building\n");
                                                    }
                                                    else {
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        ListDelVal(&Buildings(*PEnemy),BE);
                                                        Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/2);
                                                        SetLvBuildingToLv1(BE);
                                                        ListAddLast(&Buildings(*PTurn),BE);
                                                        //Check if Enemy might gain Extra Turn Skill
                                                        if (Type(*BE)=='F') {
                                                            AddSkill(PEnemy,3);
                                                            AddWarning("Building captured!\nYour enemy gained EXTRA TURN Skill");   
                                                        }
                                                        else AddWarning("Building captured!\n");
                                                    }
                                                    CHs(*PTurn) = 0;
                                                }
                                                AUs(*PTurn) = false;
                                            }
                                            //Bangunan yang diserang punya pertahanan
                                            else {
                                                if (InpTroopsNum < (int) (Troops(*BE)/(0.75))) {
                                                    Troops(*BE) -= (int) InpTroopsNum*(0.75);
                                                    Troops(*BT) -= InpTroopsNum;
                                                    AfterAttack(*BT) = true;
                                                    AddWarning("Failed to capture building\n");
                                                }
                                                else {
                                                    Troops(*BT) -= InpTroopsNum;
                                                    AfterAttack(*BT) = true;
                                                    ListDelVal(&Buildings(*PEnemy),BE);
                                                    Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/(0.75));
                                                    SetLvBuildingToLv1(BE);
                                                    ListAddLast(&Buildings(*PTurn),BE); 
                                                    //Check if Enemy might gain Extra Turn Skill
                                                    if (Type(*BE)=='F') {
                                                        AddSkill(PEnemy,3);
                                                        AddWarning("Building captured!\nYour enemy gained EXTRA TURN Skill");
                                                    }
                                                    else AddWarning("Building captured!\n");
                                                }
                                                // if (SHs(*PEnemy)>0) SHs(*PEnemy)--;
                                            }
                                            //Check if Enemy might gain Shield Skill
                                            NbBEnemyFinal = NbOfBuildings(*PEnemy);
                                            if (NbBEnemyInit==3 && NbBEnemyFinal==2) {
                                                AddSkill(PEnemy,2);
                                                AddWarning("Your enemy gained SHIELD skill\n");
                                            }
       
                                            //Check if Player might gain Attack Up Skill
                                            NbTowerPlayerFinal = CheckNbOfTower(*PTurn);
                                            if (NbTowerPlayerInit==2 && NbTowerPlayerFinal==3 && Type(*BE)=='T') {
                                                AddSkill(PTurn,4);
                                                AddWarning("You gained ATTACK UP skill\n");
                                            }
                                        }
                                        //Bangunan yang diserang tidak berkepemilikan
                                        else {
                                            //Bangunan yang diserang tidak memiliki pertahanan
                                            if (!Pb(*BE) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                                if (CHs(*PTurn)==0) {
                                                    if (InpTroopsNum < Troops(*BE)) {
                                                        Troops(*BE) -= InpTroopsNum;
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        AddWarning("Failed to capture building\n");
                                                    }
                                                    else {
                                                        Troops(*BE) = InpTroopsNum - Troops(*BE);
                                                        Troops(*BT) -= InpTroopsNum;
                                                       AfterAttack(*BT) = true;
                                                        ListAddLast(&Buildings(*PTurn),BE);
                                                        AddWarning("Building captured!\n");
                                                    }
                                                }
                                                else {  
                                                    if (InpTroopsNum < (int) (Troops(*BE)/2)) {
                                                        Troops(*BE) = ((int) (Troops(*BE)/2) - InpTroopsNum)*2;
                                                        Troops(*BT) -= InpTroopsNum;
                                                        AfterAttack(*BT) = true;
                                                        AddWarning("Failed to capture building\n");
                                                    }
                                                    else {
                                                        Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/2);
                                                        Troops(*BT) -= InpTroopsNum;
                                                            AfterAttack(*BT) = true;
                                                        ListAddLast(&Buildings(*PTurn),BE);
                                                        AddWarning("Building captured!\n");
                                                    }
                                                    CHs(*PTurn) = 0;
                                                }
                                                AUs(*PTurn) = false;
                                            }
                                            //Bangunan yang diserang memiliki pertahanan
                                            else {
                                                if (InpTroopsNum < (int) (Troops(*BE)/(0.75))) {
                                                    Troops(*BE) -= (int) InpTroopsNum*(0.75);
                                                    Troops(*BT) -= InpTroopsNum;
                                                    AfterAttack(*BT) = true;
                                                    AddWarning("Failed to capture building\n");
                                                }
                                                else {
                                                    Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/(0.75));
                                                    Troops(*BT) -= InpTroopsNum;
                                                    AfterAttack(*BT) = true;
                                                    ListAddLast(&Buildings(*PTurn),BE);
                                                    AddWarning("Building captured!\n");
                                                }
                                            }
                                        }
                                        //Check if Enemy might gain Barrage Skill
                                        NbBPlayerFinal = NbOfBuildings(*PTurn);
                                        if (NbBPlayerInit==9 && NbBPlayerFinal==10) {
                                            AddSkill(PEnemy,7);
                                            AddWarning("Your enemy gained BARRAGE skill\n");
                                        }
                                    }
                                    else AddWarning("Number you input exceeded your building troops");
                                }
                                else AddWarning("Invalid input");
                            }
                            else AddWarning("Invalid input");
                        }
                        else AddWarning("Invalid input");
                    }
                    else AddWarning("No building available to attack");
                }
                else AddWarning("No building available to attack");
            }   
            else AddWarning("A building can only attack ONCE in a turn!");
        }
        else AddWarning("Invalid building");
    }
    else AddWarning("Invalid input");
}

void LevelUpCommand(Player* PSelf) {
/*  Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
    yaitu mencetak daftar bangunan yang dimliki user,
    opsi untuk level up bangunan yang mana,
    dan hasil akhir level up. */
    ListElement* El;
    Building* B;
    int i=1;
    int InpBNUm;

    DisplayPrompt2("OWNED BUILDINGS");
    printf("\n\n");
    ListTraversal (El, ListFirstElement(Buildings(*PSelf)), El != Nil) {
        B = ListElementVal(El);

        printf("  %d. ", i);
        PrintBuilding(*B);
        i++;
    }
    printf("\n");
    DisplayPrompt2("SELECT BUILDING");
    if (ScanInt(&InpBNUm)) {
        if (InpBNUm >0 && InpBNUm <= ListSize(Buildings(*PSelf))) {
            i=1;
            ListTraversal(El, ListFirstElement(Buildings(*PSelf)), El != Nil && i != InpBNUm) i++;
            B = ListElementVal(El);

            if (Level(*B)<4) {
                if (Troops(*B) >= M(*B)/2) {
                    LevelAdd(B);
                    AddWarning("Level Up Success!");
                }
                else {
                    switch (Type(*B)) {
                    case 'C' :
                        AddWarning("Your Castle lacks troops to level up");
                        break;
                    case 'T' :
                        AddWarning("Your Tower lacks troops to level up");
                        break;
                    case 'F' :
                        AddWarning("Your Fort lacks troops to level up");
                        break;
                    case 'V' :
                        AddWarning("Your Village lacks troops to level up");
                        break;
                    }
                }
            }
            else AddWarning("Your building has reached maximum level");
        }
        else AddWarning("Invalid input");
    }
    else AddWarning("Invalid input");
}

void SkillCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan mekanisme Skill apabila user menginput command Skill,
    yang disesuaikan dengan efek Skill masing-masing */
    UseSkill(PTurn,PEnemy);
}

void UndoCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState) {
/*  Melakukan mekanisme Undo apabila user menginput command Undo.
    User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
    Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */
    if (!StackIsEmpty(*GState)) {
        RevertGameState(PTurn, PEnemy, Bldgs, GState); 
    } else {
        AddWarning("Can't undo further actions");
    }
}
void EndTurnCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */
    SetToFalse(PTurn);
    if (ETs(*PTurn)) AddAToAllBuilding(PTurn);
    else {
        AddAToAllBuilding(PEnemy);
        if (SHs(*PTurn)>0) SHs(*PTurn)--;
        if (SHs(*PEnemy)>0) SHs(*PEnemy)--;
    }

}

void MoveCommand(Player* PSelf, ArrayDin Bldgs, Graph Connect) {
/*  Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */
    ListElement* El;
    Building* BSelf, *BReceive;
    int i=1, j=1;
    int InpTroops, InpB, InpBRcv;

    DisplayPrompt2("OWNED BUILDINGS");
    printf("\n\n");
    ListTraversal (El, ListFirstElement(Buildings(*PSelf)), El != Nil) {
        BSelf = ListElementVal(El);

        printf("  %d. ", i);
        PrintBuilding(*BSelf); 
        i++;
    }

    printf("\n");
    DisplayPrompt2("FROM");
    if (ScanInt(&InpB)) {
        if (InpB > 0 && InpB <= ListSize(Buildings(*PSelf))) {
            ListTraversal(El, ListFirstElement(Buildings(*PSelf)), El != Nil && j != InpB) j++;
            BSelf = ListElementVal(El);

            if (!AfterMove(*BSelf)) {
                DisplayPrompt2("NEAREST OWNED BUILDINGS");
                printf("\n\n");
                j=1;
                ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf)))), El!=Nil) {
                    BReceive = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El)));
                    if (ListSearch(Buildings(*PSelf), BReceive) != Nil) {
                        printf("  %d. ", j);
                        PrintBuilding(*BReceive) ;
                        j++;
                    }
                }

                if (j > 1) {
                    printf("\n");
                    DisplayPrompt2("TO");
                    if (ScanInt(&InpBRcv)) {
                        if (InpBRcv > 0 && InpBRcv <= ListSize(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf)))) && InpBRcv < j) {
                            j=1;
                            ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf)))), El != Nil && j <= InpBRcv) {
                                BReceive = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El)));
                                if (ListSearch(Buildings(*PSelf), BReceive) != Nil) j++; 
                            }
                            //PrintBuilding(*BReceive);
                            DisplayPrompt2("TROOPS TO MOVE");
                            if (ScanInt(&InpTroops)) {
                                if (InpTroops > 0 && InpTroops <= Troops(*BSelf)) {
                                    Troops(*BSelf) -= InpTroops;
                                    Troops(*BReceive) += InpTroops;
                                    printf("%d troops from ", InpTroops);
                                    switch (Type(*BSelf)) {
                                    case 'C' :
                                        printf("Castle (%d,%d) ", Koordinat(*BSelf).x, Koordinat(*BSelf).y);
                                        break;
                                    case 'T' :
                                        printf("Tower (%d,%d) ", Koordinat(*BSelf).x, Koordinat(*BSelf).y);
                                        break;
                                    case 'F' :
                                        printf("Fort (%d,%d) ", Koordinat(*BSelf).x, Koordinat(*BSelf).y);
                                        break;
                                    case 'V' :
                                        printf("Village (%d,%d) ", Koordinat(*BSelf).x, Koordinat(*BSelf).y);
                                        break;
                                    }
                                    printf("has been moved to ");
                                    switch (Type(*BReceive)) {
                                    case 'C' :
                                        printf("Castle (%d,%d)\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y);
                                        break;
                                    case 'T' :
                                        printf("Tower (%d,%d)\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y);
                                        break;
                                    case 'F' :
                                        printf("Fort (%d,%d)\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y);
                                        break;
                                    case 'V' :
                                        printf("Village (%d,%d)\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y);
                                        break;
                                    }
                                    AfterMove(*BSelf) = true;
                                }
                                else AddWarning("Invalid input\n");
                            }
                            else AddWarning("Invalid input\n");
                        }
                        else AddWarning("Invalid input\n");
                    }
                    else AddWarning("Invalid input\n");
                }
                else AddWarning("No nearest owned building\n");
            }
            else AddWarning("A building can only move ONCE in a turn!\n");
        }
        else AddWarning("Invalid input\n");
    }
    else AddWarning("Invalid input\n");
}

void ExitCommand() {
/*  Melakukan mekanisme Exit, yaitu keluar dari permainan */
    exit(0);
}

void AddAToAllBuilding (Player* P) {
/*  I.S. Buildings(P) terdefinisi
    F.S. Melakukan penambahan pasukan (A) terhadap Buildings(P) apabila Troops(B)<M(B) */
    ListElement* El;
    Building* B;
    ListTraversal(El, ListFirstElement(Buildings(*P)), El != Nil) {
        B = ListElementVal(El);
        if (Troops(*B) < M(*B)) Troops(*B) += A(*B);
    }
}

void SetToFalse (Player* P) {
/*  I.S. Player terdefinisi.
    F.S. Set All AfterAttack and AfterMove All Player's Building to False */
    ListElement* El;
    Building* B;

    ListTraversal(El, ListFirstElement(Buildings(*P)), El != Nil) {
        B = ListElementVal(El);
        AfterAttack(*B) = false;
        AfterMove(*B) = false;
    }
}
