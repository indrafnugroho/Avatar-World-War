/*
GameMap.c
IMPLEMENTASI ADT GAMEMAP <GameMap>
*/

#include "GameMap/GameMap.h"
#include "Art/Art.h"
#include <stdio.h>

const bool use_emoji = false;
const char castle_icon[4] = {0xE2,0x9B,0xAA, '\0'};
const char tower_icon[4] = {0xE2,0x9B,0xB2, '\0'};
const char fort_icon[5] = {0xF0,0x9F,0x8F,0xAD, '\0'};
const char village_icon[5] = {0xF0,0x9F,0x8F,0xA0, '\0'};

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
        //printf("%d %c\n", i, Type(*Elmt(Buildings, i)));
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
    char type;

    RowStar = RowEff(Maps) + 2;
    ColStar = ColEff(Maps) + 2;
    DisplayTitleMini();
    DisplayPrompt("GAME MAP");
    printf("\n\n");
    for (int i=1; i<=RowStar; i++) {
        if (i==1 || i==RowStar) {
            printf("  ");
            set_print_color(BG_WHITE);
            for (int j=1; j<=ColStar; j++) printf("  ");
            printf(" ");
            reset_print_color();
            printf("\n");
        }
        else {
            printf("  ");
            set_print_color(BG_WHITE);
            Row = i-1;
            printf("  ");
            set_print_color(BG_BLACK);
            set_print_color(WHITE);
            set_print_color(BOLD);
            printf(" ");
            for (Col=1; Col<=ColEff(Maps); Col++) {
                if (MElmt(Maps,Row,Col) == Nil) printf("  ");
                else {
                    if (ListSearch(Buildings(P1), MElmt(Maps,Row,Col)) != Nil)
                        set_print_color(BLUE);
                    else if (ListSearch(Buildings(P2), MElmt(Maps,Row,Col)) != Nil) 
                        set_print_color(RED);
                    else
                        set_print_color(WHITE);
                    type = Type(*MElmt(Maps,Row,Col));
                    if (use_emoji) {
                        switch (type) {
                            case 'C':
                                printf("%s ", castle_icon);
                                break;
                            case 'T':
                                printf("%s ", tower_icon);
                                break;
                            case 'F':
                                printf("%s ", fort_icon);
                                break;
                            case 'V':
                                printf("%s ", village_icon);
                                break;
                        }
                    } else {
                        printf("%c ", type);
                    }
                    
                }
            }
            set_print_color(BG_WHITE);
            printf("  ");
            reset_print_color();
            printf("\n");
        }
    }
    printf("\n");
    if (use_emoji) {
        printf("  %s = Castle\n  %s = Fort\n  %s = Tower\n  %s = Village\n", castle_icon, fort_icon, tower_icon, village_icon);
        printf("\n");
    }
}
