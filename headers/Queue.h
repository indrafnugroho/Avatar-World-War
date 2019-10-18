/*
Queue.h
DEFINISI ADT QUEUE <Queue>
Queue adalah varian dari List dengan penyisipan hanya dilakukan dari elemen
terakhir (Tail) dan penghapusan hanya dilakukan dari elemen pertama (Head).
*/

#ifndef _QUEUE_H
#define _QUEUE_H

#include "List.h"

typedef ListVal_t QueueVal_t;
typedef ListElement QueueElement;
typedef List Queue;

#define QueueHead(q) ListFirstElement(q)
#define QueueTail(q) ListLastElement(q)
#define QueueValueHead(q) ListValueFirst(q)
#define QueueValueTail(q) ListValueLast(q)

bool QueueIsEmpty(Queue q);
void QueueAdd(Queue* q, QueueVal_t x);
void QueueDel(Queue* q, QueueVal_t* x);

#endif
