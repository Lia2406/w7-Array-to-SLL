#include "queue.h"

Queue createQueue() {
    Queue q;
    inisialisasiDaftar(&q);
    return q;
}

void destroyQueue(Queue *q) {
    hapusSemua(q);
}

void enqueue(Queue *q, int value) {
    sisipAkhir(q, value);
}

int dequeue(Queue *q) {
    int value = q->kepala->data;
    hapusAwal(q);
    return value;
}

boolean isEmptyQueue(Queue q) {
    return q.kepala == NULL;
}

void displayQueue(Queue q) {
    tampilkanDaftar(&q);
} 
