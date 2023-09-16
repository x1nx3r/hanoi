#include <stdio.h>

float x_to_the_power_of_n(int x, int n){
    if (n==0){
        return 1;
    } else if (n>0){
        return x * x_to_the_power_of_n(x, n-1);
    } else if (n<0){
        return 1/x_to_the_power_of_n(x, -n);
    }
}

int main (){
    int x, n;
    printf("x=");
    scanf("%d", &x);

    printf("n=");
    scanf("%d", &n);

    printf("x to the power of n : %f", x_to_the_power_of_n(x, n));

    return 0;
}