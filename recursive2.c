/*
    Nama : Muhammad Mega Nugraha
    NPM : 22081010213
    Kelas : D081

    Soal : Bagaimana menjawab x^n, jika diketahui nillai x^(n/2)! Terapkan pada kode program
    Jawab :
    dengan mengetahui sifat eksponen x^(a*b) = (x^a)^b
    maka bisa ditulis bahwa
    x^n bisa ditemukan dengan mengkuadratkan x^(n/2)
    -->  x^n = (x^(n/2))^2
*/
#include <stdio.h>
#include <math.h>

double calculate_x_to_n(double x_power_half_n) {
    // Hitung x^n dengan (x^(n/2))^2
    return pow(x_power_half_n, 2);
}

int main() {
    double x_to_half_n = 4.0;   // nilai x^(n/2)

    double result = calculate_x_to_n(x_to_half_n);

    printf("x^n = %.2lf\n", result);

    return 0;
}
