/*
Matrix.h
DEFINISI ADT MATRIX <Matrix>
*/

#ifndef _MATRIX_H
#define _MATRIX_H

typedef void* MatrixVal_t;
typedef int MatrixIndex;
typedef struct {
    MatrixVal_t** M;
    int MMax, NMax, MEff, NEff;
} Matrix;

#define MMax(m) m.MMax
#define NMax(m) m.NMax
#define MEff(m) m.MEff
#define NEff(m) m.NEff
#define M(m) (m).M
#define MatrixElement(m, i, j) m.M[i][j]

void MatrixCreate(Matrix* m, int mMax, int nMax);

void MatrixSetStaticSize(Matrix* m, int mNew, int nNew);

bool MatrixIsEmpty(Matrix m);

bool MatrixIsFull(Matrix m);

bool MatrixIsSquare(Matrix m);

bool MatrixIsSimetrical(Matrix m);

Matrix MatrixTranspose(Matrix m);

void MatrixRealloc(Matrix* m, int mNew, int nNew);

void MatrixDealloc(Matrix* m);

#endif
