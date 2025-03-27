#include "kota.h"

void tampilkanMenu() {
    printf("\nMenu Program:\n");
    printf("1. Tambah Nama ke Kota\n");
    printf("2. Hapus Nama dari Kota\n");
    printf("3. Hapus Kota\n");
    printf("4. Tampilkan Data\n");
    printf("5. Keluar\n");
    printf("Pilih menu (1-5): ");
}

void prosesMenu(int pilihan) {
    char kota[MAX_NAME_LENGTH];
    char nama[MAX_NAME_LENGTH];
    
    switch (pilihan) {
        case 1:
            printf("Masukkan nama kota: ");
            fgets(kota, MAX_NAME_LENGTH, stdin);
            kota[strcspn(kota, "\n")] = 0;
            
            printf("Masukkan nama: ");
            fgets(nama, MAX_NAME_LENGTH, stdin);
            nama[strcspn(nama, "\n")] = 0;
            
            tambahNama(kota, nama);
            break;
            
        case 2:
            printf("Masukkan nama kota: ");
            fgets(kota, MAX_NAME_LENGTH, stdin);
            kota[strcspn(kota, "\n")] = 0;
            
            printf("Masukkan nama yang akan dihapus: ");
            fgets(nama, MAX_NAME_LENGTH, stdin);
            nama[strcspn(nama, "\n")] = 0;
            
            hapusNama(kota, nama);
            break;
            
        case 3:
            printf("Masukkan nama kota yang akan dihapus: ");
            fgets(kota, MAX_NAME_LENGTH, stdin);
            kota[strcspn(kota, "\n")] = 0;
            
            hapusKota(kota);
            break;
            
        case 4:
            tampilkanData();
            break;
            
        case 5:
            printf("Terima kasih telah menggunakan program ini!\n");
            break;
            
        default:
            printf("Pilihan tidak valid!\n");
    }
}

int main() {
    int pilihan;
    
    // Inisialisasi data
    initData();
    
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // Mengambil karakter newline
        
        prosesMenu(pilihan);
        
        if (pilihan != 5) {
            printf("\nTekan Enter untuk melanjutkan...");
            getchar();
            getchar(); // Mengambil karakter newline
        }
        
    } while (pilihan != 5);
    
    // Membersihkan memori sebelum keluar
    bersihkanMemori();
    
    return 0;
} 