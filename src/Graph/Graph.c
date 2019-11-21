/*
Graph.c
Body ADT GRAPH <Graph>
*/

#include "Graph/Graph.h"
#include <stdlib.h>

void GraphCreate(Graph* g) {
     
    /*
    I.S.
        g sembarang
    F.S.
        g merupakan graph terdefinisi yang kosong
    */
    ListCreate(g);
}

bool GraphIsEmpty(Graph g){
    /*
    Menghasilkan true jika g kosong (g.vert kosong)
    */
    return ListIsEmpty(g); 
}
int GraphSize(Graph g) {
    return ListSize(g);
}


void GraphAddEdge(Graph* g, GraphVertex v1, GraphVertex v2) { 
    /* Algoritma */
    ListAddFirst(&GraphVertexAdj(v1), v2);
}

void GraphNewVertexLast(Graph* g) {
    /* Kamus Lokal */
    List* gv;
    /* Algoritma */
    gv = (List*)malloc(sizeof(List));
    ListCreate(gv);
    GraphAddVertex(g, gv);
}


void GraphAddEdgeIdx(Graph* g, int i1, int i2) {
    GraphAddEdge(g, GraphGetVertexFromIdx(*g, i1), GraphGetVertexFromIdx(*g, i2));
}

void GraphDelEdge(Graph* g, GraphVertex v1, GraphVertex v2){
    ListDelVal(&GraphVertexAdj(v1), v2);
    //ListDelVal(&GraphVertexAdj(v2), v1);
    //ListDelVal(&Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g, v2), success);
    //ListDelVal(&Connect(*GraphVertexVal(*g,v2)), GraphVertexVal(*g, v1), success);
}

void GraphDelEdgeIdx(Graph* g, int i1, int i2) {
    GraphDelEdge(g, GraphGetVertexFromIdx(*g, i1), GraphGetVertexFromIdx(*g, i2));
}

bool GraphIsAdjacent(Graph g, GraphVertex v1, GraphVertex v2){
    bool found = true;
    return ListSearch(GraphVertexAdj(v1), v2) != Nil;
    /*
    if (((ListSearch(Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g,v2))) == 0) || ((ListSearch(Connect(*GraphVertexVal(*g,v1)), GraphVertexVal(*g,v2))) == 1)){
        return false;
    }
    else {
        return true;
    }*/
}

bool GraphIsAdjacentIdx(Graph g, int i1, int i2) {
    return GraphIsAdjacent(g, GraphGetVertexFromIdx(g, i1), GraphGetVertexFromIdx(g, i2));
}


void GraphAddVertex(Graph* g, List* x){  
    ListAddLast(g, x);
}

GraphVertex GraphGetVertexFromIdx(Graph g, int idx) {
    return ListIdx(g, idx);
}

int GraphGetVertexIdx(Graph g, GraphVertex v) {
    /* Mengembalikan indeks vertex pada g */
    return ListGetIdx(g, v);
}




