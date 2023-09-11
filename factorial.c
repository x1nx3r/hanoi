#include <stdio.h>

// Fungsi untuk menghitung faktorial dari n
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    printf("Masukkan angka integer positif: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Faktorial tidak bisa dihitung untuk angka negatif.\n");
    } else {
        unsigned long long result = factorial(num);
        printf("Faktorial dari %d adalah %llu\n", num, result);
    }

    return 0;
}
