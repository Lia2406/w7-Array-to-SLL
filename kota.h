#ifndef KOTA_H
#define KOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 10
#define MAX_NAME_LENGTH 50

// Struktur untuk node Single Linked List
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

// Struktur untuk Stack
typedef struct Stack {
    Node* top;
} Stack;

// Struktur untuk Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Struktur untuk Kota
typedef struct City {
    char name[MAX_NAME_LENGTH];
    Node* head;
} City;

// Array global untuk menyimpan kota-kota
extern City cities[MAX_CITIES];
extern int cityCount;

// Stack global untuk menyimpan riwayat penghapusan
extern Stack historyStack;

// Queue global untuk menyimpan antrian penambahan
extern Queue additionQueue;

// Fungsi-fungsi dasar
void initData();
void tambahNama(const char* kota, const char* nama);
void hapusNama(const char* kota, const char* nama);
void hapusKota(const char* kota);
void tampilkanData();
void pushStack(const char* nama);
char* popStack();
void enqueueQueue(const char* nama);
char* dequeueQueue();

// Fungsi tambahan
int cariKota(const char* kota);
int cariNama(const char* kota, const char* nama);
void bersihkanMemori();

#endif 