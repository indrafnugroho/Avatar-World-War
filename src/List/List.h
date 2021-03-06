/*
List.h
DEFINISI ADT LIST LINIER <List>
List adalah list berkait satu arah.
*/

#ifndef _LIST_H
#define _LIST_H

#include "bool/bool.h"

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

/* Makro traversal list */
#define ListTraversal(p, expinit, exploop) for (p = expinit; exploop; p = ListElementNext(p))

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
void ListElAddFirst(List* l, ListElement* p);
    /*
    I.S.
        l terdefinisi, boleh kosong, p teralokasi
    F.S.
        Elemen p diletakkan di depan l, menjadi first
    */

void ListElAddAfter(List* l, ListElement* p, ListElement* prec);
    /*
    I.S.
        l terdefinisi, tidak kosong.
        p teralokasi.
        prec != Nil dan berada pada l.
    F.S.
        Elemen p diletakkan setelah prec
    */

void ListElAddLast(List* l, ListElement* p);
    /*
    I.S.
        l terdefinisi, boleh kosong.
    F.S.
        Elemen p diletakkan di belakang l, menjadi last
    */

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
void ListElDelFirst(List* l, ListElement** p);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen first(l) dihapus dan menjadi elemen p
    */


void ListElDelAfter(List* l, ListElement** p, ListElement* prec);
    /*
    I.S.
        l tidak kosong, prec != Nil dan berada pada l
    F.S.
        Elemen suksesor prec dihapus dan menjadi p.
        Jika suksesor adalah last(l), last(l) = prec
    */

void ListElDel(List* l, ListElement* p);
    /*
    I.S.
        l tidak kosong.
        p pasti berada di dalam l
    F.S.
        Elemen p dihapus dari l.
    */

void ListElDelLast(List* l, ListElement** p);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan menjadi p.
    */

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

void ListDelVal(List* l, ListVal_t x);
    /*
    I.S.
        l tidak kosong.
    F.S.
        Jika ada elemen bernilai x di l, hapus n. Jika tidak ada, tidak terjadi
        apa-apa.
    */

void ListDelLast(List* l, ListVal_t* x);
    /*
    I.S.
        l tidak kosong
    F.S.
        Elemen last(l) dihapus dan nilainya dimasukkan ke x
    */

/* Pencarian */
ListElement* ListSearch(List l, ListVal_t x);
    /*
    Mengembalikan pointer ke ListElement dengan value x paling awal jika ada,
    mengambelikan Nil jika tidak ditemukan.
    */

List CopyList(List L);
    /* Menyalin List */

ListElement* ListIdx(List L, int idx);
    /* Menngembalikan pointer ke ListElement pada urutan ke-idx pada list L */
    /* Prekondisi: 0 =< idx < ListSize(L) */

int ListGetIdx(List L, ListElement* p);
    /* Mengembalikan indeks p pada l */
    /* Prekondisi: p ada di l */

#endif
