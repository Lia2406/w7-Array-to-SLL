#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Fungsi untuk mengecek apakah linked list kosong
boolean isEmpty(LinkedList daftar) {
    return daftar.kepala == NULL;
}

// Inisialisasi daftar kosong
void inisialisasiDaftar(LinkedList* daftar) {
    daftar->kepala = NULL;
}

// Membuat simpul baru
Simpul* buatSimpul(int nilai) {
    Simpul* simpul = (Simpul*)malloc(sizeof(Simpul));
    if (simpul == NULL) {
        printf("Gagal mengalokasikan!\n");
        return NULL;
    }
    simpul->data = nilai;
    simpul->berikutnya = NULL;
    return simpul;
}

// Menyisipkan di awal daftar
void sisipAwal(LinkedList* daftar, int nilai) {
    Simpul* simpulBaru = buatSimpul(nilai);
    if (simpulBaru != NULL) {
        simpulBaru->berikutnya = daftar->kepala;
        daftar->kepala = simpulBaru;
    }
}

// Menyisipkan di akhir daftar
void sisipAkhir(LinkedList* daftar, int nilai) {
    Simpul* simpulBaru = buatSimpul(nilai);
    if (simpulBaru != NULL) {
        if (daftar->kepala == NULL) {
            daftar->kepala = simpulBaru;
        } else {
            Simpul* temp = daftar->kepala;
            while (temp->berikutnya != NULL) {
                temp = temp->berikutnya;
            }
            temp->berikutnya = simpulBaru;
        }
    }
}

// Menyisipkan setelah nilai tertentu
void sisipSetelah(LinkedList* daftar, int setelahNilai, int nilai) {
    Simpul* temp = daftar->kepala;
    while (temp != NULL && temp->data != setelahNilai) {
        temp = temp->berikutnya;
    }
    
    if (temp != NULL) {
        Simpul* simpulBaru = buatSimpul(nilai);
        if (simpulBaru != NULL) {
            simpulBaru->berikutnya = temp->berikutnya;
            temp->berikutnya = simpulBaru;
        }
    }
}

// Menghapus elemen pertama
void hapusAwal(LinkedList* daftar) {
    if (daftar->kepala != NULL) {
        Simpul* temp = daftar->kepala;
        daftar->kepala = daftar->kepala->berikutnya;
        free(temp);
    }
}

// Menghapus elemen terakhir
void hapusAkhir(LinkedList* daftar) {
    if (daftar->kepala != NULL) {
        if (daftar->kepala->berikutnya == NULL) {
            free(daftar->kepala);
            daftar->kepala = NULL;
        } else {
            Simpul* temp = daftar->kepala;
            while (temp->berikutnya->berikutnya != NULL) {
                temp = temp->berikutnya;
            }
            free(temp->berikutnya);
            temp->berikutnya = NULL;
        }
    }
}

// Menghapus elemen tertentu
void hapusNilai(LinkedList* daftar, int nilai) {
    Simpul* temp = daftar->kepala;
    Simpul* prev = NULL;
    
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->berikutnya;
    }
    
    if (temp != NULL) {
        if (prev == NULL) {
            daftar->kepala = temp->berikutnya;
        } else {
            prev->berikutnya = temp->berikutnya;
        }
        free(temp);
    }
}

// Menghapus semua elemen
void hapusSemua(LinkedList* daftar) {
    while (daftar->kepala != NULL) {
        hapusAwal(daftar);
    }
}

// Menampilkan daftar
void tampilkanDaftar(LinkedList* daftar) {
    Simpul* temp = daftar->kepala;
    while (temp != NULL) {
        printf("%d ", temp->data);  // Tambahkan spasi
        temp = temp->berikutnya;
    }
}


