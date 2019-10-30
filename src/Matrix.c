/*
Matrix.c
IMPLEMENTASI ADT MATRIX <Matrix>
*/

#include "Matrix.h"
#include <stdlib.h>

void MatrixCreate(Matrix* m, int mMax, int nMax) {
    MMax(*m) = mMax;
    NMax(*m) = nMax;
    MEff(*m) = 0;
    NEff(*m) = 0;

    //Allocate Matrix
    M(*m) = (MatrixVal_t**) malloc ((mMax+1) * sizeof(MatrixVal_t*));

    for (int i=1; i<=mMax; i++) {
        (*m).M[i] = (MatrixVal_t*) malloc ((nMax+1) * sizeof(MatrixVal_t));
    }
}

void MatrixSetStaticSize(Matrix* m, int mNew, int nNew) {
    
}

bool MatrixIsEmpty(Matrix m) {
    return (MEff(m)==0 && NEff(m)==0);
}

bool MatrixIsFull(Matrix m) {
    return (MEff(m)==MMax(m) && NEff(m)==NMax(m));
}

bool MatrixIsSquare(Matrix m) {
    return MEff(m)==NEff(m);
}

bool MatrixIsSimetrical(Matrix m) {
    
}

Matrix MatrixTranspose(Matrix m) {}

void MatrixRealloc(Matrix* m, int mNew, int nNew) {
    MMax(*m) = mNew;
    NMax(*m) = nNew;

    M(*m) = realloc(M(*m), ((mMax+1) * sizeof(MatrixVal_t*)));

    for (int i=1; i<=nNew; i++) {
        (*m).M[i] = realloc((*m).M[i], ((nNew+1)*sizeof(MatrixVal_t)));
    }
}

void MatrixDealloc(Matrix* m) {
    free(M(*m));
}