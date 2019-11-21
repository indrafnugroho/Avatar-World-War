/*
Graph.h
DEFINISI ADT GRAPH <Graph>
*/

#ifndef _GRAPH_H
#define _GRAPH_H

#include "List/List.h"


typedef ListElement* GraphVertex;
typedef List Graph;

#define GraphVertexFirst(g) ListFrstElement(g)
#define GraphVertexAdj(p) (*(List*)ListElementVal(p))

void GraphCreate(Graph* g);
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
    /*
    Mengembalikan banyak vertex pada g
    */


void GraphAddVertex(Graph* g, List* x);
    /*
    I.S.
        x adalah pointer to list (sebagai adjacency list, g terdefinisi)
    F.S.
        x menjadi niali vertex dari g 
    */

void GraphNewVertexLast(Graph* g);
    /*
    I.S
        g terdefinisi
    F.S.
        terdepat vertex baru di g
    */

void GraphAddEdge(Graph* g, GraphVertex v1, GraphVertex v2);
    /*
    I.S.
        v1 dan v2 adalah vertex dari g
    F.S.
        v1 dan v2 terhubung
    */

void GraphDelEdge(Graph* g, GraphVertex v1, GraphVertex v2);
    /*
    I.S.
        v1 dan v2 adalah vertex dari g dan terhubung edge
    F.S.
        edge yang menghubungkan v1 dan v2 dihapus
    */

bool GraphIsAdjacent(Graph g, GraphVertex v1, GraphVertex v2);
    /* Mengembalikan true jika v1 dan v2 terhubung edge */

GraphVertex GraphGetVertexFromIdx(Graph g, int idx);
    /* Mengembalikan vertex indeks ke-idx pada g */

int GraphGetVertexIdx(Graph g, GraphVertex v);
    /* Mengembalikan indeks vertex pada g */

void GraphAddEdgeIdx(Graph* g, int i1, int i2);
    /*
    I.S.
        v1 dan v2 adalah vertex indeks ke i1 dan i2 dari g
    F.S.
        v1 dan v2 terhubung
    */

void GraphDelEdgeIdx(Graph* g, int i1, int i2);
    /*
    I.S.
        v1 dan v2 adalah vertex indeks ke i1 dan i2 dari g
    F.S.
        v1 dan v2 terhubung
    */

bool GraphIsAdjacentIdx(Graph g, int i1, int i2);
    /* Mengembalikan true jika verteks indeks ke i1 dan i2 terhubung edge */


#endif
