/*
List.c
IMPLEMENTASI ADT LIST LINIER <List>
*/

#include "List.h"
#include <stdlib.h>

ListElement* ListElementAlloc(ListVal_t x) {
    /*
    Mengembalikan pointer yang menunjuk ke ListElement yang dialokasi dengan nilai x.
    */
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    p = (ListElement*) malloc(sizeof(ListElement));
    /* Jika alokasi berhasil masukkan nilai x */
    if (p != Nil) ListElementVal(p) = x;
    return p;
}

void ListCreate(List* l) {
    /*
    I.S.
        l sembarang.
    F.S.
        l merupakan list terdefinisi denga first(l) dan last(l) menunjuk ke Nil.
    */
    /* Algoritma */
    ListFirstElement(*l) = Nil;
    ListLastElement(*l) = Nil;
}


bool ListIsEmpty(List l) {
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */
    /* Algoritma */
    return (ListFirstElement(l) == Nil) && (ListLastElement(l) == Nil);
}

int ListSize(List l) {
    /*
    Mengembalikan banyak elemen dalam l
    */
    /* Kamus lokal */
    ListElement* p;
    int count;
    /* Algoritma */
    if (ListIsEmpty(l)) {
        return 0;
    } else {
        count = 0;
        ListTraversal (p, ListFirstElement(l), p != Nil) {
            count++;
        }
        return count;
    }
}

void ListAddFirst(List* l, ListVal_t x) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */
    /* Kamus lokal */
    ListElement* p;
    /* Algoritma */
    p = ListElementAlloc(x);
    if (p != Nil) {
        if (ListIsEmpty(*l)) {
            /* List kosong */
            ListElementNext(p) = Nil;
            ListFirstElement(*l) = p;
            ListLastElement(*l) = p;
        } else {
            /* List tidak kosong, sisipkan elemen di depan first(l) */
            ListElementNext(p) = ListFirstElement(*l);
            ListFirstElement(*l) = p;
        }
    }
}

void ListAddAfter(List* l, ListVal_t x, ListElement* prec) {
    /*
    I.S.
        l terdefinisi, tidak kosong.
        prec != Nil dan berada pada l
    F.S.
        Elemen bernilai x diletakkan setelah prec
    */
    /* Kamus lokal */
    ListElement* p;
    /* Algoritma */
    p = ListElementAlloc(x);
    if (p != Nil) {
        ListElementNext(p) = ListElementNext(prec);
        ListElementNext(prec) = p;
        if (ListLastElement(*l) == prec) {
            ListLastElement(*l) = p;
        }
    }
}

void ListAddLast(List* l, ListVal_t x) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */
    /* Algoritma */
    if (ListIsEmpty(*l)) {
        ListAddFirst(l, x);
    } else {
        ListAddAfter(l, x, ListLastElement(*l));
    }
}

void ListDelFirst(List* l, ListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    p = ListFirstElement(*l);
    *x = ListElementVal(p);
    if (ListFirstElement(*l) == ListLastElement(*l)) {
        ListFirstElement(*l) = Nil;
        ListLastElement(*l) = Nil;
    } else {
        ListFirstElement(*l) = ListElementNext(ListFirstElement(*l));
    }
    free(p);
}

void ListDelAfter(List* l, ListVal_t* x, ListElement* prec) {
    /*
    I.S.
        l tidak kosong, prec != Nil dan berada pada l, next(prec) != Nil
    F.S.
        Elemen suksesor prec dihapus dan nilainya dimasukkan ke x.
        Jika suksesor adalah last(l), last(l) = prec
    */
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    p = ListElementNext(prec);
    *x = ListElementVal(p);
    ListElementNext(prec) = ListElementNext(p);
    if (ListLastElement(*l) == p) {
        ListLastElement(*l) = prec;
    }
    free(p);
}

void ListDelVal(List* l, ListVal_t x, bool success) {
    /*
    I.S.
        l tidak kosong.
    F.S.
        Jika ada elemen bernilai x di l, hapus n dan success bernilai true.
        Jika tidak ada, success bernilai false.
    */
    /* Kamus Lokal */
    ListElement* p;
    ListVal_t discard;
    /* Algoritma */
    p = ListFirstElement(*l);
    if (ListElementVal(p) == x) {
        ListDelFirst(l, &discard);
    } else {
        ListTraversal (p, ListFirstElement(*l),
            ListElementVal(ListElementNext(p)) != x) {}
        ListDelAfter(l, &discard, p);
    }
}

void ListDelLast(List* l, ListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    if (ListFirstElement(*l) == ListLastElement(*l)) {
        ListDelFirst(l, x);
    } else {
        ListTraversal (p, ListFirstElement(*l),
            ListElementNext(p) != ListLastElement(*l)) {}
        ListDelAfter(l, x, p);
    }
}

ListElement* ListSearch(List l, ListVal_t x) {
    /*
    Mengembalikan pointer ke ListElement dengan value x jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */
    /*
    Mengembalikan banyak elemen dalam l
    */
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    if (ListIsEmpty(l)) {
        return Nil;
    } else {
        ListTraversal (p, ListFirstElement(l),
            ListElementNext(p) != Nil && ListElementVal(p) != x) {}
        if (ListElementVal(p) == x) {
            return p;
        } else {
            return 0;
        }
    }
}
