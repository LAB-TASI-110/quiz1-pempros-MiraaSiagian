#include <stdio.h>

int main() {
    int G;
    printf("Masukkan jumlah kelompok: ");
    scanf("%d", &G);

    int n[G];
    int total = 0;

    for (int i = 0; i < G; i++) {
        printf("Jumlah data kelompok %d: ", i + 1);
        scanf("%d", &n[i]);
        total += n[i];
    }

    int data[total];
    printf("\nMasukkan %d nilai:\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &data[i]);
    }

    int k;
    printf("\nMasukkan kode kelompok yang dicari: ");
    scanf("%d", &k);

    if (k < 1 || k > G) {
        printf("Kode kelompok tidak valid\n");
        return 0;
    }

    // hitung offset
    int start = 0;
    for (int i = 0; i < k - 1; i++) {
        start += n[i];
    }

    printf("\nNilai kelompok %d:\n", k);
    for (int i = start; i < start + n[k - 1]; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}