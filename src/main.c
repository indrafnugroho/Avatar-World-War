/* main.c */

#include <stdio.h>
#include "bool.h"
#include "List.h"

void printlist(List l) {
    ListElement* p;
    if(!ListIsEmpty(l)) {
        printf("<");
        ListTraversal(p, ListFirstElement(l), p != Nil) {
            printf("%d, ", (int) ListElementVal(p));
        }
        printf("> %d %d\n",  ListValueFirst(l), ListValueLast(l));
    } else {
        printf("List Kosong");
    }
}

int main() {
    int i;
    ListVal_t x;
    List list;
    ListElement* k;
    ListCreate(&list);
    for (i = 0; i < 10; i++) {
        ListAddFirst(&list, i);
        printlist(list);
    }
    for (i = 10; i < 20; i++) {
        ListAddLast(&list, i);
        printlist(list);
    }
    k = ListSearch(list, 13);
    printf("[%d]", ListElementVal(k));
    ListAddAfter(&list, 9000, k);
    printlist(list);
    printf("\n>>%d<<\n", ListSize(list));
    k = ListSearch(list, 4);
    printf("[%d]", ListElementVal(k));
    ListDelAfter(&list, &x, k);
    printlist(list);
    for (i = 0; i < 8; i++) {
        ListDelFirst(&list, &x);
        printlist(list);
        printf("%d", x);
    }
    for (i = 0; i < 12; i++) {
        ListDelLast(&list, &x);
        printlist(list);
        printf("%d", x);
    }
    return 0;
}
