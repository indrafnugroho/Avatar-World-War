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

void ListElAddFirst(List* l, ListElement* p) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */
    /* Algoritma */
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

void ListElAddAfter(List* l, ListElement* p, ListElement* prec) {
    /*
    I.S.
        l terdefinisi, tidak kosong.
        prec != Nil dan berada pada l
    F.S.
        Elemen bernilai x diletakkan setelah prec
    */
    /* Algoritma */
    ListElementNext(p) = ListElementNext(prec);
    ListElementNext(prec) = p;
    if (ListLastElement(*l) == prec) {
        ListLastElement(*l) = p;
    }
}

void ListElAddLast(List* l, ListElement* p) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */
    /* Algoritma */
    if (ListIsEmpty(*l)) {
        ListElAddFirst(l, p);
    } else {
        ListElAddAfter(l, p, ListLastElement(*l));
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
	ListElAddFirst(l, p);
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
	ListElAddAfter(l, p, prec);
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

void ListElDelFirst(List* l, ListElement** p) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan menjadi elemen p
    */
    /* Algoritma */
    *p = ListFirstElement(*l);
    if (ListFirstElement(*l) == ListLastElement(*l)) {
        ListFirstElement(*l) = Nil;
        ListLastElement(*l) = Nil;
    } else {
        ListFirstElement(*l) = ListElementNext(ListFirstElement(*l));
    }
}

void ListElDelAfter(List* l, ListElement** p, ListElement* prec) {
    /*
    I.S.
        l tidak kosong, prec != Nil dan berada pada l
    F.S.
        Elemen suksesor prec dihapus dan menjadi p.
        Jika suksesor adalah last(l), last(l) = prec
    */
    /* Algoritma */
    *p = ListElementNext(prec);
    ListElementNext(prec) = ListElementNext(*p);
    if (ListLastElement(*l) == *p) {
        ListLastElement(*l) = prec;
    } 
}

void ListElDel(List* l, ListElement* p) {
    /*
    I.S.
        l tidak kosong.
        p pasti berada di dalam l
    F.S.
        Elemen p dihapus dari l.
    */
    /* Kamus Lokal */
    ListElement* prec;
    ListElement* discard;
    /* Algoritma */
    prec = ListFirstElement(*l);
    if (prec == p) {
        ListElDelFirst(l, &discard);
    } else {
        ListTraversal (prec, ListFirstElement(*l),
            ListElementNext(prec) != p) {}
        ListElDelAfter(l, &discard, prec);
    }
}

void ListElDelLast(List* l, ListElement** p) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan menjadi p.
    */
    /* Kamus Lokal */
    ListElement* prec;	
    /* Algoritma */
    if (ListFirstElement(*l) == ListLastElement(*l)) {
        ListElDelFirst(l, p);
    } else {
        ListTraversal (prec, ListFirstElement(*l),
            ListElementNext(prec) != ListLastElement(*l)) {}
        ListElDelAfter(l, p, prec);
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
    ListElDelFirst(l, &p);
    *x = ListElementVal(p);
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
    ListElDelAfter(l, &p, prec);
    *x = ListElementVal(p);
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
    ListElDelLast(l, &p);
    *x = ListElementVal(p);
    free(p);
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

List CopyList(List l) {
    /* Menyalin List */
    /* Kamus Lokal */
    ListVal_t x;
    ListElement* p;
    List lout;
    /* Algoritma */
    ListCreate(&lout);
    ListTraversal(p, ListFirstElement(l), ListElementVal(p) != Nil) {
        ListAddLast(&lout, ListElementVal(p));
    }
    return lout;
}

