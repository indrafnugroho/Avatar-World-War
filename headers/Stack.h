#ifndef _STACK_H
#define _STACK_H

#include "LinkedList.h"
#include "bool.h"

typedef LinkedListVal_t StackVal_t;
typedef LinkedListElement StackElement;
typedef LinkedList Stack;

#define StackTop(s) LinkedListFirstElement(s)
#define StackValueTop(s) LinkedListValueFirst(s)

bool StackIsEmpty(Stack s);
void StackPush(Stack* s, StackVal_t x);
void StackPop(Stack* s, StackVal_t* x);

#endif
