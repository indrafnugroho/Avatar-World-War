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

void ScanWord(Word* to);

void ScanInt(int* to);

bool WordToInt(Word w, int* i);

void OutputWord(Word w, bool newline);

void WriteWord(Word w);

void PrintWord(Word w);

#endif
