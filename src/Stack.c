#include "Stack.h"

bool StackIsEmpty(Stack s) {
    return ListIsEmpty(s);
}

void StackPush(Stack* s, StackVal_t x) {
    ListAddFirst(s, x);
}

void StackPop(Stack* s, StackVal_t* x) {
    ListDelFirst(s, x);
}
