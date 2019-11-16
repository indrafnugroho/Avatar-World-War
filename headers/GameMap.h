/*
GameMap.h
DEFINISI ADT GAMEMAP <GameMap>
*/

#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include "bool.h"
#include "pcolor.h"
#include "Player.h"

#define RowMin 1
#define RowMax 20
#define ColMin 1
#define ColMax 30

typedef int MIndex;
typedef struct {
    Building* Mem[RowMax+1][ColMax+1];
    int RowEff;
    int ColEff;
} GameMap;

#define RowEff(M) (M).RowEff
#define ColEff(M) (M).ColEff
#define MElmt(M,i,j) (M).Mem[i][j]

void CreateEmptyMap(GameMap* Maps, int NRow, int NCol);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NRow x NCol di "ujung kiri" memori */
/* I.S. NRow dan NCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

void SetMap(GameMap* Maps, ArrayDin Arr);
/* Memasukkan elemen-elemen Building ke dalam Matrix yang siap dicetak */

void PrintMap(GameMap Maps, Player P1, Player P2);
// Mencetak peta permainan ke layar
// dengan spesifikasi border * di sisi peta
// dan Tipe Bangunan dengan tanda kepemilikan
// warna pemain (Y for P1, R for P2)

#endif