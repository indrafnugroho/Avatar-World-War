/*
Matrix.h
DEFINISI ADT MATRIX <Matrix>
*/

#ifndef _MATRIX_H
#define _MATRIX_H

#include "bool.h"

#define RowMin 1
#define RowMax 20
#define ColMin 1
#define ColMax 30

typedef int MatrixVal_t;
typedef int MatrixIndex;
typedef struct {
    MatrixVal_t Mem[RowMax+1][ColMax+1];
    int RowEff;
    int ColEff;
} Matrix;

#define RowEff(m) (m).RowEff
#define ColEff(m) (m).ColEff
#define Mem(m) (m).Mem
#define MElmt(m,i,j) m.Mem[i][j]

void CreateMatrix(Matrix* M, int NRow, int NCol);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NRow x NCol di "ujung kiri" memori */
/* I.S. NRow dan NCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

MatrixIndex GetLastIdxRow (Matrix M);
/* Mengirimkan indeks baris terbesar M */

MatrixIndex GetLastIdxCol (Matrix M);
/* Mengirimkan indeks kolom terbesar M */

MatrixVal_t GetElmtDiagonal (MATRIKS M, indeks i);
/* Mengirimkan elemen M(i,i) */

void SetElmtMatrix(Matrix* M, int NRow, int NCol, int Val);
/*  Mengubah nilai elemen ke (NRow,NCol) pada matriks */

bool IsMatrixSquare (MATRIKS M);
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

bool IsMatrixSymmetry (MATRIKS M);
/* Mengirimkan true jika M adalah matriks simetri : IsMatrixSquare(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */

#endif
