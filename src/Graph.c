/*
Graph.c
Body ADT GRAPH <Graph>
*/

#include "IArray.h"
#include "Matrix.h"
#include "Graph.h"
#include "stdio.h"
#include "stdlib.h"



void GraphCreate(Graph* g, int MaxEl){
    /*
    I.S.
        g sembarang
    F.S.
        g merupakan graph terdefinisi yang kosong
    */

}

void GraphIsEmpty(Graph g);
    /*
    Menghasilkan true jika g kosong (g.vert kosong)
    */

void GraphSize(Graph g);

void GraphAddVertex(Graph* g, GraphVertex* v, GraphVal_t x);

void GraphDelVertex(Graph* g, GraphVertex v, GraphVal_t* x);

void GraphAddEdge(Graph* g, GraphVertex v1, GraphVertex v2);

void GraphDelEdge(Graph* g, GraphVertex v1, GraphVertex v2);

GraphVertex GraphSearchVertex(Graph* g, GraphVal_t x)

bool GraphIsAdjacent(Graph g, GraphVertex v1, GraphVertex v2);

void GraphRealloc(Graph* g, int MaxEl);

void GraphDealloc(Graph* g){
    free(*g);
}

#endif

