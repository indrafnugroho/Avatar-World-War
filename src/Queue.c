#include "Queue.h"

bool QueueIsEmpty(Queue q) {
    return ListIsEmpty(q);
}

void QueuePush(Queue* q, QueueVal_t x) {
    ListAddLast(q, x);
}

void QueuePop(Queue* q, QueueVal_t* x) {
    ListDelFirst(q, x);
}
