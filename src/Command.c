/* Command.c
   Implementasi Command.h */

#include "Command.h"
#include <stdio.h>

void InputCommand(Player* P1, Player* P2, GameState* GS) {
/*  Melakukan input Command menggunakan Word Processor */

    Word input;   
    printf("ENTER COMMAND: ");
    ScanWord(&input);

    if (WordEqualsString(input, "ATTACK")) AttackCommand(P1,P2,GS);
    else if (WordEqualsString(input, "LEVEL_UP")) LevelUpCommand(P1,P2,GS);
    else if (WordEqualsString(input, "SKILL")) LevelUpCommand(P1,P2,GS);
    else if (WordEqualsString(input, "UNDO")) UndoCommand(P1,P2,GS);
    else if (WordEqualsString(input, "END_TURN")) EndTurnCommand(P1,P2,GS);
    else if (WordEqualsString(input, "SAVE")) SaveCommand(P1,P2,GS);
    else if (WordEqualsString(input, "MOVE")) MoveCommand(P1,P2,GS);
    else if (WordEqualsString(input, "EXIT")) ExitCommand(P1,P2,GS);
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
    ListElement* P, PT, PE;
    int i=1;

    printf("Daftar bangunan:\n");
    ListTraversal (P, ListFirstElement(Buildings(*PTurn)), P != Nil) {
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

    printf("Bangunan yang digunakan untuk menyerang: ");
    int InpBSelf;
    if (ScanInt(&InpBSelf)) {
        i=1;
        ListTraversal(PT, ListFirstElement(Buildings(*PTurn)), PT != Nil && i != InpBSelf) i++;

        printf("Daftar bangunan yang dapat diserang:\n");
        /*
        List of Connected Foe's Building
        */

        printf("Bangunan yang diserang: ");
        int InpBEnemy;
        if (ScanInt(&InpBEnemy)) {
            i=1;
            ListTraversal(PE, ListFirstElement(Buildings(*PEnemy)), PE != Nil && i != InpBEnemy) i++;

            printf("Jumlah pasukan: ");
            int InpTroopsNum;
            if (ScanInt(&InpTroopsNum)) {

            }
        }

        //Kondisi Else
        //printf("Tidak ada bangunan yang dapat diserang\n");
    }

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

void EndTurnCommand(Player* PTurn, Player* PEnemy, GameState* GS) {}
/*  Melakukan mekanisme End_Turn apabila user menginput command End_Turn. */

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