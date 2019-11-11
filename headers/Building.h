/*
Building.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _BUILDING_H
#define _BUILDING_H

#include "Player.h"
#include "Point.h"
#include "ArrayDin.h"

typedef struct {
    Point Koordinat;
    int Ownership; //0 tidak dimiliki siapapun, 1 dimiliki player 1, 2 dimiliki player 2
    char Type;
    int Pasukan;
    int Level;
    int A; // Nilai penambahan pasukan pada bangunan tiap awal giliran
    int M; // Jumlah maksimum pasukan yang bisa terdapat pada bangunan
    int P; // Status pertahanan bangunan
    int U; // Pasukan awal yang harus dikalahkan untuk menjadikan bangunan milik pemain
} Building;

/* Selektor */
#define Koordinat(B) (B).Koordinat
#define Ownership(B) (B).Ownership
#define Type(B) (B).Type
#define Pasukan(B) (B).Pasukan
#define Level(B) (B).Level
#define A(B) (B).A
#define M(B) (B).M
#define U(B) (B).U

void InitializationBuilding (Building *B);
    /*
    I.S.
        Parameter-parameter pada Building belum terisi
    F.S.
        Parameter-parameter pada building terisi, sesuai jenis Building
    */

void AddPasukanNextTurn (Building B);
    /*
    I.S.
        Jumlah pasukan pada building sembarang
    F.S.
        Jumlah pasukan pada building bertambah sebesar A, sesuai jenis building
    */

void LevelAdd (Building *B);
    /*
    I.S.
        Level bangunan sembarang
    F.S.
        - Level bangunan bertambah apabila jumlah pasukan pada bangunan >= M/2
        - Jika level bangunan bertambah, jumlah pasukan pada bangunan berkurang sebanyak M/2
    */

#endif