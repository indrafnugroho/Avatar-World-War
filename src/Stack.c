#include "Stack.h"

bool StackIsEmpty(Stack s) {
    return LinkedListIsEmpty(s);
}

void StackPush(Stack* s, StackVal_t x) {
    LinkedListAddFirst(s, x);
}

void StackPop(Stack* s, StackVal_t* x) {
    LinkedListDelFirst(s, x);
}
