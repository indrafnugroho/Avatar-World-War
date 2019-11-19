/*
GameMap.c
IMPLEMENTASI ADT GAMEMAP <GameMap>
*/

#include "GameMap.h"
#include "Art.h"
#include <stdio.h>

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

void SetMap(GameMap* Maps, ArrayDin Buildings) {
/* Memasukkan elemen-elemen Building ke dalam Matrix yang siap dicetak */
    for (int i=0; i<Neff(Buildings); i++) {
        printf("%d %c\n", i, Type(*Elmt(Buildings, i)));
        MElmt(*Maps, Koordinat(*Elmt(Buildings, i)).x, Koordinat(*Elmt(Buildings, i)).y) = Elmt(Buildings, i);
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
    DisplayTitleMini();
    DisplayPrompt("GAME MAP");
    printf("\n\n");
    for (int i=1; i<=RowStar; i++) {
        if (i==1 || i==RowStar) {
            printf("  ");
            set_print_color(BG_WHITE);
            for (int j=1; j<=ColStar; j++) printf(" ");
            reset_print_color();
            printf("\n");
        }
        else {
            printf("  ");
            set_print_color(BG_WHITE);
            Row = i-1;
            printf(" ");
            set_print_color(BG_BLACK);
            set_print_color(WHITE);
            set_print_color(BOLD);
            for (Col=1; Col<=ColEff(Maps); Col++) {
                if (MElmt(Maps,Row,Col) == Nil) printf(" ");
                else {
                    if (ListSearch(Buildings(P1), MElmt(Maps,Row,Col)) != Nil)
                        set_print_color(BLUE);
                    else if (ListSearch(Buildings(P2), MElmt(Maps,Row,Col)) != Nil) 
                        set_print_color(RED);
                    else
                        set_print_color(WHITE); 
                    printf("%c", Type(*MElmt(Maps,Row,Col)));
                }
            }
            set_print_color(BG_WHITE);
            printf(" ");
            reset_print_color();
            printf("\n");
        }
    }
}
