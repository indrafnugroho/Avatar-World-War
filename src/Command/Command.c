/* Command.c
   Implementasi Command.h */

#include "bool/bool.h"
#include "Command.h"
#include "Art/Art.h"
#include <stdio.h>
#include <stdlib.h>

void InputCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState, Graph Connect) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    bool loop;
    loop = true;
    while(loop) {
        DisplayPrompt2("COMMAND");
        ScanWord(&input);
        if (WordEqualsString(input, "ATTACK")) {
            AttackCommand(PTurn,PEnemy,*Bldgs,Connect);
            //CheckSkill(PTurn,PEnemy,input);
            //CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
        }
        else if (WordEqualsString(input, "LEVEL_UP")) {
            LevelUpCommand(PTurn);
            //CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
        }
        else if (WordEqualsString(input, "SKILL")) {
            SkillCommand(PTurn,PEnemy);
            CheckSkill(PTurn,PEnemy,input);
            //CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
        }
        else if (WordEqualsString(input, "UNDO")) UndoCommand(PTurn,PEnemy,Bldgs,GState);
        else if (WordEqualsString(input, "END_TURN")) {
            EndTurnCommand(PTurn,PEnemy);
            //CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
            loop = false;
        }
        else if (WordEqualsString(input, "SAVE")) SaveCommand(PTurn,PEnemy);
        else if (WordEqualsString(input, "MOVE")) {
            MoveCommand(PTurn,*Bldgs,Connect);
            ///CaptureGameState(*PTurn,*PEnemy,*Bldgs,GState,input);
        }
        else if (WordEqualsString(input, "EXIT")) ExitCommand();
        else printf("Command yang Anda masukkan salah!\n");
    }
}

void AttackCommand(Player* PTurn, Player* PEnemy, ArrayDin Bldgs, Graph Connect) {
/*  Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */
    ListElement* El, *El2;
    Building* B, *BT, *CB, *BE;
    int i=1;

    DisplayPrompt("OWNED BUILDINGS");
    printf("\n\n");
    ListTraversal (El, ListFirstElement(Buildings(*PTurn)), El != Nil) {
        B = ListElementVal(El);

        //printf("%p ", El);
        printf("  %d. ", i);
        switch (Type(*B)) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        }
        printf("\n");
        i++;
    }

    DisplayPrompt2("BUILDING TO USE");
    int InpBSelf;
    if (ScanInt(&InpBSelf)) {
        i=1;
        ListTraversal(El, ListFirstElement(Buildings(*PTurn)), El != Nil && i != InpBSelf) i++;
        //printf("%p ", El);
        BT = ListElementVal(El);
        if (!AfterAttack(*BT)) {
            if (!ListIsEmpty(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT))))) {
                DisplayPrompt("NEAREST NEUTRAL AND ENEMY BUILDINGS");
                printf("\n\n");
                i=1;
                ListTraversal(El2, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT)))), El2 != Nil) {
                    //printf("%p ", El2);
                    CB = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El2)));

                    printf("  %d. ", i);
                    switch (Type(*CB)) {  
                    case 'C' :
                        printf("Castle (%d,%d) %d lv. %d\n", Koordinat(*CB).x, Koordinat(*CB).y, Troops(*CB), Level(*CB));
                        break;
                    case 'T' :
                        printf("Tower (%d,%d) %d lv. %d\n", Koordinat(*CB).x, Koordinat(*CB).y, Troops(*CB), Level(*CB));
                        break;
                    case 'F' :
                        printf("Fort (%d,%d) %d lv. %d\n", Koordinat(*CB).x, Koordinat(*CB).y, Troops(*CB), Level(*CB));
                        break;
                    case 'V' :
                        printf("Village (%d,%d) %d lv. %d\n", Koordinat(*CB).x, Koordinat(*CB).y, Troops(*CB), Level(*CB));
                        break;
                    }
                    i++;
                }
                printf("\n");
                DisplayPrompt2("BUILDING TO ATTACK");
                int InpBEnemy;
                if (ScanInt(&InpBEnemy)) {
                    if (InpBEnemy <= ListSize(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT))))) {
                        i=1;
                        ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BT)))), El != Nil && i != InpBEnemy) i++;
                    
                        BE = Elmt(Bldgs, GraphGetVertexIdx(Connect, ListElementVal(El)));
                        DisplayPrompt2("NUMBER OF TROOPS");
                        int InpTroopsNum;
                        if (ScanInt(&InpTroopsNum)) {
                            if (InpTroopsNum <= Troops(*BT)) {
                                //Cek apakah bangunan yang diserang milik lawan
                                int j=1;
                                ListTraversal(El, ListFirstElement(Buildings(*PEnemy)), ListElementVal(El) != BE && ListElementNext(El) != Nil) j++;                            
                            
                                //Bangunan yang diserang milik lawan
                                if (ListElementVal(El) == BE) {
                                    //Bangunan yang diserang tidak punya pertahanan
                                    //Dapat disebabkan juga oleh skill 
                                    if ((!Pb(*BE) && SHs(*PEnemy)==0) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                        if (CHs(*PTurn)==0) {
                                            if (InpTroopsNum < Troops(*BE)) {
                                                Troops(*BE) -= InpTroopsNum;
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                printf("Bangunan gagal direbut\n");
                                            }
                                            else {
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                ListDelVal(&Buildings(*PEnemy),BE);
                                                Troops(*BE) = InpTroopsNum - Troops(*BE);
                                                SetLvBuildingToLv1(BE);
                                                ListAddLast(&Buildings(*PTurn),BE);
                                                printf("Bangunan menjadi milikmu!\n");
                                            }
                                        }
                                        else {
                                            if (InpTroopsNum < (int) (Troops(*BE)/2)) {
                                                Troops(*BE) = (int) (Troops(*BE)/2) - InpTroopsNum;
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                printf("Bangunan gagal direbut\n");
                                            }
                                            else {
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                ListDelVal(&Buildings(*PEnemy),BE);
                                                Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/2);
                                                SetLvBuildingToLv1(BE);
                                                ListAddLast(&Buildings(*PTurn),BE);
                                                printf("Bangunan menjadi milikmu!\n");
                                            }
                                            CHs(*PTurn) = 0;
                                        }
                                        AUs(*PTurn) = false;
                                    }
                                    //Bangunan yang diserang punya pertahanan
                                    else {
                                        if (InpTroopsNum < (int) (Troops(*BE)/(0.75))) {
                                            Troops(*BE) = (int) (Troops(*BE)/(0.75)) - InpTroopsNum;
                                            Troops(*BT) -= InpTroopsNum;
                                            AfterAttack(*BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(*BT) -= InpTroopsNum;
                                            AfterAttack(*BT) = true;
                                            ListDelVal(&Buildings(*PEnemy),BE);
                                            Troops(*BE) = InpTroopsNum - (int) (Troops(*BE)/(0.75));
                                            SetLvBuildingToLv1(BE);
                                            ListAddLast(&Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                        if (SHs(*PEnemy)>0) SHs(*PEnemy)--;
                                    }
                                }
                                //Bangunan yang diserang tidak berkepemilikan
                                else {
                                    //Bangunan yang diserang tidak memiliki pertahanan
                                    if (!Pb(*BE) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                        if (CHs(*PTurn)==0) {
                                            if (InpTroopsNum < U(*BE)) {
                                                U(*BE) -= InpTroopsNum;
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                printf("Bangunan gagal direbut\n");
                                            }
                                            else {
                                                printf("test");
                                                Troops(*BE) = InpTroopsNum - U(*BE);
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                ListAddLast(&Buildings(*PTurn),BE);
                                                printf("Bangunan menjadi milikmu!\n");
                                            }
                                        }
                                        else {
                                            if (InpTroopsNum < (int) (U(*BE)/2)) {
                                                U(*BE) = (int) (U(*BE)/2) - InpTroopsNum;
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                printf("Bangunan gagal direbut\n");
                                            }
                                            else {
                                                Troops(*BE) = InpTroopsNum - (int) (U(*BE)/2);
                                                Troops(*BT) -= InpTroopsNum;
                                                AfterAttack(*BT) = true;
                                                ListAddLast(&Buildings(*PTurn),BE);
                                                printf("Bangunan menjadi milikmu!\n");
                                            }
                                            CHs(*PTurn) = 0;
                                        }
                                        AUs(*PTurn) = false;
                                    }
                                    //Bangunan yang diserang memiliki pertahanan
                                    else {
                                        if (InpTroopsNum < (int) (U(*BE)/(0.75))) {
                                            U(*BE) = (int) (U(*BE)/(0.75)) - InpTroopsNum;
                                            Troops(*BT) -= InpTroopsNum;
                                            AfterAttack(*BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(*BE) = InpTroopsNum - (int) (U(*BE)/(0.75));
                                            Troops(*BT) -= InpTroopsNum;
                                            AfterAttack(*BT) = true;
                                            ListAddLast(&Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                    }
                                }
                            }
                            else printf("Jumlah pasukan yang Anda masukkan melebihi jumlah pasukan di Bangunan\n");
                        }
                        else printf("Input yang Anda masukkan salah\n");
                    }
                    else printf("Input yang Anda masukkan salah\n");
                }
                else printf("Input yang Anda masukkan salah\n");
            }
            else printf("Tidak ada bangunan yang dapat diserang\n");
        }
        else printf("Bangunan yang Anda pilih sudah digunakan untuk menyerang sebelumnya\n");
    }
    else printf("Input yang Anda masukkan salah\n");
}

void LevelUpCommand(Player* PSelf) {
/*  Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
    yaitu mencetak daftar bangunan yang dimliki user,
    opsi untuk level up bangunan yang mana,
    dan hasil akhir level up. */
    ListElement* El;
    Building* B;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (El, ListFirstElement(Buildings(*PSelf)), El != Nil) {
        B = ListElementVal(El);

        printf("%d. ", i);
        switch(Type(*B)) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(*B).x, Koordinat(*B).y, Troops(*B), Level(*B));
            break;
        }
        i++;
    }

    printf("Bangunan yang akan di level up: ");
    int InpBNUm;
    if (ScanInt(&InpBNUm)) {
        if (InpBNUm <= ListSize(Buildings(*PSelf))) {
            i=1;
            ListTraversal(El, ListFirstElement(Buildings(*PSelf)), El != Nil && i != InpBNUm) i++;
            B = ListElementVal(El);

            if (Level(*B)<4) {
                if (Troops(*B) >= M(*B)/2) LevelAdd(B);
                else {
                    switch (Type(*B)) {
                    case 'C' :
                        printf("Jumlah pasukan Castle kurang untuk level up\n");
                        break;
                    case 'T' :
                        printf("Jumlah pasukan Tower kurang untuk level up\n");
                        break;
                    case 'F' :
                        printf("Jumlah pasukan Fort kurang untuk level up\n");
                        break;
                    case 'V' :
                        printf("Jumlah pasukan Village kurang untuk level up\n");
                        break;
                    }
                }
            }
            else printf("Level Bangunan Anda sudah maksimum\n");
        }
        else printf("Input yang Anda masukkan salah\n");
    }
    else printf("Input yang Anda masukkan salah\n");
}

void SkillCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan mekanisme Skill apabila user menginput command Skill,
    yang disesuaikan dengan efek Skill masing-masing */
    UseSkill(PTurn,PEnemy);
}

void UndoCommand(Player* PTurn, Player* PEnemy, ArrayDin* Bldgs, Stack* GState) {}
/*  Melakukan mekanisme Undo apabila user menginput command Undo.
    User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
    Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */
    if (SHs(*PTurn)>0) SHs(*PTurn)--;
    if (SHs(*PEnemy)>0) SHs(*PEnemy)--;
    SetToFalse(PTurn);
    AddAToAllBuilding(PEnemy);
}

void SaveCommand(Player* PTurn, Player* PEnemy) {}
/*  Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand(Player* PSelf, ArrayDin Bldgs, Graph Connect) {
/*  Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */
    ListElement* El;
    Building* BSelf, *BReceive;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (El, ListFirstElement(Buildings(*PSelf)), El != Nil) {
        BSelf = ListElementVal(El);

        printf("%d. ", i);
        if (Type(*BSelf) == 'C') {
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(*BSelf).x, Koordinat(*BSelf).y, Troops(*BSelf), Level(*BSelf));
        }
        else if (Type(*BSelf) == 'T') {
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(*BSelf).x, Koordinat(*BSelf).y, Troops(*BSelf), Level(*BSelf));
        }
        else if (Type(*BSelf) == 'F') {
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(*BSelf).x, Koordinat(*BSelf).y, Troops(*BSelf), Level(*BSelf));
        }
        else if (Type(*BSelf) == 'V') {
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(*BSelf).x, Koordinat(*BSelf).y, Troops(*BSelf), Level(*BSelf));
        }
        i++;
    }

    printf("Pilih bangunan: ");
    int InpB;
    if (ScanInt(&InpB)) {
        if (InpB <= ListSize(Buildings(*PSelf))) {
            int j=1;
            ListTraversal(El, ListFirstElement(Buildings(*PSelf)), El != Nil && j != InpB) j++;
            BSelf = ListElementVal(El);

            if (!AfterMove(*BSelf)) {
                printf("Daftar bangunan terdekat:\n");
                j=1;
                ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf)))), El!=Nil) {
                    BReceive = ListElementVal(El);

                    printf("%d. ", j);
                    switch(Type(*BReceive)) {
                    case 'C' :
                        printf("Castle (%d,%d) %d lv. %d\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y, Troops(*BReceive), Level(*BReceive));
                        break;
                    case 'T' :
                        printf("Tower (%d,%d) %d lv. %d\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y, Troops(*BReceive), Level(*BReceive));
                        break;
                    case'F' :
                        printf("Fort (%d,%d) %d lv. %d\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y, Troops(*BReceive), Level(*BReceive));
                        break;
                    case 'V':
                        printf("Village (%d,%d) %d lv. %d\n", Koordinat(*BReceive).x, Koordinat(*BReceive).y, Troops(*BReceive), Level(*BReceive));
                        break;
                    }
                    j++;
                }

                printf("Bangunan yang akan menerima: ");
                int InpBRcv;
                if (ScanInt(&InpBRcv)) {
                    if (InpBRcv <= ListSize(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf))))) {
                        j=1;
                        ListTraversal(El, ListFirstElement(GraphVertexAdj(GraphGetVertexFromIdx(Connect, Search1(Bldgs, BSelf)))), El != Nil && j != InpBRcv) j++;
                        BReceive = ListElementVal(El);

                        printf("Jumlah pasukan: ");
                        int InpTroops;
                        if (ScanInt(&InpTroops)) {
                            if (InpTroops <= Troops(*BReceive)) {
                                Troops(*BSelf) -= InpTroops;
                                Troops(*BReceive) += InpTroops;
                                printf("%d pasukan dari ", InpTroops);
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
                                printf("telah berpindah ke ");
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
                            else printf("Jumlah pasukan Bangunan Anda kurang\n");
                        }
                        else printf("Input yang Anda masukkan salah\n");
                    }
                    else printf("Input yang Anda masukkan salah\n");
                }
                else printf("Input yang Anda masukkan salah\n");
            }
            else printf("Bangunan yang Anda pilih sudah melakukan MOVE sebelumnya\n");
        }
        else printf("Input yang Anda masukkan salah\n");
    }
    else printf("Input yang Anda masukkan salah\n");
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
