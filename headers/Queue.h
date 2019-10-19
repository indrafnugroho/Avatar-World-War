/*
Queue.h
DEFINISI ADT QUEUE <Queue>
Queue adalah varian dari List dengan penyisipan hanya dilakukan dari elemen
terakhir (Tail) dan penghapusan hanya dilakukan dari elemen pertama (Head).
*/

#ifndef _QUEUE_H
#define _QUEUE_H

#include "List.h"

/* Definisi Elemen Queue dan Queue */
typedef ListVal_t QueueVal_t;
typedef ListElement QueueElement;
typedef List Queue;

/* Selektor */
#define QueueHead(q) ListFirstElement(q)
#define QueueTail(q) ListLastElement(q)
#define QueueValueHead(q) ListValueFirst(q)
#define QueueValueTail(q) ListValueLast(q)

/* Primitif */
void QueueCreate(Queue* q);
    /*
    I.S.
        q sembarang.
    F.S.
        q merupakan queue terdefinisi denga head(q) dan tail(q) menunjuk ke Nil.
    */

bool QueueIsEmpty(Queue q);
    /*
    Mengembalikan true jika q kosong (head(q) dan tail(q) menunjuk ke Nil)
    */

void QueueAdd(Queue* q, QueueVal_t x);
    /*
    I.S.
        q terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang q, menjadi tail(q)
    */

void QueueDel(Queue* q, QueueVal_t* x);
    /*
    I.S.
        q tidak kosong
    F.S.
        Elemen head(q) dihapus dan nilainya dimasukkan ke x, head(q) menjadi
        elemen setelahnya atau Nil jika queue kosong.
    */

#endif
