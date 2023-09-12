#include <stdio.h>

// Fungsi untuk membalik row dan cols (transpos)
void transposeMatrix(int original[][100], int transpose[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = original[i][j];
        }
    }
}

// fungsi input matrix
void matrixInput(int matrix[][100], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// fungsi display matrix
void matrixDisplay(int matrix[][100], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
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
    matrixInput(matrix, rows, cols);

    // gunakan fungsi yang tadi untuk mengukar row dan cols
    transposeMatrix(matrix, transpose, rows, cols);

    // tampilkan matrix asal
    matrixDisplay(matrix, rows, cols);

    // display hasil transpos
    matrixDisplay(transpose, rows, cols);

    return 0;
}
