#include "Queue.h"

bool QueueIsEmpty(Queue q) {
    return LinkedListIsEmpty(q);
}

void QueuePush(Queue* q, QueueVal_t x) {
    LinkedListAddLast(q, x);
}

void QueuePop(Queue* q, QueueVal_t* x) {
    LinkedListDelFirst(q, x);
}
