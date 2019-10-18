#include "LinkedList.h"
#include <stdlib.h>

LinkedListElement* LinkedListElementAlloc(LinkedListVal_t x) {
    /* Kamus Lokal */
    LinkedListElement* p;
    /* Algoritma */
    p = (LinkedListElement*) malloc(sizeof(LinkedListElement));
    if (p != Nil) LinkedListElementVal(p) = x;
    return p;
}

bool LinkedListIsEmpty(LinkedList l) {
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */
    return (LinkedListFirstElement(l) == Nil) && (LinkedListLastElement(l) == Nil);
}

int LinkedListSize(LinkedList l) {
    /*
    Mengembalikan banyak elemen dalam l
    */
    LinkedListElement* p;
    int count;
    if (LinkedListIsEmpty(l)) {
        return 0;
    } else {
        count = 0;
        p = LinkedListFirstElement(l);
        while (p != Nil) {
            p = LinkedListElementNext(p);
            count++;
        }
        return count;
    }
}

void LinkedListAddFirst(LinkedList* l, LinkedListVal_t x) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */
    /* Kamus lokal */
    LinkedListElement* p;
    /* Algoritma */
    p = LinkedListElementAlloc(x);
    if (LinkedListIsEmpty(*l)) {
        LinkedListElementNext(p) = Nil;
        LinkedListFirstElement(*l) = p;
        LinkedListLastElement(*l) = p;
    } else {
        LinkedListElementNext(p) = LinkedListFirstElement(*l);
        LinkedListFirstElement(*l) = p;
    }
}

void LinkedListAddLast(LinkedList* l, LinkedListVal_t x) {
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */
    /* Kamus lokal */
    LinkedListElement* p;
    /* Algoritma */
    p = LinkedListElementAlloc(x);
    LinkedListElementNext(p) = Nil;
    if (LinkedListIsEmpty(*l)) {
        LinkedListFirstElement(*l) = p;
        LinkedListLastElement(*l) = p;
    } else {
        LinkedListElementNext(LinkedListLastElement(*l)) = p;
        LinkedListLastElement(*l) = p;
    }
}

void LinkedListDelFirst(LinkedList* l, LinkedListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */
    LinkedListElement* p;
    /* Algoritma */
    p = LinkedListFirstElement(*l);
    *x = LinkedListElementVal(p);
    if (LinkedListFirstElement(*l) == LinkedListLastElement(*l)) {
        LinkedListFirstElement(*l) = Nil;
        LinkedListLastElement(*l) = Nil;
    } else {
        LinkedListFirstElement(*l) = LinkedListElementNext(LinkedListFirstElement(*l));
    }
    free(p);
}

void LinkedListDelLast(LinkedList* l, LinkedListVal_t* x) {
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */
    LinkedListElement* p;
    LinkedListElement* plast;
    /* Algoritma */
    plast = LinkedListLastElement(*l);
    *x = LinkedListElementVal(p);
    if (LinkedListFirstElement(*l) == plast) {
        LinkedListFirstElement(*l) = Nil;
        LinkedListLastElement(*l) = Nil;
    } else {
        p = LinkedListFirstElement(*l);
        while (LinkedListElementNext(p) != LinkedListLastElement(*l)) {
            p = LinkedListElementNext(p);
        }
        LinkedListElementNext(p) = Nil;
    }
    free(plast);
}

LinkedListElement* LinkedListSearch(LinkedList l, LinkedListVal_t x) {
    /*
    Mengembalikan pointer ke LinkedListElement dengan value x jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */
    /*
    Mengembalikan banyak elemen dalam l
    */
    LinkedListElement* p;
    int count;
    if (LinkedListIsEmpty(l)) {
        return Nil;
    } else {
        p = LinkedListFirstElement(l);
        while (LinkedListElementNext(p) != Nil && LinkedListElementVal(p) != x) {
            p = LinkedListElementNext(p);
        }
        if (LinkedListElementVal(p) != x) {
            return p;
        } else {
            return 0;
        }
    }
}
