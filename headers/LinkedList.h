#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "bool.h"

#define Nil 0

typedef void* LinkedListVal_t;

/* Definisi Elemen List Linier / LinkedListElement */
typedef struct LinkedListElement LinkedListElement;
struct LinkedListElement {
    LinkedListVal_t value;
    LinkedListElement* next;
};

/* Selektor */
#define LinkedListElementVal(p) (p)->value
#define LinkedListElementNext(p) (p)->next

LinkedListElement* LinkedListElementAlloc(LinkedListVal_t x);
    /*
    Mengembalikan pointer yang menunjuk ke LinkedListElement yang dialokasi dengan nilai x.
    */

/* Definisi List Linier / LinkedList */
typedef struct {
    LinkedListElement* first;
    LinkedListElement* last;
} LinkedList;

#define LinkedListFirstElement(l) (l).first

#define LinkedListLastElement(l) (l).last

bool LinkedListIsEmpty(LinkedList l);
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */

int LinkedListSize(LinkedList l);
    /*
    Mengembalikan banyak elemen dalam l
    */

void LinkedListAddFirst(LinkedList* l, LinkedListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */

void LinkedListAddLast(LinkedList* l, LinkedListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */

void LinkedListDelFirst(LinkedList* l, LinkedListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */

void LinkedListDelLast(LinkedList* l, LinkedListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */

LinkedListElement* LinkedListSearch(LinkedList l, LinkedListVal_t x);
    /*
    Mengembalikan pointer ke LinkedListElement dengan value x jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */

#endif
