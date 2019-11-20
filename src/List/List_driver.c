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
    ListVal_t x;
    int i;

    bool success;
    ListCreate(&l1);
    printf("[List Driver]\n\nAdd 0..9 as first\n");
    for (i = 0; i < 10; i++) {
        ListAddFirst(&l1, i);
    }
    PrintList(l1);
    printf("\nAdd 10..19 as last\n");
    for (i = 10; i < 20; i++) {
        ListAddLast(&l1, i);
    }
    PrintList(l1);
    printf("\nAdd 100 after 15\n");
    ListAddAfter(&l1, 100, ListSearch(l1, 15));
    PrintList(l1);
    printf("\nDelete 7\n");
    ListDelVal(&l1, 7);
    PrintList(l1);
    printf("\nDelete Value after 11\n");
    ListDelAfter(&l1, &x, ListSearch(l1, 11));
    PrintList(l1);
    printf("    Deleted: %d\n", x);
    printf("\nDelete 8 Elements from first\n");
    for (i = 0; i < 8; i++) {
        ListDelFirst(&l1, &x);
    }
    PrintList(l1);
    printf("\nDelete 10 Elements from last\n");
    for (i = 0; i < 10; i++) {
        ListDelLast(&l1, &x);
    }
    PrintList(l1);

    return 0;
}
