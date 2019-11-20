#include "Stack.h"
#include <stdio.h>

int main() {
    Stack q1;
    StackVal_t x;
    int i;

    printf("[Stack Driver]\n\n");
    StackCreate(&q1);
    for (i = 0; i < 10; i++) {
        printf("Pushing %d to Stack\n", i);
        StackPush(&q1, i);
    }
    while (!StackIsEmpty(q1)) {
        StackPop(&q1, &x);
        printf("Popping from Stack, get %d\n", x);
    }
}
