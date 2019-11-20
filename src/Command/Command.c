/* Command.c
   Implementasi Command.h */

#include "Command/Command.h"
#include <stdio.h>

void InputCommand(Player* PTurn, Player* PEnemy, GameState* GS) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    printf("ENTER COMMAND: ");
    ScanWord(&input);

    if (WordEqualsString(input, "ATTACK")) AttackCommand(PTurn,PEnemy,GS);
    else if (WordEqualsString(input, "LEVEL_UP")) LevelUpCommand(PTurn,GS);
    else if (WordEqualsString(input, "SKILL")) SkillCommand(PTurn,PEnemy,GS);
    else if (WordEqualsString(input, "UNDO")) UndoCommand(PTurn,PEnemy,GS);
    else if (WordEqualsString(input, "END_TURN")) EndTurnCommand(PEnemy,GS);
    else if (WordEqualsString(input, "SAVE")) SaveCommand(PTurn,PEnemy,GS);
    else if (WordEqualsString(input, "MOVE")) MoveCommand(PTurn,GS);
    else if (WordEqualsString(input, "EXIT")) ExitCommand(PTurn,PEnemy,GS);
    else printf("Command yang Anda masukkan salah!\n");
}

void AttackCommand(Player* PTurn, Player* PEnemy, GameState* GS) {
/*  Melakukan mekanisme attack apabila user menginput command Attack,
    yaitu mencetak daftar bangunan yang dimiliki user,
    opsi untuk menyerang dengan bangunan apa,
    daftar bangunan yang dapat diserang (yang saling terhubung),
    opsi bangunan apa yang akan diserang,
    jumlah pasukan yang digunakan untuk menyerang,
    dan hasil akhir penyerangan. */
    ListElement* P, PT, CB, PE;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (P, ListFirstElement(Buildings(*PTurn)), P != Nil) {
        printf("%d. ", i);
        switch (Type(P)) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        }
        i++;
    }

    printf("Bangunan yang digunakan untuk menyerang: ");
    int InpBSelf;
    if (ScanInt(&InpBSelf)) {
        i=1;
        ListTraversal(PT, ListFirstElement(Buildings(*PTurn)), PT != Nil && i != InpBSelf) i++;

        if (!AfterAttack(PT)) {
            if (!ListIsEmpty(Connect(PT))) {
                printf("Daftar bangunan yang dapat diserang:\n");
                i=1;
                ListTraversal(CB, ListFirstElement(Connect(PT)), PE != Nil) {
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
                    ListTraversal(PE, ListFirstElement(Connect(PT)), PE != Nil && i != InpBEnemy) i++;

                    printf("Jumlah pasukan: ");
                    int InpTroopsNum;
                    if (ScanInt(&InpTroopsNum)) {
                        if (InpTroopsNum <= Troops(PT)) {
                            //Cek apakah bangunan yang diserang milik lawan
                            int j=1; ListElement* CheckB;
                            ListTraversal(CheckB, ListFirstElement(Buildings(*PEnemy)), CheckB != PE && CheckB != Nil) j++;                            
                            
                            //Bangunan yang diserang milik lawan
                            if (CheckB == PE) {
                                //Bangunan yang diserang tidak punya pertahanan
                                if (!Pb(PE)) {
                                    if (InpTroopsNum < Troops(PE)) {
                                        Troops(PE) -= InpTroopsNum;
                                        Troops(PT) -= InpTroopsNum;
                                        AfterAttack(PT) = true;
                                        printf("Bangunan gagal direbut\n");
                                    }
                                    else {
                                        ListElDel(Buildings(*PEnemy),PE);
                                        Troops(PT) -= InpTroopsNum;
                                        AfterAttack(PT) = true;
                                        Troops(PE) -= InpTroopsNum;
                                        if (Troops(PE) < 0) Troops(PE) = Troops(PE)*(-1);
                                        SetLvBuildingToLv1(PE);
                                        ListElAddLast(Buildings(*PTurn),PE);
                                        printf("Bangunan menjadi milikmu!\n");
                                    }
                                }
                                //Bangunan yang diserang punya pertahanan
                                else {

                                }
                            }
                            //Bangunan yang diserang tidak berkepemilikan
                            else {
                                //Bangunan yang diserang tidak memiliki pertahanan
                                if (!Pb(PE)) {
                                    if (InpTroopsNum < U(PE)) {
                                        Troops(PT) -= InpTroopsNum;
                                        AfterAttack(PT) = true;
                                        printf("Bangunan gagal direbut\n");
                                    }
                                    else {
                                        Troops(PE) = U(PE) - InpTroopsNum;
                                        if (Troops(PE) < 0) Troops(PE) = Troops(PE)*(-1);
                                        Troops(PT) -= InpTroopsNum;
                                        AfterAttack(PT) = true;
                                        ListElAddLast(Buildings(*PTurn),PE);
                                        printf("Bangunan menjadi milikmu!\n");
                                    }
                                }
                                //Bangunan yang diserang memiliki pertahanan
                                else {

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

    /*
    Processing Attack Command
    */
}

void LevelUpCommand(Player* PSelf, GameState* GS) {
/*  Melakukan mekanisme Level_Up apabila user menginput command Level_UP,
    yaitu mencetak daftar bangunan yang dimliki user,
    opsi untuk level up bangunan yang mana,
    dan hasil akhir level up. */
    ListElement* P;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (P, ListFirstElement(Buildings(*PSelf)), P != Nil) {
        printf("%d. ", i);
        switch(Type(P)) {
        case 'C' :
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'T' :
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'F' :
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        case 'V' :
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
            break;
        }
        i++;
    }

    printf("Bangunan yang akan di level up: ");
    int InpBNUm;
    if (ScanInt(&InpBNUm)) {
        if (InpBNUm <= ListSize(Buildings(*PSelf))) {
            i=1;
            ListTraversal(P, ListFirstElement(Buildings(*PSelf)), P != Nil && i != InpBNUm) i++;

            if (Level(P)<4) {
                if (Troops(P) >= M(P)/2) LevelAdd(&P);
                else {
                    switch (Type(P)) {
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

void SkillCommand(Player* PTurn, Player* PEnemy, GameState* GS) {}
/*  Melakukan mekanisme Skill apabila user menginput command Skill,
    yang disesuaikan dengan efek Skill masing-masing */

void UndoCommand(Player* PTurn, Player* PEnemy, GameState* GS) {}
/*  Melakukan mekanisme Undo apabila user menginput command Undo.
    User hanya dapat melakukan UNDO hingga command sesudah END_TURN / SKILL. 
    Artinya, setelah command END_TURN / SKILL, pemain tidak dapat melakukan UNDO lagi */

void EndTurnCommand(Player* PEnemy, GameState* GS) {
/*  Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */
    AddAToAllBuilding(PEnemy);
}

void SaveCommand(Player* PTurn, Player* PEnemy, GameState* GS) {}
/*  Melakukan mekanisme Save_File, yaitu menyimpan state permainan yang sedang berlangsung*/

void MoveCommand(Player* PSelf, GameState* GS) {
/*  Melakukan mekanisme Move, yaitu memindahkan pasukan dari suatu bangunan ke bangunan lain milik
    pemain yang terhubung dengan bangunan tersebut. MOVE hanya dapat dilakukan
    sekali untuk tiap bangunan pada tiap gilirannya. */
    ListElement* P, B;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (P, ListFirstElement(Buildings(*PSelf)), P != Nil) {
        printf("%d. ", i);
        if (Type(P) == 'C') {
            printf("Castle (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
        }
        else if (Type(P) == 'T') {
            printf("Tower (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
        }
        else if (Type(P) == 'F') {
            printf("Fort (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
        }
        else if (Type(P) == 'V') {
            printf("Village (%d,%d) %d lv. %d\n", Koordinat(P).X, Koordinat(P).Y, Troops(P), Level(P));
        }
        i++;
    }

    printf("Pilih bangunan: ");
    int InpB;
    if (ScanInt(&InpB)) {
        if (InpB <= ListSize(Buildings(*PSelf))) {
            int j=1;
            ListTraversal(P, ListFirstElement(Buildings(*PSelf)), P != Nil && j != InpB) j++;

            if (!AfterMove(P)) {
                printf("Daftar bangunan terdekat:\n");
                j=1;
                ListTraversal(B, ListFirstElement(Connect(P)), B!=Nil) {
                    printf("%d. ", j);
                    switch(Type(B)) {
                    case 'C' :
                        printf("Castle (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
                        break;
                    case 'T' :
                        printf("Tower (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
                        break;
                    case'F' :
                        printf("Fort (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
                        break;
                    case 'V'
                        printf("Village (%d,%d) %d lv. %d\n", Koordinat(B).X, Koordinat(B).Y, Troops(B), Level(B));
                        break;
                    }
                    j++;
                }

                printf("Bangunan yang akan menerima: ");
                int InpBRcv;
                if (ScanInt(&InpBRcv)) {
                    if (InpBRcv <= ListSize(Connect(P))) {
                        j=1;
                        ListTraversal(B, ListFirstElement(Connect(P)), B != Nil && j != InpBRcv) j++;

                        printf("Jumlah pasukan: ");
                        int InpTroops;
                        if (ScanInt(&InpTroops)) {
                            if (InpTroops <= Troops(B)) {
                                Troops(P) -= InpTroops;
                                Troops(B) += InpTroops;
                                printf("%d pasukan dari ", InpTroops);
                                switch (Type(P)) {
                                case 'C' :
                                    printf("Castle (%d,%d) ", Koordinat(P).X, Koordinat(P).Y);
                                    break;
                                case 'T' :
                                    printf("Tower (%d,%d) ", Koordinat(P).X, Koordinat(P).Y);
                                    break;
                                case 'F' :
                                    printf("Fort (%d,%d) ", Koordinat(P).X, Koordinat(P).Y);
                                    break;
                                case 'V' :
                                    printf("Village (%d,%d) ", Koordinat(P).X, Koordinat(P).Y);
                                    break;
                                }
                                printf("telah berpindah ke ");
                                switch (Type(B)) {
                                case 'C' :
                                    printf("Castle (%d,%d)\n", Koordinat(B).X, Koordinat(B).Y);
                                    break;
                                case 'T' :
                                    printf("Tower (%d,%d)\n", Koordinat(B).X, Koordinat(B).Y);
                                    break;
                                case 'F' :
                                    printf("Fort (%d,%d)\n", Koordinat(B).X, Koordinat(B).Y);
                                    break;
                                case 'V' :
                                    printf("Village (%d,%d)\n", Koordinat(B).X, Koordinat(B).Y);
                                    break;
                                }
                                AfterMove(P) = true;
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

void ExitCommand(Player* PTurn, Player* PEnemy, GameState* GS) {}
/*  Melakukan mekanisme Exit, yaitu keluar dari permainan */

void AddAToAllBuilding (Player* P) {
/* Melakukan penambahan pasukan (A) terhadap bangunan player */
    ListElement* El;

    ListTraversal(El, ListFirstElement(Buildings(*P)), El != Nil) {
        if (Troops(Buildings(*P)) < M(Buildings(*P))) Troops(Buildings(*P)) += A(Buildings(*P));
    }
}
