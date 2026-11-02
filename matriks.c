#include <stdio.h>

#define MAKS 10

int main() {
    int A[MAKS][MAKS], B[MAKS][MAKS], C[MAKS][MAKS];
    int baris_A, kolom_A, baris_B, kolom_B;
    int i, j, k;
    char ulang;

    do {
        printf("\n=== PERKALIAN MATRIKS ===\n");

        printf("Masukkan jumlah baris dan kolom matriks A (Contoh: 3 3): ");
        scanf("%d %d", &baris_A, &kolom_A);
        printf("Masukkan jumlah baris dan kolom matriks B (Contoh: 3 3): ");
        scanf("%d %d", &baris_B, &kolom_B);
        
        if (kolom_A != baris_B) {
            printf("Perkalian tidak dapat dilakukan! Kolom A harus sama dengan baris B.\n");
        } else if (baris_A > MAKS || kolom_A > MAKS || baris_B > MAKS || kolom_B > MAKS) {
            printf("Ukuran matriks maksimal %d x %d.\n", MAKS, MAKS);
        } else {

            printf("\nMasukkan elemen matriks A:\n");
            for (i = 0; i < baris_A; i++) {
                for (j = 0; j < kolom_A; j++) {
                    printf("A[%d][%d] = ", i, j);
                    scanf("%d", &A[i][j]);
                }
            }
            printf("\nMasukkan elemen matriks B:\n");
            for (i = 0; i < baris_B; i++) {
                for (j = 0; j < kolom_B; j++) {
                    printf("B[%d][%d] = ", i, j);
                    scanf("%d", &B[i][j]);
                }
            }

            for (i = 0; i < baris_A; i++) {
                for (j = 0; j < kolom_B; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < kolom_A; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            printf("\nHasil perkalian A x B:\n");
            for (i = 0; i < baris_A; i++) {
                for (j = 0; j < kolom_B; j++) {
                    printf("%d\t", C[i][j]);
                }
                printf("\n");
            }
        }

        printf("\nHitung lagi? (y/n): ");
        scanf(" %c", &ulang);   
    } while (ulang == 'y' || ulang == 'Y');

    printf("Terima kasih!\n");
    return 0;
}