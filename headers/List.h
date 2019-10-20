/*
List.h
DEFINISI ADT LIST LINIER <List>
List adalah list berkait satu arah.
*/

#ifndef _LIST_H
#define _LIST_H

#include "bool.h"

#define Nil 0

typedef void* ListVal_t;

/* Definisi Elemen List Linier / ListElement */
typedef struct ListElement ListElement;
struct ListElement {
    ListVal_t value;
    ListElement* next;
};

/* Selektor */
#define ListElementVal(p) (p)->value
#define ListElementNext(p) (p)->next

/* Primitif */
ListElement* ListElementAlloc(ListVal_t x);
    /*
    Mengembalikan pointer yang menunjuk ke ListElement yang dialokasi dengan nilai x.
    */

/* Definisi List Linier / List */
typedef struct {
    ListElement* first;
    ListElement* last;
} List;

/* Selektor */
#define ListFirstElement(l) (l).first
#define ListLastElement(l) (l).last
#define ListValueFirst(l) (l).first->value
#define ListValueLast(l) (l).last->value

/* Primitif */
void ListCreate(List* l);
    /*
    I.S.
        l sembarang.
    F.S.
        l merupakan list terdefinisi denga first(l) dan last(l) menunjuk ke Nil.
    */

bool ListIsEmpty(List l);
    /*
    Mengembalikan true jika l kosong (first dan last menunjuk ke Nil)
    */

int ListSize(List l);
    /*
    Mengembalikan banyak elemen dalam l
    */

/* Tambah Elemen */
void ListAddFirst(List* l, ListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di depan l, menjadi first
    */

void ListAddAfter(List* l, ListVal_t x, ListElement* prec);
    /*
    I.S.
        l terdefinisi, tidak kosong.
        prec != Nil dan berada pada l
    F.S.
        Elemen bernilai x diletakkan setelah prec
    */

void ListAddLast(List* l, ListVal_t x);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen bernilai x diletakkan di belakang l, menjadi last
    */

/* Hapus Elemen */
void ListDelFirst(List* l, ListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan nilainya dimasukkan ke x
    */


void ListDelAfter(List* l, ListVal_t* x, ListElement* prec);
    /*
    I.S.
        l tidak kosong, prec != Nil dan berada pada l
    F.S.
        Elemen suksesor prec dihapus dan nilainya dimasukkan ke x.
        Jika suksesor adalah last(l), last(l) = prec
    */

void ListDelVal(List* l, ListVal_t x, bool success);
    /*
    I.S.
        l tidak kosong.
    F.S.
        Jika ada elemen bernilai x di l, hapus n dan success bernilai true.
        Jika tidak ada, success bernilai false.
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
