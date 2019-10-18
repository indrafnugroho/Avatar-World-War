#include "List.h"
#include <stdlib.h>

ListElement* ListElementAlloc(ListVal_t x) {
    /* Kamus Lokal */
    ListElement* p;
    /* Algoritma */
    p = (ListElement*) malloc(sizeof(ListElement));
    if (p != Nil) ListElementVal(p) = x;
    return p;
}

void ListCreate(List* l) {
    ListFirstElement(*l) = Nil;
    ListLastElement(*l) = Nil;
}


bool ListIsEmpty(List l) {
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */
    return (ListFirstElement(l) == Nil) && (ListLastElement(l) == Nil);
}

int ListSize(List l) {
    /*
    Mengembalikan banyak elemen dalam l
    */
    ListElement* p;
    int count;
    if (ListIsEmpty(l)) {
        return 0;
    } else {
        count = 0;
        p = ListFirstElement(l);
        while (p != Nil) {
            p = ListElementNext(p);
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
    if (ListIsEmpty(*l)) {
        ListElementNext(p) = Nil;
        ListFirstElement(*l) = p;
        ListLastElement(*l) = p;
    } else {
        ListElementNext(p) = ListFirstElement(*l);
        ListFirstElement(*l) = p;
    }
}

void ListAddLast(List* l, ListVal_t x) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */
    /* Kamus lokal */
    ListElement* p;
    /* Algoritma */
    p = ListElementAlloc(x);
    ListElementNext(p) = Nil;
    if (ListIsEmpty(*l)) {
        ListFirstElement(*l) = p;
        ListLastElement(*l) = p;
    } else {
        ListElementNext(ListLastElement(*l)) = p;
        ListLastElement(*l) = p;
    }
}

void ListDelFirst(List* l, ListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */
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

void ListDelLast(List* l, ListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */
    ListElement* p;
    ListElement* plast;
    /* Algoritma */
    plast = ListLastElement(*l);
    *x = ListElementVal(plast);
    if (ListFirstElement(*l) == plast) {
        ListFirstElement(*l) = Nil;
        ListLastElement(*l) = Nil;
    } else {
        p = ListFirstElement(*l);
        while (ListElementNext(p) != ListLastElement(*l)) {
            p = ListElementNext(p);
        }
        ListElementNext(p) = Nil;
        ListLastElement(*l) = p;
    }
    free(plast);
}

ListElement* ListSearch(List l, ListVal_t x) {
    /*
    Mengembalikan pointer ke ListElement dengan value x jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */
    /*
    Mengembalikan banyak elemen dalam l
    */
    ListElement* p;
    int count;
    if (ListIsEmpty(l)) {
        return Nil;
    } else {
        p = ListFirstElement(l);
        while (ListElementNext(p) != Nil && ListElementVal(p) != x) {
            p = ListElementNext(p);
        }
        if (ListElementVal(p) != x) {
            return p;
        } else {
            return 0;
        }
    }
}
