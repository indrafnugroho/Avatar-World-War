/*
Building.h
DEFINISI ABSTRAKSI GAME
*/

#ifndef _BUILDING_H
#define _BUILDING_H

#include "Player.h"

typedef struct {
    int owner;
    int pasukan;
    int level;
    int A;
    int M;
    int P;
    int U;
    int type;
} Building;

void InitialBuilding (Building *B);
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
