/* Command.c
   Implementasi Command.h */

#include "Command.h"
#include <stdio.h>

void InputCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    printf("ENTER COMMAND: ");
    ScanWord(&input);

    if (WordEqualsString(input, "ATTACK")) AttackCommand(PTurn,PEnemy);
    else if (WordEqualsString(input, "LEVEL_UP")) LevelUpCommand(PTurn);
    else if (WordEqualsString(input, "SKILL")) SkillCommand(PTurn,PEnemy);
    else if (WordEqualsString(input, "UNDO")) UndoCommand(PTurn,PEnemy);
    else if (WordEqualsString(input, "END_TURN")) EndTurnCommand(PTurn,PEnemy);
    else if (WordEqualsString(input, "SAVE")) SaveCommand(PTurn,PEnemy);
    else if (WordEqualsString(input, "MOVE")) MoveCommand(PTurn);
    else if (WordEqualsString(input, "EXIT")) ExitCommand();
    else printf("Command yang Anda masukkan salah!\n");
}

void AttackCommand(Player* PTurn, Player* PEnemy) {
/*  Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */
    ListElement* B, BT, CB, BE;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (B, ListFirstElement(Buildings(*PTurn)), B != Nil) {
        printf("%d. ", i);
        switch (Type(*(Building*)ListElementVal(B))) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        }
        i++;
    }

    printf("Bangunan yang digunakan untuk menyerang: ");
    int InpBSelf;
    if (ScanInt(&InpBSelf)) {
        i=1;
        ListTraversal(BT, ListFirstElement(Buildings(*PTurn)), BT != Nil && i != InpBSelf) i++;

        if (!AfterAttack(BT)) {
            if (!ListIsEmpty(Connect(BT))) {
                printf("Daftar bangunan yang dapat diserang:\n");
                i=1;
                ListTraversal(CB, ListFirstElement(Connect(BT)), BE != Nil) {
                    printf("%d. ", i);
                    switch (Type(CB)) {  
                    case 'C' :
                        printf("Castle (%d,%d) %d lv. %d\n", Koordinat(CB).X, Koordinat(CB).Y, Troops(CB), Level(CB));
                        break;
                    case 'T' :
                        printf("Tower (%d,%d) %d lv. %d\n", Koordinat(CB).X, Koordinat(CB).Y, Troops(CB), Level(CB));
                        break;
                    case 'F' :
                        printf("Fort (%d,%d) %d lv. %d\n", Koordinat(CB).X, Koordinat(CB).Y, Troops(CB), Level(CB));
                        break;
                    case 'V' :
                        printf("Village (%d,%d) %d lv. %d\n", Koordinat(CB).X, Koordinat(CB).Y, Troops(CB), Level(CB));
                        break;
                    }
                    i++;
                }
                printf("Bangunan yang diserang: ");
                int InpBEnemy;
                if (ScanInt(&InpBEnemy)) {
                    i=1;
                    ListTraversal(BE, ListFirstElement(Connect(BT)), BE != Nil && i != InpBEnemy) i++;

                    printf("Jumlah pasukan: ");
                    int InpTroopsNum;
                    if (ScanInt(&InpTroopsNum)) {
                        if (InpTroopsNum <= Troops(BT)) {
                            //Cek apakah bangunan yang diserang milik lawan
                            int j=1; ListElement* CheckB;
                            ListTraversal(CheckB, ListFirstElement(Buildings(*PEnemy)), CheckB != BE && CheckB != Nil) j++;                            
                            
                            //Bangunan yang diserang milik lawan
                            if (CheckB == BE) {
                                //Bangunan yang diserang tidak punya pertahanan
                                //Dapat disebabkan juga oleh skill 
                                if ((!Pb(BE) && SHs(*PEnemy)==0) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                    if (CHs(*PTurn)==0) {
                                        if (InpTroopsNum < Troops(BE)) {
                                            Troops(BE) -= InpTroopsNum;
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            ListElDel(Buildings(*PEnemy),BE);
                                            Troops(BE) = InpTroopsNum - Troops(BE);
                                            SetLvBuildingToLv1(BE);
                                            ListElAddLast(Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                    }
                                    else {
                                        if (InpTroopsNum < (int) (Troops(BE)/2)) {
                                            Troops(BE) = (int) (Troops(BE)/2) - InpTroopsNum;
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            ListElDel(Buildings(*PEnemy),BE);
                                            Troops(BE) = InpTroopsNum - (int) (Troops(BE)/2);
                                            SetLvBuildingToLv1(BE);
                                            ListElAddLast(Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                        CHs(*PTurn) = 0;
                                    }
                                    AUs(*PTurn) = false;
                                }
                                //Bangunan yang diserang punya pertahanan
                                else {
                                    if (InpTroopsNum < (int) (Troops(BE)/(0.75))) {
                                        Troops(BE) = (int) (Troops(BE)/(0.75)) - InpTroopsNum;
                                        Troops(BT) -= InpTroopsNum;
                                        AfterAttack(BT) = true;
                                        printf("Bangunan gagal direbut\n");
                                    }
                                    else {
                                        Troops(BT) -= InpTroopsNum;
                                        AfterAttack(BT) = true;
                                        ListElDel(Buildings(*PEnemy),BE);
                                        Troops(BE) = InpTroopsNum - (int) (Troops(BE)/(0.75));
                                        SetLvBuildingToLv1(BE);
                                        ListElAddLast(Buildings(*PTurn),BE);
                                        printf("Bangunan menjadi milikmu!\n");
                                    }
                                    if (SHs(*PEnemy)>0) SHs(*PEnemy)--;
                                }
                            }
                            //Bangunan yang diserang tidak berkepemilikan
                            else {
                                //Bangunan yang diserang tidak memiliki pertahanan
                                if (!Pb(BE) || AUs(*PTurn) || CHs(*PTurn)==1) {
                                    if (CHs(*PTurn)==0) {
                                        if (InpTroopsNum < U(BE)) {
                                            U(BE) -= InpTroopsNum;
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(BE) = InpTroopsNum - U(BE);
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            ListElAddLast(Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                    }
                                    else {
                                        if (InpTroopsNum < (int) (U(BE)/2)) {
                                            U(BE) = (int) (U(BE)/2) - InpTroopsNum;
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            printf("Bangunan gagal direbut\n");
                                        }
                                        else {
                                            Troops(BE) = InpTroopsNum - (int) (U(BE)/2);
                                            Troops(BT) -= InpTroopsNum;
                                            AfterAttack(BT) = true;
                                            ListElAddLast(Buildings(*PTurn),BE);
                                            printf("Bangunan menjadi milikmu!\n");
                                        }
                                        CHS(*PTurn) = 0;
                                    }
                                    AUs(*PTurn) = false;
                                }
                                //Bangunan yang diserang memiliki pertahanan
                                else {
                                    if (InpTroopsNum < (int) (U(BE)/(0.75))) {
                                        U(BE) = (int) (U(BE)/(0.75)) - InpTroopsNum;
                                        Troops(BT) -= InpTroopsNum;
                                        AfterAttack(BT) = true;
                                        printf("Bangunan gagal direbut\n");
                                    }
                                    else {
                                        Troops(BE) = InpTroopsNum - (int) (U(BE)/(0.75));
                                        Troops(BT) -= InpTroopsNum;
                                        AfterAttack(BT) = true;
                                        ListElAddLast(Buildings(*PTurn),BE);
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
    ListElement* B;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (B, ListFirstElement(Buildings(*PSelf)), B != Nil) {
        printf("%d. ", i);
        switch(Type(B)) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
            break;
        }
        i++;
    }

    printf("Bangunan yang akan di level up: ");
    int InpBNUm;
    if (ScanInt(&InpBNUm)) {
        if (InpBNUm <= ListSize(Buildings(*PSelf))) {
            i=1;
            ListTraversal(B, ListFirstElement(Buildings(*PSelf)), B != Nil && i != InpBNUm) i++;

            if (Level(B)<4) {
                if (Troops(B) >= M(B)/2) LevelAdd(&B);
                else {
                    switch (Type(B)) {
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

void UndoCommand(Player* PTurn, Player* PEnemy) {}
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

void MoveCommand(Player* PSelf) {
/*  Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */
    ListElement* BSelf, BReceive;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (BSelf, ListFirstElement(Buildings(*PSelf)), BSelf != Nil) {
        printf("%d. ", i);
        if (Type(BSelf) == 'C') {
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(BSelf).X, Koordinat(BSelf).Y, Troops(BSelf), Level(BSelf));
        }
        else if (Type(BSelf) == 'T') {
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(BSelf).X, Koordinat(BSelf).Y, Troops(BSelf), Level(BSelf));
        }
        else if (Type(BSelf) == 'F') {
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(BSelf).X, Koordinat(BSelf).Y, Troops(BSelf), Level(BSelf));
        }
        else if (Type(BSelf) == 'V') {
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(BSelf).X, Koordinat(BSelf).Y, Troops(BSelf), Level(BSelf));
        }
        i++;
    }

    printf("Pilih bangunan: ");
    int InpB;
    if (ScanInt(&InpB)) {
        if (InpB <= ListSize(Buildings(*PSelf))) {
            int j=1;
            ListTraversal(BSelf, ListFirstElement(Buildings(*PSelf)), BSelf != Nil && j != InpB) j++;

            if (!AfterMove(BSelf)) {
                printf("Daftar bangunan terdekat:\n");
                j=1;
                ListTraversal(BReceive, ListFirstElement(Connect(BSelf)), BReceive!=Nil) {
                    printf("%d. ", j);
                    switch(Type(BReceive)) {
                    case 'C' :
                        printf("Castle (%d,%d) %d lv. %d\n", Koordinat(BReceive).X, Koordinat(BReceive).Y, Troops(BReceive), Level(BReceive));
                        break;
                    case 'T' :
                        printf("Tower (%d,%d) %d lv. %d\n", Koordinat(BReceive).X, Koordinat(BReceive).Y, Troops(BReceive), Level(BReceive));
                        break;
                    case'F' :
                        printf("Fort (%d,%d) %d lv. %d\n", Koordinat(BReceive).X, Koordinat(BReceive).Y, Troops(BReceive), Level(BReceive));
                        break;
                    case 'V'
                        printf("Village (%d,%d) %d lv. %d\n", Koordinat(BReceive).X, Koordinat(BReceive).Y, Troops(BReceive), Level(BReceive));
                        break;
                    }
                    j++;
                }

                printf("Bangunan yang akan menerima: ");
                int InpBRcv;
                if (ScanInt(&InpBRcv)) {
                    if (InpBRcv <= ListSize(Connect(BSelf))) {
                        j=1;
                        ListTraversal(BReceive, ListFirstElement(Connect(BSelf)), BReceive != Nil && j != InpBRcv) j++;

                        printf("Jumlah pasukan: ");
                        int InpTroops;
                        if (ScanInt(&InpTroops)) {
                            if (InpTroops <= Troops(BReceive)) {
                                Troops(BSelf) -= InpTroops;
                                Troops(BReceive) += InpTroops;
                                printf("%d pasukan dari ", InpTroops);
                                switch (Type(BSelf)) {
                                case 'C' :
                                    printf("Castle (%d,%d) ", Koordinat(BSelf).X, Koordinat(BSelf).Y);
                                    break;
                                case 'T' :
                                    printf("Tower (%d,%d) ", Koordinat(BSelf).X, Koordinat(BSelf).Y);
                                    break;
                                case 'F' :
                                    printf("Fort (%d,%d) ", Koordinat(BSelf).X, Koordinat(BSelf).Y);
                                    break;
                                case 'V' :
                                    printf("Village (%d,%d) ", Koordinat(BSelf).X, Koordinat(BSelf).Y);
                                    break;
                                }
                                printf("telah berpindah ke ");
                                switch (Type(BReceive)) {
                                case 'C' :
                                    printf("Castle (%d,%d)\n", Koordinat(BReceive).X, Koordinat(BReceive).Y);
                                    break;
                                case 'T' :
                                    printf("Tower (%d,%d)\n", Koordinat(BReceive).X, Koordinat(BReceive).Y);
                                    break;
                                case 'F' :
                                    printf("Fort (%d,%d)\n", Koordinat(BReceive).X, Koordinat(BReceive).Y);
                                    break;
                                case 'V' :
                                    printf("Village (%d,%d)\n", Koordinat(BReceive).X, Koordinat(BReceive).Y);
                                    break;
                                }
                                AfterMove(BSelf) = true;
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
    exit();
}

void AddAToAllBuilding (Player* P) {
/*  I.S. Buildings(P) terdefinisi
    F.S. Melakukan penambahan pasukan (A) terhadap Buildings(P) apabila Troops(B)<M(B) */
    ListElement* El;

    ListTraversal(El, ListFirstElement(Buildings(*P)), El != Nil) {
        if (Troops(Buildings(*P)) < M(Buildings(*P))) Troops(Buildings(*P)) += A(Buildings(*P));
    }
}

void SetToFalse (Player* P) {
/*  I.S. Player terdefinisi.
    F.S. Set All AfterAttack and AfterMove All Player's Building to False */
    ListElement* B;

    ListTraversal(B, ListFirstElement(Buildings(*P)), B != Nil) {
        AfterAttack(B) = false;
        AfterMove(B) = false;
    }
}
