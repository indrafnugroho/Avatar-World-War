/*
IArray.h
DEFINISI ADT Array Implisit <IArray>
*/

#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "bool/bool.h"
#include "Building/Building.h"

#define IndexUndef 0
#define IdxMin 1
#define ValUndef -999999
#define Nil 0

typedef int ArrayIndex;
typedef Building* ArrayVal_t;

typedef struct {
    Building** TI;
    int Neff;
    int MaxElem;
} ArrayDin;

#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxElem(T) (T).MaxElem

void MakeEmpty(ArrayDin *T, int MaxElem);
/* I.S. T sembarang, MaxElem > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElem + 1 */

void Dealokasi(ArrayDin *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElem(T)=0; Neff(T)=0 */

int NbElmt(ArrayDin T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

ArrayIndex GetFirstIdx(ArrayDin T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

ArrayIndex GetLastIdx(ArrayDin T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

bool IsEmpty(ArrayDin T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

bool IsFull(ArrayDin T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void CopyTab(ArrayDin Tin, ArrayDin *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElem sama) */
/* Proses : Menyalin isi Tin ke Tout */

void RevertTab(ArrayDin Tin, ArrayDin *Tout);
/* I.S. Tout dan Tin berukuran sama */
/* F.S. Nilai elemen Building di Tout menjadi sama dengan di Tin */
/* Proses : Menyalin isi Tin ke Tout */

void AddAsLastEl(ArrayDin *T, Building* X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void DelLastEl(ArrayDin *T, Building** X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

void GrowTab(ArrayDin *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(ArrayDin *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxElem > num, dan Neff < MaxElem - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(ArrayDin *T);
/* Proses : Mengurangi max element sehingga Neff = MaxElem */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxElem = Neff */

Building SearchBuilding(ArrayDin T, int Row, int Col);
/*  Mencari Building berdasarkan koordinat masukan (Row,Col) */
/*  I.S. Building pasti ada di Array */
/*  F.S. Memberikan hasil Building */

ArrayIndex Search1 (ArrayDin T, Building *X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */

void DelEli (ArrayDin * T, ArrayIndex i, Building ** X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

#endif