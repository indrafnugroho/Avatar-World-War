#include "Stack/Stack.h"

void StackCreate(Stack *s) {
    /*
    I.S.
        s sembarang.
    F.S.
        s merupakan stack terdefinisi denga top(l) menunjuk ke Nil.
    */
    /* ALgoritma */
    ListCreate(s);
}

bool StackIsEmpty(Stack s) {
    /*
    Mengembalikan true jika s kosong (top(s) menunjuk ke Nil)
    */
    /* ALgoritma */
    return ListIsEmpty(s);
}

void StackPush(Stack* s, StackVal_t x) {
    /*
    I.S.
        s terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan s, menjadi top(s)
    */
    /* ALgoritma */
    ListAddFirst(s, x);
}

void StackPop(Stack* s, StackVal_t* x) {
    /*
    I.S.
        s tidak kosong
    F.S.
        Elemen top(s) dihapus dan nilainya dimasukkan ke x, top(s) menjadi
        elemen setelahnya atau Nil juka stack kosong.
    */
    /* ALgoritma */
    ListDelFirst(s, x);
}
