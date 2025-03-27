#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

// Deklarasi fungsi stack
void push(LinkedList* stack, int nilai);
void pop(LinkedList* stack);
void tampilkanStack(LinkedList* stack);
boolean isEmptyStack(LinkedList stack);

#endif // STACK_H 
