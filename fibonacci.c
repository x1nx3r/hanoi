#include <stdio.h>

//fungsi untuk generate deret fibonacci hingga n
void generateFibonacci(int n) {
    int first = 0, second = 1, next, i;
    
    printf("Fibonacci Sequence up to %d terms:\n", n);
    
    for (i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Masukkan berapa banyak angka deret fibonacci yang anda inginkan: ");
    scanf("%d", &n);
    
    generateFibonacci(n);
    
    return 0;
}
