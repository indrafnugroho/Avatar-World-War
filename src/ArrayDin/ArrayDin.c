/*
ArrayDin.c
IMPLEMENTASI ABSTRAKSI ARRAY DINAMIS
*/

#include "ArrayDin/ArrayDin.h"
#include <stdlib.h>
#include <stdio.h>

void MakeEmpty(ArrayDin *T, int MaxEl) {
/* I.S. T sembarang, MaxElem > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElem + 1 */
    (TI(*T)) = (Building **) malloc (MaxEl* sizeof(Building));
    Neff(*T) = 0;
    MaxElem(*T) = MaxEl;
}

void Dealokasi(ArrayDin *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElem(T)=0; Neff(T)=0 */
    int i;
    for (i = GetFirstIdx(*T); i < Neff(*T); i++) {
        free(Elmt(*T, i));
    }
    free(TI(*T));
    Neff(*T) = 0;
    MaxElem(*T) = 0;
}

int NbElmt(ArrayDin T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return Neff(T);
}

ArrayIndex GetFirstIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return 0;
}

ArrayIndex GetLastIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return Neff(T) - 1;
}

bool IsEmpty(ArrayDin T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
    return(Neff(T)==0);
}

bool IsFull(ArrayDin T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return(Neff(T) == MaxElem(T));
}

void CopyTab(ArrayDin Tin, ArrayDin *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElem sama) */
/* Proses : Menyalin isi Tin ke Tout */
    MakeEmpty(Tout, MaxElem(Tin));
  Neff(*Tout) = Neff(Tin);
  int i;
  for (i=0 ; i< Neff(Tin); i++) {
    Elmt(*Tout, i) = (Building*)malloc(sizeof(Building));
    *(Building*)Elmt(*Tout, i) = CopyBuilding(*(Building*)Elmt(Tin, i));
  }
}

void RevertTab(ArrayDin Tin, ArrayDin *Tout){
/* I.S. Tout dan Tin berukuran sama */
/* F.S. Nilai elemen Building di Tout menjadi sama dengan di Tin */
/* Proses : Menyalin isi Tin ke Tout */
  Neff(*Tout) = Neff(Tin);
  int i;
  for (i=0 ; i< Neff(Tin); i++) {
    *(Building*)Elmt(*Tout, i) = CopyBuilding(*(Building*)Elmt(Tin, i));
  }
}

void AddAsLastEl(ArrayDin *T, Building* X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Neff(*T) += 1;
  Elmt(*T, Neff(*T) - 1) = X;
}

void DelLastEl(ArrayDin *T, Building** X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T, Neff(*T) - 1);
    Elmt(*T, Neff(*T) - 1) = Nil;
  Neff (*T) -= 1;
}

void GrowTab(ArrayDin *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    MaxElem(*T) += num;
    (TI(*T)) = (Building**) realloc(TI(*T), MaxElem(*T) * sizeof(Building*));
}

void ShrinkTab(ArrayDin *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxElem > num, dan Neff < MaxElem - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    if (Neff(*T) < MaxElem(*T) - num ) { 
        MaxElem(*T) -= num;
        (TI(*T)) = (Building**) realloc(TI(*T), MaxElem(*T) * sizeof(Building*));
    }
}

void CompactTab(ArrayDin *T){
/* Proses : Mengurangi max element sehingga Neff = MaxElem */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxElem = Neff */
    MaxElem(*T) = Neff(*T);
    (TI(*T)) = (Building**) realloc(TI(*T), MaxElem(*T) * sizeof(Building*));
}

Building SearchBuilding(ArrayDin T, int Row, int Col) {
/*  Mencari Building berdasarkan koordinat masukan (Row,Col) */
/*  I.S. Building pasti ada di Array */
/*  F.S. Memberikan hasil Building */
    ArrayIndex i=1;
    bool found=false;

    while (i<=Neff(T) && !found) {
        if (PointX(Koordinat(*Elmt(T,i))) == Row && PointY(Koordinat(*Elmt(T,i))) == Col) {
            found = true;
        }
        else i++;
    }
    return *Elmt(T,i);
}

ArrayIndex Search1 (ArrayDin T, Building *X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    int i = GetFirstIdx(T);
    while ((i <= GetLastIdx(T)) && (Elmt(T, i) != X)) {
        i ++;
    }

    if (i <= GetLastIdx(T)) {
        return i;
    } else {
        return ValUndef;
    }
}

void DelEli (ArrayDin * T, ArrayIndex i, Building ** X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    *X = Elmt(*T, i);

    int j;
    for (j = i; j <= (GetLastIdx(*T) - 1); j++) {
        Elmt(*T, j) = Elmt(*T, (j + 1));
    }

    Neff(*T) -= 1;
}