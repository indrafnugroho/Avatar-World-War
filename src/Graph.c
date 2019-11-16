/*
Graph.c
Body ADT GRAPH <Graph>
*/

#include "ArrayDin.h"
#include "Graph.h"
#include "List.h"
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
    return IsEmpty(g); 
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

void GraphDelEdge(Graph* g, GraphVertex v1, GraphVertex v2){
    bool success;
    ListDelVal(Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g, v2), success);
    ListDelVal(Connect(*GraphVertexVal(*g,v2)), GraphVertexVal(*g, v1), success);
}

bool GraphIsAdjacent(Graph *g, GraphVertex v1, GraphVertex v2){
    bool found = true;
    if (((ListSearch(Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g,v2))) == 0) || ((ListSearch(Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g,v2))) == 1)){
        return false;
    }
    else {
        return true;
    }
}

void GraphDealloc(Graph* g){
    free(TI(*g));
}

void GraphAddVertex(Graph* g, GraphVal_t x){
  
    AddAsLastEl(g, x);
}

void GraphDelVertex(Graph* g, GraphVertex v, GraphVal_t* x){
    GraphVertexVal(*g, v) = GraphVertexVal(*g, v) - *x;
    Neff(*g) = Neff(*g) - 1;
    
}

GraphVertex GraphSearchVertex(Graph* g, GraphVal_t x){
    return Search1(*g, x);
}

void GraphRealloc(Graph* g, int MaxEl){
    
}
