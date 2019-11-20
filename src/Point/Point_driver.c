#include <stdio.h>
#include "Point.h"

int main() {
    Point p;
    printf("[Point Driver]\nCreate point ad x = 7, y = 8: ");
    PointCreate(&p, 7, 8);
    PointPrint(p);
    printf("\nAfter move with dx = 1, dy = -5, become ");
    PointMove(&p, 1, -5);
    PointPrint(p);

    return 0;
}
