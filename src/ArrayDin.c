/*
ArrayDin.c
IMPLEMENTASI ABSTRAKSI ARRAY DINAMIS
*/

#include "ArrayDin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(ArrayDin *T, int MaxElem){
/* I.S. T sembarang, MaxElem > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElem + 1 */
    (TI(*T)) = (int *) malloc (100 * sizeof(int));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}


void Dealokasi(ArrayDin *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElem(T)=0; Neff(T)=0 */
    free(TI(*T));
    Neff(*T) = 0;
    MaxEl(*T) = 0;
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
    return MaxEl(T);
}

ArrayIndex GetFirstIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return Elmt(T,1);
}
ArrayIndex GetLastIdx(ArrayDin T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return (Elmt(T, Neff(T)));
}
/* ********** Test Indeks yang valid ********** */
bool IsIdxValid(ArrayDin T, ArrayIndex i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return((0<= i) && (i <= MaxEl(T)));
}
bool IsIdxEff(ArrayDin T, ArrayIndex i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return((IdxMin <= i) && (i <= Neff(T)));

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
    return(Neff(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(ArrayDin *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElemement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElemement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
    int N,i;
  do {
    scanf("%d", &N);
  }  while (!IsIdxValid(*T, N));
  if (N==0){
    Neff(*T)=0;
  }
  else {
    for (i=1; i<= N; i++){
      scanf("%d", &Elmt(*T,i));
    }
    Neff(*T) = N;
  }
}

void TulisIsiTab(ArrayDin T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
    int i;
  printf("[");
  if (Neff(T) != 0){
    for (i=1; i< Neff(T); i++){
      printf("%d", Elmt(T,i));
      printf(",");
    }
    printf("%d]", Elmt(T, Neff(T)));
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
ArrayDin PlusMinusTab(ArrayDin T1, ArrayDin T2, bool plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt T3;
  int i;
  MakeEmpty (&T3, MaxEl(T1));
  if (plus){
    for (i=1; i<= Neff(T1); i++){
      Elmt(T3,i) = Elmt(T1, i) + Elmt(T2, i);
    }
  }
  else {
    for (i=1; i<= Neff(T1); i++){
      Elmt(T3,i) = Elmt(T1, i) - Elmt(T2, i);
    }
  }
  return T3;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
bool IsEQ(ArrayDin T1, ArrayDin T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    int i;
  if (Neff(T1) != Neff(T2)) {
    return false;
  }
  else {
    for (i=1; i<= Neff(T1); i++){
      if (Elmt(T1, i) != Elmt(T2, i)) {
        return false;
      }
    }
    return true;
  }

}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
ArrayIndex Search1(ArrayDin T, Building X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    int i;
  if (Neff(T) != 0){
    for (i=1; i<= Neff(T); i++){
        if (Elmt(T, i) == X){
          return i;
        }
    }
    return IdxUndef;
  }
  else {
    return IdxUndef;
  }

}

bool SearchB(ArrayDin T, Building X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    int i;
  if (Neff(T) != 0){
    for (i=1; i<= Neff(T); i++){
        if (Elmt(T, i) == X){
          return true;
        }
    }
    return false;
  }
  else {
    return false;
  }

}

/* ********** NILAI EKSTREM ********** */
void MaxMin(ArrayDin T, Building *Max, Building *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
  *Max = Elmt(T,IdxMin);
  *Min = Elmt(T,IdxMin);
  int i;
  for (i=1; i<= Neff(T); i++){
    if (Elmt(T,i) >= (*Max)){
      (*Max) = Elmt(T,i);
    }
    if (Elmt(T,i) <= (*Min)){
      (*Min) = Elmt(T,i);
    }
  }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(ArrayDin Tin, ArrayDin *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElem sama) */
/* Proses : Menyalin isi Tin ke Tout */
    MakeEmpty(Tout, MaxEl(Tin));
  Neff(*Tout) = Neff(Tin);
  int i;
  for (i=1; i<= Neff(Tin); i++){
    Elmt(*Tout, i) = Elmt(Tin,i);
  }
}

int SumTab(ArrayDin T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
  int sum,i;
  sum = 0;
  if (Neff(T) != 0){
    for (i=1; i<=Neff(T); i++){
      sum = sum + Elmt(T,i);
    }
  }
  return sum;
}

int CountX(ArrayDin T, Building X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    int i, count;
  count = 0;
  if (Neff(T)!= 0) {
    for (i=1; i<= Neff(T); i++){
          if (Elmt(T, i) == X){
          count ++;
          }
    }
  }
    return count;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(ArrayDin *T, Building X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    Neff(*T) += 1;
  Elmt(*T, Neff(*T)) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(ArrayDin *T, Building *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
    Elmt(*T, Neff(*T)) = Elmt(*T, Neff(*T)) - *X;
  Neff (*T) -= 1;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(ArrayDin *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    TabInt temp;
	MakeEmpty(&temp,MaxEl(*T));
	CopyTab(*T,&temp);
	MakeEmpty(T,MaxEl(*T)+num);
	CopyTab(temp,T);
	MaxEl(*T) += num;
}
void ShrinkTab(ArrayDin *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxElem > num, dan Neff < MaxElem - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
     MaxEl(*T) -= num;
}

void CompactTab(ArrayDin *T){
/* Proses : Mengurangi max element sehingga Neff = MaxElem */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxElem = Neff */
    MaxEl(*T) = Neff(*T);
}