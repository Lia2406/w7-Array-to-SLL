#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Fungsi untuk memasukkan elemen ke stack
void push(LinkedList* stack, int nilai) {
    sisipAwal(stack, nilai);
}

// Fungsi untuk mengeluarkan elemen dari stack
void pop(LinkedList* stack) {
    hapusAwal(stack);
}

// Fungsi untuk menampilkan isi stack
void tampilkanStack(LinkedList* stack) {
    tampilkanDaftar(stack);
}

// Fungsi untuk mengecek stack kosong
boolean isEmptyStack(LinkedList stack) {
    return isEmpty(stack);
} 
