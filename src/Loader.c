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
    int i,N,M,B;
    int temp;
    char to;

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
            B = temp;
        }
        // Buat baca konfigurasi Building butuh ADT arraydin
    }
}