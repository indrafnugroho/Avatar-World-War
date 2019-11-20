#include "List.h"
#include <stdio.h>

void PrintList(List l) {
    ListElement* p;
    printf("<");
    if (!ListIsEmpty(l)) {
        ListTraversal(p, ListFirstElement(l), p != Nil) {
            printf("%d,", ListElementVal(p));
        }
        printf("\b");
    }
    printf(">\n");
}

int main() {
    List l1, l2;
    int x, i;
    bool success;
    ListCreate(&l1);
    for (i = 0; i < 10; i++) {
        ListAddFirst(&l1, i);
    }
    PrintList(l1);
    for (i = 10; i < 20; i++) {
        ListAddLast(&l1, i);
    }
    PrintList(l1);
    ListAddAfter(&l1, 100, ListSearch(l1, 15));
    PrintList(l1);
    ListDelVal(&l1, 7, success);
    PrintList(l1);
    ListDelAfter(&l1, ListSearch(l1, 11), &x);
    PrintList(l1);
    return 0;
}
