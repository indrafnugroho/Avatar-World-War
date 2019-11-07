#include "Loader.h"

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
    int i,N,M,NbOfB;
    int temp;
    char to;
    ArrayDin *ArrayOfBuildings;
    Building *B;

    /* ALGORITMA */
    CreateEmpty(&CWord);
    if (ReadStart(path)) {
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            N = temp;
        }
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            M = temp;
        }
        ReadWord(&CWord);
        if(WordToInt(CWord,&temp)){
            NbOfB = temp;
        }
        MakeEmpty(ArrayOfBuildings,B);
        for(i = 1; i <= MaxElement(*ArrayOfBuildings); i++) {
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
        }
    }
}