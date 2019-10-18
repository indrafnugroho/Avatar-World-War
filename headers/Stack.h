/*
Stack.h
DEFINISI ADT STACK <Stack>
Stack adalah varian dari List dengan penyisipan  dan penghapusan hanya
dilakukan dari elemen pertama (Top).
*/

#ifndef _STACK_H
#define _STACK_H

#include "List.h"
#include "bool.h"

typedef ListVal_t StackVal_t;
typedef ListElement StackElement;
typedef List Stack;

#define StackTop(s) ListFirstElement(s)
#define StackValueTop(s) ListValueFirst(s)

bool StackIsEmpty(Stack s);
void StackPush(Stack* s, StackVal_t x);
void StackPop(Stack* s, StackVal_t* x);

#endif
