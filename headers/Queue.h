#ifndef _QUEUE_H
#define _QUEUE_H

#include "LinkedList.h"

typedef LinkedListVal_t QueueVal_t;
typedef LinkedListElement QueueElement;
typedef LinkedList Queue;

#define QueueHead(q) LinkedListFirstElement(q)
#define QueueTail(q) LinkedListLastElement(q)
#define QueueValueHead(q) LinkedListValueFirst(q)
#define QueueValueTail(q) LinkedListValueLast(q)

bool QueueIsEmpty(Queue q);
void QueueAdd(Queue* q, QueueVal_t x);
void QueueDel(Queue* q, QueueVal_t* x);

#endif
