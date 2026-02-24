#include <stdio.h>
#include <string.h>

int main() {
    // Data menu
    char menu[5][30] = {
        "Nasi Goreng Spesial",
        "Ayam Penyet",
        "Sate Ayam",
        "Bakso Urat",
        "Mie Ayam"
    };

    int harga[5] = {25000, 30000, 28000, 22000, 20000};

    int pilihan[10], porsi[10];
    int totalItem[10];
    int jumlahPesanan, i;

    int totalBayar = 0;
    float diskon = 0;

    printf("=== DAFTAR MENU ===\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - %d\n", i + 1, menu[i], harga[i]);
    }

    printf("\nJumlah pesanan: ");
    scanf("%d", &jumlahPesanan);

    for (i = 0; i < jumlahPesanan; i++) {
        printf("\nPesanan ke-%d\n", i + 1);

        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan[i]);

        printf("Jumlah porsi: ");
        scanf("%d", &porsi[i]);

        totalItem[i] = harga[pilihan[i] - 1] * porsi[i];
        totalBayar += totalItem[i];
    }

    // Logika diskon
    if (totalBayar >= 500000)
        diskon = 0.25;
    else if (totalBayar >= 400000)
        diskon = 0.20;
    else if (totalBayar >= 300000)
        diskon = 0.15;
    else if (totalBayar >= 200000)
        diskon = 0.10;
    else if (totalBayar >= 100000)
        diskon = 0.05;

    int potongan = totalBayar * diskon;
    int totalAkhir = totalBayar - potongan;

    // Cetak struk
    printf("\n==============================================\n");
    printf("Menu                     Porsi   Harga   Total\n");
    printf("==============================================\n");

    for (i = 0; i < jumlahPesanan; i++) {
        printf("%-24s %3d %8d %8d\n",
            menu[pilihan[i] - 1],
            porsi[i],
            harga[pilihan[i] - 1],
            totalItem[i]);
    }

    printf("==============================================\n");
    printf("Total Pembayaran : %d\n", totalBayar);
    printf("Diskon           : %d\n", potongan);
    printf("Total Akhir      : %d\n", totalAkhir);

    return 0;
}