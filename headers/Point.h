/*
Point.h
DEFINISI ADT POINT <Point>
*/

#ifndef _POINT_H
#define _POINT_H

typedef struct {
    int x, y;
} Point;

#define PointX(p) p.x
#define PointY(p) p.y

void PointCreate(Point* P, int x, int y);
void PointMove(Point* P, int dx, int dy);

#endif
