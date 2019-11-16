/*
Graph.h
DEFINISI ADT GRAPH <Graph>
*/

#ifndef _GRAPH_H
#define _GRAPH_H

#include "ArrayDin.h"
#include "List.h"


typedef ArrayVal_t GraphVal_t;
typedef ArrayIndex GraphVertex;
typedef ArrayDin Graph;

#define GraphVertexVal(g, v) Elmt(g, v)
#define GraphMaxElement(g) MaxElem(g)

void GraphCreate(Graph* g, int MaxEl);
    /*
    I.S.
        g sembarang
    F.S.
        g merupakan graph terdefinisi yang kosong
    */

bool GraphIsEmpty(Graph g);
    /*
    Menghasilkan true jika g kosong (g.vert kosong)
    */

int  GraphSize(Graph g);

void GraphAddVertex(Graph* g, GraphVertex* v, GraphVal_t x);

void GraphDelVertex(Graph* g, GraphVertex v, GraphVal_t* x);

void GraphAddEdge(Graph* g, GraphVertex v1, GraphVertex v2);

void GraphDelEdge(Graph* g, GraphVertex v1, GraphVertex v2);

GraphVertex GraphSearchVertex(Graph* g, GraphVal_t x);

bool GraphIsAdjacent(Graph g, GraphVertex v1, GraphVertex v2);

void GraphRealloc(Graph* g, int MaxEl);

void GraphDealloc(Graph* g);

#endif
