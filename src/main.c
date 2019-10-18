/* main.c */

#include <stdio.h>
#include "bool.h"
#include "List.h"

void printlist(List l) {
    ListElement* p = ListFirstElement(l);
    if(!ListIsEmpty(l)) {
        printf("<");
        while (p != Nil) {
            printf("%d, ", (int) ListElementVal(p));
            p = ListElementNext(p);
        }
        printf("> %d %d\n",  ListValueFirst(l), ListValueLast(l));
    } else {
        printf("List Kosong");
    }
}

int main() {
    int i, x;
    List list;
    ListCreate(&list);
    for (i = 0; i < 10; i++) {
        ListAddFirst(&list, i);
        printlist(list);
    }
    for (i = 10; i < 20; i++) {
        ListAddLast(&list, i);
        printlist(list);
    }
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
