#include "Queue.h"

void QueueCreate(Queue *q) {
    /*
    I.S.
        q sembarang.
    F.S.
        q merupakan queue terdefinisi denga head(q) dan tail(q) menunjuk ke Nil.
    */
    /* ALgoritma */
    ListCreate(q);
}

bool QueueIsEmpty(Queue q) {
    /*
    Mengembalikan true jika q kosong (head(q) dan tail(q) menunjuk ke Nil)
    */
    /* ALgoritma */
    return ListIsEmpty(q);
}

void QueueAdd(Queue* q, QueueVal_t x) {
    /*
    I.S.
        q terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang q, menjadi tail(q)
    */
    /* ALgoritma */
    ListAddLast(q, x);
}

void QueueDel(Queue* q, QueueVal_t* x) {
    /*
    I.S.
        q tidak kosong
    F.S.
        Elemen head(q) dihapus dan nilainya dimasukkan ke x, head(q) menjadi
        elemen setelahnya atau Nil jika queue kosong.
    */
    /* ALgoritma */
    ListDelFirst(q, x);
}
