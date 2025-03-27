#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef LinkedList Queue;

// Konstruktor
Queue createQueue();
void destroyQueue(Queue *q);

// Operasi dasar Queue
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
boolean isEmptyQueue(Queue q);
void displayQueue(Queue q);

#endif 
