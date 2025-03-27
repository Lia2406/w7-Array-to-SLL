#include "kota.h"

// Definisi variabel global
City cities[MAX_CITIES];
int cityCount;
Stack historyStack;
Queue additionQueue;

// Inisialisasi data
void initData() {
    cityCount = 0;
    historyStack.top = NULL;
    additionQueue.front = NULL;
    additionQueue.rear = NULL;
}

// Mencari indeks kota dalam array
int cariKota(const char* kota) {
    for (int i = 0; i < cityCount; i++) {
        if (strcmp(cities[i].name, kota) == 0) {
            return i;
        }
    }
    return -1;
}

// Mencari nama dalam kota tertentu
int cariNama(const char* kota, const char* nama) {
    int idxKota = cariKota(kota);
    if (idxKota == -1) return 0;
    
    Node* current = cities[idxKota].head;
    while (current != NULL) {
        if (strcmp(current->name, nama) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Menambahkan nama ke dalam kota
void tambahNama(const char* kota, const char* nama) {
    int idxKota = cariKota(kota);
    
    // Jika kota belum ada, tambahkan kota baru
    if (idxKota == -1) {
        if (cityCount >= MAX_CITIES) {
            printf("Jumlah kota sudah mencapai batas maksimum!\n");
            return;
        }
        strcpy(cities[cityCount].name, kota);
        cities[cityCount].head = NULL;
        idxKota = cityCount++;
    }
    
    // Cek apakah nama sudah ada
    if (cariNama(kota, nama)) {
        printf("Nama sudah ada dalam kota tersebut!\n");
        return;
    }
    
    // Buat node baru
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, nama);
    newNode->next = NULL;
    
    // Tambahkan ke linked list
    if (cities[idxKota].head == NULL) {
        cities[idxKota].head = newNode;
    } else {
        Node* current = cities[idxKota].head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    // Tambahkan ke queue
    enqueueQueue(nama);
    
    printf("Nama berhasil ditambahkan!\n");
}

// Menghapus nama dari kota
void hapusNama(const char* kota, const char* nama) {
    int idxKota = cariKota(kota);
    if (idxKota == -1) {
        printf("Kota tidak ditemukan!\n");
        return;
    }
    
    Node* current = cities[idxKota].head;
    Node* prev = NULL;
    
    while (current != NULL) {
        if (strcmp(current->name, nama) == 0) {
            if (prev == NULL) {
                cities[idxKota].head = current->next;
            } else {
                prev->next = current->next;
            }
            
            // Simpan ke stack sebelum menghapus
            pushStack(current->name);
            free(current);
            printf("Nama berhasil dihapus!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    
    printf("Nama tidak ditemukan dalam kota tersebut!\n");
}

// Menghapus kota dan semua namanya
void hapusKota(const char* kota) {
    int idxKota = cariKota(kota);
    if (idxKota == -1) {
        printf("Kota tidak ditemukan!\n");
        return;
    }
    
    // Hapus semua nama dalam kota
    Node* current = cities[idxKota].head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        pushStack(temp->name);
        free(temp);
    }
    
    // Geser array kota
    for (int i = idxKota; i < cityCount - 1; i++) {
        cities[i] = cities[i + 1];
    }
    cityCount--;
    
    printf("Kota berhasil dihapus!\n");
}

// Menampilkan semua data
void tampilkanData() {
    if (cityCount == 0) {
        printf("Belum ada data kota!\n");
        return;
    }
    
    printf("\nData Kota dan Nama:\n");
    for (int i = 0; i < cityCount; i++) {
        printf("\nKota: %s\n", cities[i].name);
        printf("Daftar Nama:\n");
        
        Node* current = cities[i].head;
        if (current == NULL) {
            printf("  - (Kosong)\n");
        } else {
            while (current != NULL) {
                printf("  - %s\n", current->name);
                current = current->next;
            }
        }
    }
}

// Operasi Stack
void pushStack(const char* nama) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, nama);
    newNode->next = historyStack.top;
    historyStack.top = newNode;
}

char* popStack() {
    if (historyStack.top == NULL) {
        return NULL;
    }
    
    Node* temp = historyStack.top;
    historyStack.top = temp->next;
    char* nama = strdup(temp->name);
    free(temp);
    return nama;
}

// Operasi Queue
void enqueueQueue(const char* nama) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, nama);
    newNode->next = NULL;
    
    if (additionQueue.rear == NULL) {
        additionQueue.front = newNode;
        additionQueue.rear = newNode;
    } else {
        additionQueue.rear->next = newNode;
        additionQueue.rear = newNode;
    }
}

char* dequeueQueue() {
    if (additionQueue.front == NULL) {
        return NULL;
    }
    
    Node* temp = additionQueue.front;
    additionQueue.front = temp->next;
    if (additionQueue.front == NULL) {
        additionQueue.rear = NULL;
    }
    
    char* nama = strdup(temp->name);
    free(temp);
    return nama;
}

// Membersihkan memori
void bersihkanMemori() {
    // Bersihkan linked list setiap kota
    for (int i = 0; i < cityCount; i++) {
        Node* current = cities[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    // Bersihkan stack
    while (historyStack.top != NULL) {
        Node* temp = historyStack.top;
        historyStack.top = temp->next;
        free(temp);
    }
    
    // Bersihkan queue
    while (additionQueue.front != NULL) {
        Node* temp = additionQueue.front;
        additionQueue.front = temp->next;
        free(temp);
    }
    additionQueue.rear = NULL;
} 