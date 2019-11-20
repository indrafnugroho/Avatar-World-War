/*
Point.c
IMPLEMENTASI ADT POINT <Point>
*/

#include "Point/Point.h"
#include <stdio.h>

void PointCreate(Point* p, int x, int y) {
    /*
    I.S
        p sembarang, x dan y terdefinisi.
    F.S.
        p terdefinisi dengan p.x = x dan p.y = y.
    */
    /* Algoritma */
    PointX(*p) = x;
    PointY(*p) = y;
}

void PointMove(Point* p, int dx, int dy) {
    /*
    I.S
        p terdefinisi.
    F.S
        p.x ditambah dengan dx dan p.y ditambah dengan dy.
    */
    /* Algoritma */
    PointX(*p) += dx;
    PointY(*p) += dy;
}

void PointPrint(Point p) {
    /*
    I.S.
        p terdefinisi.
    F.S.
        p dicetak ke layar dengan format (p.x, p.y).
    */
    /* Algoritma */
    printf("(%d, %d)", PointX(p), PointY(p));
}
