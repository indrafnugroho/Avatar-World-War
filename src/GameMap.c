/*
GameMap.c
IMPLEMENTASI ADT GAMEMAP <GameMap>
*/

#include "GameMap.h"

void CreateEmptyMap(GameMap* Maps, int NRow, int NCol) {
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NRow x NCol di "ujung kiri" memori */
/* I.S. NRow dan NCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    RowEff(*Maps) = NRow;
    ColEff(*Maps) = NCol;

    for (int i=1; i<=RowEff(*Maps); i++) {
        for (int j=1; j<=ColEff(*Maps); j++) {
            MElmt(*Maps,i,j) = Nil;
        }
    }
}

void SetMap(GameMap* Maps, ArrayDin Arr) {
/* Memasukkan elemen-elemen Building ke dalam Matrix yang siap dicetak */
    for (int i=1; i<=Neff(GG->Buildings); i++) {
        MElmt(*Maps, Koordinat(*Elmt(Arr, i)).X, Koordinat(*Elmt(Arr, i)).Y) = Elmt(Arr, i);
    }
}

void PrintMap(GameMap Maps, Player P1, Player P2) {
// Mencetak peta permainan ke layar
// dengan spesifikasi border * di sisi peta
// dan Tipe Bangunan dengan tanda kepemilikan
// warna pemain
    int RowStar, ColStar;
    int Row, Col;

    RowStar = RowEff(Maps) + 2;
    ColStar = ColEff(Maps) + 2;

    for (int i=1; i<=RowStar; i++) {
        if (i==1 || i==RowStar) {
            for (int j=1; j<=ColStar; j++) printf("*");
            printf("\n");
        }
        else {
            Row = i-1;
            printf("*");
            for (Col=1; Col<=ColEff(M); Col++) {
                if (MElmt(Maps,Row,Col) == Nil) printf(" ");
                else {
                    if (ListSearch(Buildings(P1), MElmt(Maps,Row,Col)) != Nil) print_yellow(Type(MElmt(Maps,Row,Col)));
                    else if (ListSearch(Buildings(P2), MElmt(Maps,Row,Col)) != Nil) print_red(Type(MElmt(Maps,Row,Col)));
                    else printf("%c", Type(MElmt(Maps,Row,Col)));
                }
            }
            printf("*\n");
        }
    }
}