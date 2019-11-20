/*
ArrayDin.c
IMPLEMENTASI ABSTRAKSI ARRAY DINAMIS
*/

#include "ArrayDin/ArrayDin.h"
#include <stdlib.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
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
    free(TI(*T));
    Neff(*T) = 0;
    MaxElem(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(ArrayDin T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    return Neff(T);
}


int MaxElement(ArrayDin T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
    return MaxElem(T);
}

ArrayIndex GetFirstIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return 1;
}
ArrayIndex GetLastIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return Neff(T) - 1;
}
/* ********** Test Indeks yang valid ********** */
bool IsIdxValid(ArrayDin T, ArrayIndex i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((0<= i) && (i < MaxElem(T)));
}
bool IsIdxEff(ArrayDin T, ArrayIndex i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return((IdxMin <= i) && (i < Neff(T)));

}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
bool IsEmpty(ArrayDin T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
    return(Neff(T)==0);
}

bool IsFull(ArrayDin T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return(Neff(T) == MaxElem(T));
}



/* ********** OPERASI LAIN ********** */
void CopyTab(ArrayDin Tin, ArrayDin *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElem sama) */
/* Proses : Menyalin isi Tin ke Tout */
    MakeEmpty(Tout, MaxElem(Tin));
  Neff(*Tout) = Neff(Tin);
  int i;
  for (i=0 ; i< Neff(Tin); i++){
    Elmt(*Tout, i) = Elmt(Tin,i);
  }
}



int CountX(ArrayDin T, Building* X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    int i, count;
  count = 0;
  if (Neff(T)!= 0) {
    for (i= 0; i< Neff(T); i++){
          if (Elmt(T, i) == X){
          count ++;
          }
    }
  }
    return count;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(ArrayDin *T, Building* X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Neff(*T) += 1;
  Elmt(*T, Neff(*T) - 1) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
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
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(ArrayDin *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
  ArrayDin temp;
	MakeEmpty(&temp,MaxElem(*T));
	CopyTab(*T,&temp);
	MakeEmpty(T,MaxElem(*T)+num);
	CopyTab(temp,T);
	MaxElem(*T) += num;
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
