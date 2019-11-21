#include "Loader/Loader.h"
#include <stdio.h>
#include <stdlib.h>

void ReadConfigFile(char* path, ArrayDin* buildings, Graph* connect, GameMap* map)
/*
I.S.
    Terdapat file eksternal berisi konfigurasi awal permainan.
F.S.
    File konfigurasi dibaca dan diolah sehingga siap dibuat GameMap.
*/
{
    /* KAMUS LOKAL */
    Word CWord,TEMPWORD;
    int i,j,N,M,NbOfB;
    int temp;
    char to;
    Building *B;
    List* Adj;
    /* ALGORITMA */
    CreateEmpty(&CWord);
    if (ReadStart(path)) {
        /* Membaca Ukuran Map */
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            N = temp;
            printf("N: %d\n", N);
        }
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            M = temp;
            printf("M: %d\n", M);
        }
        CreateEmptyMap(map, N, M);
        /* Membaca banyak building */
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            NbOfB = temp;
            printf("Num of buildings: %d\n", NbOfB);
        }
        /* Membaca Building */
        MakeEmpty(buildings ,NbOfB);
        GraphCreate(connect); 
        for(i = 0; i < NbOfB; i++) {
            B = (Building*) malloc(sizeof(Building));
            ReadWord(&CWord);
            Type(*B) = CWord.Tab[0];
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointX(Koordinat(*B)) = temp;
            }
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointY(Koordinat(*B)) = temp;
            }
            InitializationBuilding(B);
            AddAsLastEl(buildings, B);
            Adj = (List*) malloc(sizeof(List));
            ListCreate(Adj);
            GraphAddVertex(connect, Adj);
            printf("Building #%d: %c(%d, %d)\n", i + 1,Type(*B), PointX(Koordinat(*B)), PointY(Koordinat(*B)));
        }
        /* Membaca keterhubungan building */
        for (i = 0; i < NbOfB; i++) {
            for (j = 0; j < NbOfB; j++) {
                ReadWord(&CWord);
                if (WordToInt(CWord, &temp)) {
                    if(temp == 1) {
                        GraphAddEdgeIdx(connect, i, j);
                        printf("Connected: #%d -> #%d\t", i + 1, j + 1);
                    }
                }
            }
            printf("\n");
        }
    }
    SetMap(map, *buildings);
    //PrintMap(*map, P1, P2);
}

void SaveGameFile(char* path, Player P1, Player P2, ArrayDin buildings, Graph connect, GameMap map, Player* Pturn) {
    FILE* sav;
    int i, j;
    Building* b;
    ListElement* p;

    sav = fopen(path, "w");
    
    fprintf(sav, "%d %d\n%d\n", RowEff(map), ColEff(map), Neff(buildings));
    for (i = GetFirstIdx(buildings); i < Neff(buildings); i++) {
        b = Elmt(buildings, i);
        fprintf(sav, "%c %d %d %d %d %d %d %d %d %d %d\n",
            Type(*b), Koordinat(*b).x, Koordinat(*b).y, Troops(*b), Level(*b), 
            A(*b), M(*b), Pb(*b), U(*b), AfterAttack(*b), AfterMove(*b)
        );

    }
    for (i = GetFirstIdx(buildings); i < Neff(buildings); i++) { 
        for (j = GetFirstIdx(buildings); j < Neff(buildings); j++) {
            fprintf(sav, "%d ", GraphIsAdjacentIdx(connect, i, j));
        }
        fprintf(sav, "\n");
    }
    fprintf(sav, "%d %d %d %d %d %d\n", ListSize(Buildings(P1)), ListSize(Skills(P1)), CHs(P1), SHs(P1), AUs(P1), ETs(P1));
    ListTraversal(p, ListFirstElement(Buildings(P1)), p != Nil) {
        fprintf(sav, "%d ", Search1(buildings, ListElementVal(p)));
    }
    fprintf(sav, "\n");
    ListTraversal(p, ListFirstElement(Skills(P1)), p != Nil) {
        fprintf(sav, "%d ", ListElementVal(p));
    } 
    fprintf(sav, "\n");
    fprintf(sav, "%d %d %d %d %d %d\n", ListSize(Buildings(P2)), ListSize(Skills(P2)), CHs(P2), SHs(P2), AUs(P2), ETs(P2));
    ListTraversal(p, ListFirstElement(Buildings(P2)), p != Nil) {
        fprintf(sav, "%d ", Search1(buildings, ListElementVal(p)));
    }
    fprintf(sav, "\n");
    ListTraversal(p, ListFirstElement(Skills(P2)), p != Nil) {
        fprintf(sav, "%d ", ListElementVal(p));
    } 
    fprintf(sav, "\n%d\n", Pturn == &P1 ? 1 : 2);

    fclose(sav);
}

void LoadGameFile(char* path, Player* P1, Player* P2, ArrayDin* buildings, Graph* connect, GameMap* map, Player** Pturn) {
    /* Kamus Lokal */
    Word CWord,TEMPWORD;
    int i,j,N,M,NbOfB, NbOfPS, NbOfPB;
    int temp;
    char to;
    Building *B;
    List* Adj;
    /* ALGORITMA */
    CreateEmpty(&CWord);
    if (ReadStart(path)) {
        /* Membaca Ukuran Map */
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            N = temp;
            printf("N: %d\n", N);
        }
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            M = temp;
            printf("M: %d\n", M);
        }
        CreateEmptyMap(map, N, M);
        /* Membaca banyak building */
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            NbOfB = temp;
            printf("Num of buildings: %d\n", NbOfB);
        }
        /* Membaca Building */
        MakeEmpty(buildings ,NbOfB);
        GraphCreate(connect); 
        for(i = 0; i < NbOfB; i++) {
            B = (Building*) malloc(sizeof(Building));
            ReadWord(&CWord);
            Type(*B) = CWord.Tab[0];
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointX(Koordinat(*B)) = temp;
            }
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointY(Koordinat(*B)) = temp;
            }
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                Troops(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                Level(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                A(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                M(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                Pb(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                U(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                AfterAttack(*B) = temp;
            }
             ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                AfterMove(*B) = temp;
            } 
            //InitializationBuilding(B);
            AddAsLastEl(buildings, B);
            Adj = (List*) malloc(sizeof(List));
            ListCreate(Adj);
            GraphAddVertex(connect, Adj);
            printf("Building #%d: %c(%d, %d)\n", i + 1,Type(*B), PointX(Koordinat(*B)), PointY(Koordinat(*B)));
        }
        /* Membaca keterhubungan building */
        for (i = 0; i < NbOfB; i++) {
            for (j = 0; j < NbOfB; j++) {
                ReadWord(&CWord);
                if (WordToInt(CWord, &temp)) {
                    if(temp == 1) {
                        GraphAddEdgeIdx(connect, i, j);
                        printf("Connected: #%d -> #%d\t", i + 1, j + 1);
                    }
                }
            }
            printf("\n");
        }
        /* Player 1 */
        CreateNewPlayer(P1);
        QueueDel(&Skills(*P1), &temp);
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            NbOfPB = temp;
        } 
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            NbOfPS = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            CHs(*P1) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            SHs(*P1) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            AUs(*P1) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            ETs(*P1) = temp;
        }
        for (i = 0; i < NbOfPB; i++) {
            ReadWord(&CWord);
            if (WordToInt(CWord, &temp)) {
                ListAddLast(&Buildings(*P1), Elmt(*buildings, temp));
            }
        }
        for (i = 0; i < NbOfPS; i++) {
            ReadWord(&CWord);
            if (WordToInt(CWord, &temp)) {
                AddSkill(P1, temp);
            }
        }
        /* Player 2 */
        CreateNewPlayer(P2);
        QueueDel(&Skills(*P2), &temp);
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            NbOfPB = temp;
        } 
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            NbOfPS = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            CHs(*P2) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            SHs(*P2) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            AUs(*P2) = temp;
        }
        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            ETs(*P2) = temp;
        }
        for (i = 0; i < NbOfPB; i++) {
            ReadWord(&CWord);
            if (WordToInt(CWord, &temp)) {
                ListAddLast(&Buildings(*P2), Elmt(*buildings, temp));
            }
        }
        for (i = 0; i < NbOfPS; i++) {
            ReadWord(&CWord);
            if (WordToInt(CWord, &temp)) {
                AddSkill(P2, temp);
            }
        }

        ReadWord(&CWord);
        if (WordToInt(CWord, &temp)) {
            *Pturn = temp == 1 ? P1 : P2;
        }

    }
    SetMap(map, *buildings);

}
