/*
Point.h
DEFINISI ADT POINT <Point>
*/

#ifndef _POINT_H
#define _POINT_H

typedef struct {
    int x, y;
} Point;

#define PointX(p) (p).x
#define PointY(p) (p).y

void PointCreate(Point* p, int x, int y);
    /*
    I.S
        p sembarang, x dan y terdefinisi.
    F.S.
        p terdefinisi dengan p.x = x dan p.y = y.
    */

void PointMove(Point* p, int dx, int dy);
    /*
    I.S
        p terdefinisi.
    F.S
        p.x ditambah dengan dx dan p.y ditambah dengan dy.
    */

void PointPrint(Point p);
    /*
    I.S.
        p terdefinisi.
    F.S.
        p dicetak ke layar dengan format (p.x, p.y).
    */

#endif
