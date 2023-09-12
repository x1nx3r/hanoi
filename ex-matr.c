#include <stdio.h>

// Fungsi untuk membalik row dan cols (transpos)
void transposeMatrix(int original[][100], int transpose[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = original[i][j];
        }
    }
}

int main() {
    int rows, cols;

    // input.
    printf("Masukkan berapa banyak baris: ");
    scanf("%d", &rows);
    printf("Masukkan berapa banyak kolom: ");
    scanf("%d", &cols);

    int matrix[100][100]; // Assuming a maximum size for the matrix
    int transpose[100][100];

    // Input the elements of the matrix.
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // gunakan fungsi yang tadi untuk mengukar row dan cols
    transposeMatrix(matrix, transpose, rows, cols);

    // tampilkan matrix asal
    printf("Matrix yang anda masukkan:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // display hasil transpos
    printf("Hasil Transpos:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
