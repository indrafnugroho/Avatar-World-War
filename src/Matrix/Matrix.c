/*
Matrix.c
IMPLEMENTASI ADT MATRIX <Matrix>
*/

#include "Matrix.h"

void CreateMatrix(Matrix* M, int NRow, int NCol) {
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NRow x NCol di "ujung kiri" memori */
/* I.S. NRow dan NCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    RowEff(*M) = NRow;
    ColEff(*M) = NCol;
}

MatrixIndex GetLastIdxRow (Matrix M) {
/* Mengirimkan indeks baris terbesar M */
    return RowEff(M);
}

MatrixIndex GetLastIdxCol (Matrix M) {
/* Mengirimkan indeks kolom terbesar M */
    return ColEff(M);
}

MatrixVal_t GetElmtDiagonal (MATRIKS M, indeks i) {
/* Mengirimkan elemen M(i,i) */
    return MElmt(M,i,i);
}

void SetElmtMatrix(Matrix* M, int NRow, int NCol, int Val) {
/*  Mengubah nilai elemen ke (NRow,NCol) pada matriks */
    MElmt(*M,NRow,NCol) = Val;
}

bool IsMatrixSquare (MATRIKS M) {
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return (GetLastIdxRow(M) == GetLastIdxCol(M));
}

bool IsMatrixSymmetry (MATRIKS M) {
/* Mengirimkan true jika M adalah matriks simetri : IsMatrixSquare(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
    //Kamus Lokal
    MatrixIndex i=RowMin, j;
    bool found=false;

    //Algoritma
    if (IsMatrixSquare(M)) {
        while ((!found) && (i<=GetLastIdxRow(M))) {
            j=ColMin;
            while ((!found) && (j<=GetLastIdxCol(M))) {
                if (MElmt(M,i,j) != MElmt(M,j,i)) found = true;
                else j++;
            } 
            i++;
        } 
        return (!found);
    } 
    else return false;
}