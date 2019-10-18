#ifndef _List_H
#define _List_H

#include "bool.h"

#define Nil 0

typedef int ListVal_t;

/* Definisi Elemen List Linier / ListElement */
typedef struct ListElement ListElement;
struct ListElement {
    ListVal_t value;
    ListElement* next;
};

/* Selektor */
#define ListElementVal(p) (p)->value
#define ListElementNext(p) (p)->next

ListElement* ListElementAlloc(ListVal_t x);
    /*
    Mengembalikan pointer yang menunjuk ke ListElement yang dialokasi dengan nilai x.
    */

/* Definisi List Linier / List */
typedef struct {
    ListElement* first;
    ListElement* last;
} List;

#define ListFirstElement(l) (l).first
#define ListLastElement(l) (l).last
#define ListValueFirst(l) (l).first->value
#define ListValueLast(l) (l).last->value

void ListCreate(List* l);


bool ListIsEmpty(List l);
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */

int ListSize(List l);
    /*
    Mengembalikan banyak elemen dalam l
    */

void ListAddFirst(List* l, ListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */

void ListAddLast(List* l, ListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */

void ListDelFirst(List* l, ListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */

void ListDelLast(List* l, ListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */

ListElement* ListSearch(List l, ListVal_t x);
    /*
    Mengembalikan pointer ke ListElement dengan value x jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */

#endif
