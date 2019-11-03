/*
WordProcessor.h
DEFINISI ADT MESIN KATA <WordProcessor>
*/

#ifndef _WORDPROCESSOR_H
#define _WORDPROCESSOR_H

#include "bool.h"
#include "CharProcessor.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'
#define MARK '\0'

typedef struct {
    char Tab[NMax]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
} Word;

/* State Mesin Kata */
extern bool EndWord;
extern Word CWord;

void CreateEmpty(Word* w);

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTWORD(char* path);
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinWord();
/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWord(Word from, Word* to);
/* Menyamakan tiap karakter pada to dengan tiap karakter pada from
   I.S. : from terdefinisi, to sembarang
   F.S. : to berisi karakter yang sama dengan pada from */

void ScanWord(Word* to);
/* Menerima masukan satu kata (berhenti pada spasi terdekat)
   I.S. : to sembarang
   F.S. : to terdefinisi, berisi satu kata masukan pengguna */

void ScanInt(int* to);
/* Menerima masukan suatu angka integer yang ditulis pengguna
   I.S. : to sembarang
   F.S. : to menjadi angka yang ditulis pengguna */

void ScanString(char* to, int limit);
/* Menerima suatu string dari pengguna dengan batasan panjang limit-1.
   Batasannya limit-1 karena satu char digunakan untuk simbol \0 sebagai penanda akhir string.
   I.S. : to terdefinisi sebagai array of char dengan ukuran >= limit
   F.S. : to diisi karakter sebanyak limit (termasuk penanda \0) */

bool WordToInt(Word w, int* i);
/* Mengubah suatu Word w menjadi nilai integer pada i.
   Mengembalikan true jika konversi berhasil, false jika gagal.
   I.S. : w terdefinisi, i sembarang
   F.S. : Jika berhasil:
            i menjadi nilai yang tersimpan pada w,
            Fungsi mengembalikan true
          Jika gagal:
            i tidak berubah
            Fungsi mengembalikan false */

void WriteWord(Word w);
/* Mencetak suatu Word w ke layar.
   I.S. : w terdefinisi
   F.S. : w tercetak di layar */

void PrintWord(Word w);
/* Mencetak suatu Word w ke layar diakhiri dengan simbol \n.
   I.S. : w terdefinisi
   F.S. : w tercetak di layar diakhiri simbol \n */

#endif
