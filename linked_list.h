#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

// Struktur Node
typedef struct Simpul {
    int data;
    struct Simpul* berikutnya;
} Simpul;

// Struktur Linked List
typedef struct {
    Simpul* kepala;
} LinkedList;

// Deklarasi Fungsi
void inisialisasiDaftar(LinkedList* list);
Simpul* buatSimpul(int nilai);
void sisipAwal(LinkedList* list, int nilai);
void sisipAkhir(LinkedList* list, int nilai);
void sisipSetelah(LinkedList* list, int setelahNilai, int nilai);
void hapusAwal(LinkedList* list);
void hapusAkhir(LinkedList* list);
void hapusNilai(LinkedList* list, int nilai);
void tampilkanDaftar(LinkedList* list);
void hapusSemua(LinkedList* list);
boolean isEmpty(LinkedList list);

#endif // LINKED_LIST_H
