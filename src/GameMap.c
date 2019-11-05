/*
GameMap.c
IMPLEMENTASI ADT GAMEMAP <GameMap>
*/

#include "GameMap.h"

void PrintMap(Matrix m) {
// Mencetak peta permainan ke layar
// dengan spesifikasi border * di sisi peta
// dan Tipe Bangunan dengan tanda kepemilikan
// warna pemain
    //Kamus Lokal
    int starrow, starcol, row, col;

    //Algoritma
    starrow = MEff(m) + 2;
    starcol = NEff(m) + 2;

    for (int i=1; i<=starrow; i++) {
        if (i==1 || i==starrow) {
            for (int j=1; i<=starcol; i++) printf("*");
            printf("\n");
        }
        else {
            row = i-2;
            printf("*");
            for (col=0; col<N; col++) {
                //Butuh Building dulu
            }
            printf("*\n");
        }
    }


}