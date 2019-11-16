#include "Loader.h"
#include "Graph.h"
#include "ArrayDin.h"
#include <stdio.h>
#include <stdlib.h>
void ReadConfigFile(char* path)
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
    ArrayDin *ArrayOfBuildings = (ArrayDin*) malloc(sizeof(ArrayDin));
    Building *B;

    /* ALGORITMA */
    CreateEmpty(&CWord);
    if (ReadStart(path)) {
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
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            NbOfB = temp;
            printf("Num of buildings: %d\n", NbOfB);
        }
        MakeEmpty(ArrayOfBuildings,NbOfB);
        for(i = 0; i < NbOfB; i++) {
            B = (Building*) malloc(sizeof(Building));
            ReadWord(&CWord);
            Type(*B) = CC;
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointX(Koordinat(*B)) = temp;
            }
            ReadWord(&CWord);
            if(WordToInt(CWord,&temp)){
                PointY(Koordinat(*B)) = temp;
            }
            AddAsLastEl(ArrayOfBuildings,B);
            printf("Building #%d: %c(%d, %d)\t", i + 1,Type(*B), PointX(Koordinat(*B)), PointY(Koordinat(*B)));
        }
        for (i = 0; i < NbOfB; i++) {
            for (j = 0; j < NbOfB; j++) {
                ReadWord(&CWord);
                if (WordToInt(CWord, &temp)) {
                    if(temp == 1) {
                        printf("Connected: #%d -> #%d\t", i + 1, j + 1);
                    }
                }
            }
        }
    }
}
