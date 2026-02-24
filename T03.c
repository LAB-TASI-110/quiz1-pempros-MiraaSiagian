#include <stdio.h>
#include <string.h>

#define MAX_ASRAMA 5
#define MAX_MINGGU 10

/* ================== ENUM STATUS ================== */
typedef enum {
    BELUM_DIJEMPUT = 0,
    DIJEMPUT = 1,
    DIKEMBALIKAN = 2
} StatusLaundry;

/* ================== STRUCT DATA ================== */
typedef struct {
    int baju;
    int celana;
    int jaket;
    int handuk;
} ItemLaundry;

typedef struct {
    int mingguKe;
    ItemLaundry item;
    StatusLaundry status;
} LaundryMingguan;

typedef struct {
    char nama[30];
    LaundryMingguan laundry[MAX_MINGGU];
    int jumlahLaundry;
} Asrama;

/* ================== VARIABEL GLOBAL ================== */
Asrama daftarAsrama[MAX_ASRAMA];
int jumlahAsrama = 0;

/* ================== FUNGSI BANTU ================== */
void tampilkanStatus(StatusLaundry status) {
    if (status == BELUM_DIJEMPUT) printf("Belum Dijemput");
    else if (status == DIJEMPUT) printf("Dijemput");
    else if (status == DIKEMBALIKAN) printf("Dikembalikan");
}

/* ================== TAMBAH ASRAMA ================== */
void tambahAsrama() {
    if (jumlahAsrama >= MAX_ASRAMA) {
        printf("Kapasitas asrama penuh.\n");
        return;
    }

    printf("Nama Asrama: ");
    scanf(" %[^\n]", daftarAsrama[jumlahAsrama].nama);

    daftarAsrama[jumlahAsrama].jumlahLaundry = 0;
    jumlahAsrama++;

    printf("Asrama berhasil ditambahkan.\n");
}

/* ================== INPUT LAUNDRY ================== */
void inputLaundry() {
    int idx;

    if (jumlahAsrama == 0) {
        printf("Belum ada asrama.\n");
        return;
    }

    printf("Pilih Asrama:\n");
    for (int i = 0; i < jumlahAsrama; i++) {
        printf("%d. %s\n", i + 1, daftarAsrama[i].nama);
    }
    scanf("%d", &idx);
    idx--;

    Asrama *a = &daftarAsrama[idx];

    if (a->jumlahLaundry >= MAX_MINGGU) {
        printf("Data laundry mingguan penuh.\n");
        return;
    }

    LaundryMingguan *l = &a->laundry[a->jumlahLaundry];

    printf("Minggu ke: ");
    scanf("%d", &l->mingguKe);

    printf("Jumlah Baju   : ");
    scanf("%d", &l->item.baju);
    printf("Jumlah Celana : ");
    scanf("%d", &l->item.celana);
    printf("Jumlah Jaket  : ");
    scanf("%d", &l->item.jaket);
    printf("Jumlah Handuk : ");
    scanf("%d", &l->item.handuk);

    l->status = BELUM_DIJEMPUT;
    a->jumlahLaundry++;

    printf("Data laundry berhasil dicatat.\n");
}

/* ================== UBAH STATUS ================== */
void ubahStatus() {
    int aIdx, lIdx;

    if (jumlahAsrama == 0) {
        printf("Belum ada data.\n");
        return;
    }

    printf("Pilih Asrama:\n");
    for (int i = 0; i < jumlahAsrama; i++) {
        printf("%d. %s\n", i + 1, daftarAsrama[i].nama);
    }
    scanf("%d", &aIdx);
    aIdx--;

    Asrama *a = &daftarAsrama[aIdx];

    if (a->jumlahLaundry == 0) {
        printf("Belum ada laundry mingguan.\n");
        return;
    }

    printf("Pilih Laundry Mingguan:\n");
    for (int i = 0; i < a->jumlahLaundry; i++) {
        printf("%d. Minggu %d (", i + 1, a->laundry[i].mingguKe);
        tampilkanStatus(a->laundry[i].status);
        printf(")\n");
    }
    scanf("%d", &lIdx);
    lIdx--;

    /* Transisi status BERURUTAN (AMAN) */
    switch (a->laundry[lIdx].status) {
        case BELUM_DIJEMPUT:
            a->laundry[lIdx].status = DIJEMPUT;
            printf("Status diubah menjadi Dijemput.\n");
            break;
        case DIJEMPUT:
            a->laundry[lIdx].status = DIKEMBALIKAN;
            printf("Status diubah menjadi Dikembalikan.\n");
            break;
        case DIKEMBALIKAN:
            printf("Laundry sudah dikembalikan.\n");
            break;
    }
}

/* ================== LAPORAN ================== */
void tampilkanLaporan() {
    if (jumlahAsrama == 0) {
        printf("Belum ada data.\n");
        return;
    }

    for (int i = 0; i < jumlahAsrama; i++) {
        Asrama *a = &daftarAsrama[i];
        printf("\nAsrama: %s\n", a->nama);

        for (int j = 0; j < a->jumlahLaundry; j++) {
            LaundryMingguan *l = &a->laundry[j];
            printf(" Minggu %d | Baju:%d Celana:%d Jaket:%d Handuk:%d | Status: ",
                   l->mingguKe,
                   l->item.baju,
                   l->item.celana,
                   l->item.jaket,
                   l->item.handuk);
            tampilkanStatus(l->status);
            printf("\n");
        }
    }
}

/* ================== MAIN ================== */
int main() {
    int menu;

    do {
        printf("\n=== SISTEM LAUNDRY ASRAMA ===\n");
        printf("1. Tambah Asrama\n");
        printf("2. Input Laundry Mingguan\n");
        printf("3. Ubah Status Laundry\n");
        printf("4. Tampilkan Laporan\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahAsrama(); break;
            case 2: inputLaundry(); break;
            case 3: ubahStatus(); break;
            case 4: tampilkanLaporan(); break;
            case 0: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (menu != 0);

    return 0;
}