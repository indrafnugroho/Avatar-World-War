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
    Player P1, P2;
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
