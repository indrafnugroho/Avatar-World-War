/*
Stack.h
DEFINISI ADT STACK <Stack>
Stack adalah varian dari List dengan penyisipan  dan penghapusan hanya
dilakukan dari elemen pertama (Top).
*/

#ifndef _STACK_H
#define _STACK_H

#include "List/List.h"

/* Definisi Elemen Stack dan Stack */
typedef ListVal_t StackVal_t;
typedef ListElement StackElement;
typedef List Stack;

/* Selektor */
#define StackTop(s) ListFirstElement(s)
#define StackValueTop(s) ListValueFirst(s)

/* Primitif */
void StackCreate(Stack *s);
    /*
    I.S.
        s sembarang.
    F.S.
        s merupakan stack terdefinisi denga top(l) menunjuk ke Nil.
    */

bool StackIsEmpty(Stack s);
    /*
    Mengembalikan true jika s kosong (top(s) menunjuk ke Nil)
    */

void StackPush(Stack* s, StackVal_t x);
    /*
    I.S.
        s terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan s, menjadi top(s)
    */

void StackPop(Stack* s, StackVal_t* x);
    /*
    I.S.
        s tidak kosong
    F.S.
        Elemen top(s) dihapus dan nilainya dimasukkan ke x, top(s) menjadi
        elemen setelahnya atau Nil juka stack kosong.
    */

#endif
