#include <stdio.h>

// n = number of disks to be moved
// origin_rod = Rod where disk is present
// destination_rod = Rod where disk is supposed to go
// aux_rod = Rod where disk isn't supossed to go

void towerHanoi(int n, char origin_rod, char destination_rod, char aux_rod){
    if (n==1){
        printf("\nMove disk 1 from rod %c to rod %c", origin_rod, destination_rod);
        return;
    }

    towerHanoi(n-1, origin_rod, aux_rod, destination_rod);
    printf("\nMove disk %d from rod %c to rod %c", n, origin_rod, destination_rod);
    towerHanoi(n-1, aux_rod, destination_rod, origin_rod);
}

int main (){
    int n;
    printf("Enter how many disks? ");
    scanf("\n%d", &n);
    towerHanoi(n, 'A', 'C', 'B' );
    return 0;
}



