/*
GameMap.c
IMPLEMENTASI ADT GAMEMAP <GameMap>
*/

#include "GameMap.h"

void PrintMap(Matrix M, ArrayDin Arr) {
// Mencetak peta permainan ke layar
// dengan spesifikasi border * di sisi peta
// dan Tipe Bangunan dengan tanda kepemilikan
// warna pemain
    //Kamus Lokal
    int starrow, starcol, row, col;
    Building BTemp;

    //Algoritma
    starrow = RowEff(M) + 2;
    starcol = ColEff(M) + 2;

    for (int i=1; i<=starrow; i++) {
        if (i==1 || i==starrow) {
            for (int j=1; i<=starcol; i++) printf("*");
            printf("\n");
        }
        else {
            row = i-1;
            printf("*");
            for (col=1; col<=ColEff(M); col++) {
                if (MElmt(M,row,col) == 0) printf(" ");
                else if (MElmt(M,row,col) == 1) {
                    BTemp = SearchBuilding(T,row,col);
                    if (Ownership(BTemp)==0) printf("%c", Type(BTemp));
                    else if (Ownership(BTemp)==1) print_red(Type(BTemp));
                    else if (Ownership(BTemp)==2) print_blue(Type(BTemp));
                }
            }
            printf("*\n");
        }
    }


}