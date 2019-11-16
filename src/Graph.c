/*
Graph.c
Body ADT GRAPH <Graph>
*/

#include "ArrayDin.h"
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>



void GraphCreate(Graph* g, int MaxEl) {
     
    /*
    I.S.
        g sembarang
    F.S.
        g merupakan graph terdefinisi yang kosong
    */
    MakeEmpty(g, MaxEl);
}

bool GraphIsEmpty(Graph g){
    /*
    Menghasilkan true jika g kosong (g.vert kosong)
    */
    IsEmpty(g); 
}
int GraphSize(Graph g) {
    return Neff(g);
}


void GraphAddEdge(Graph* g, GraphVertex v1, GraphVertex v2) {
    /* Kamus */
     
    /* Algoritma */
    ListAddFirst(&Connect(*GraphVertexVal(*g, v1)), GraphVertexVal(*g, v2));
    ListAddFirst(&Connect(*GraphVertexVal(*g, v2)), GraphVertexVal(*g, v1));
}

bool GraphIsAdjacent(Graph g, GraphVertex v1, GraphVertex v2);

void GraphDealloc(Graph* g){
    free(TI(*g));
}

