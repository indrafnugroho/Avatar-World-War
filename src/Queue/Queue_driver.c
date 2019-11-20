#include "Queue.h"
#include <stdio.h>

int main() {
    Queue q1;
    QueueVal_t x;
    int i;

    printf("[Queue Driver]\n\n");
    QueueCreate(&q1);
    for (i = 0; i < 10; i++) {
        printf("Adding %d to Queue\n", i);
        QueueAdd(&q1, i);
    }
    while (!QueueIsEmpty(q1)) {
        QueueDel(&q1, &x);
        printf("Removing from Queue, get %d\n", x);
    }
}
