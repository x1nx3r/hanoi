#include <stdio.h>
#include <string.h>

// Struct template untuk karakter profil
struct Mahasiswa {
    char nama[50];
    char npm[15];
    char prodi[24];
    float ipk;
};

// Fungsi pembanding untuk sorting
int compareByNama(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->nama, b->nama);
}

int compareByNpm(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->npm, b->npm);
}

int compareByProdi(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    return strcmp(a->prodi, b->prodi);
}

int compareByIpk(const struct Mahasiswa *a, const struct Mahasiswa *b) {
    if (a->ipk < b->ipk) {
        return -1;
    } else if (a->ipk > b->ipk) {
        return 1;
    } else {
        return 0;
    }
}

// Fungsi untuk menampilkan elemen-elemen pada array Mahasiswa
void displayMahasiswa(const struct Mahasiswa *identitas, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, NPM: %s, Prodi: %s, IPK: %.2f\n", 
        identitas[i].nama, identitas[i].npm, 
        identitas[i].prodi, identitas[i].ipk);
    }
}

// Fungsi Bubble Sort
void bubbleSort(struct Mahasiswa identitas[], 
                int size, int (*compare)(const struct Mahasiswa *,
                const struct Mahasiswa *)) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(&identitas[j], &identitas[j + 1]) > 0) {
                struct Mahasiswa temp = identitas[j];
                identitas[j] = identitas[j + 1];
                identitas[j + 1] = temp;
                swapped = 1;

                printf("Swapping %s with %s\n", identitas[j].nama, identitas[j + 1].nama);
            }
        }
        if (swapped == 0) {
            // Jika tidak ada pertukaran dalam loop dalam, array sudah terurut.
            break;
        }
    }
}

// Fungsi Selection Sort
void selectionSort(struct Mahasiswa identitas[], 
                int size, int (*compare)(const struct Mahasiswa *, 
                const struct Mahasiswa *)) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (compare(&identitas[j], &identitas[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Tukar elemen jika perlu
            struct Mahasiswa temp = identitas[i];
            identitas[i] = identitas[minIndex];
            identitas[minIndex] = temp;

            printf("Swapping %s with %s\n", identitas[i].nama, identitas[minIndex].nama);
        }
    }
}

int main() {
    struct Mahasiswa identitas[] = {
        {"Udin", "17081010013", "Informatika", 2.7},
        {"Slamet", "19012010043", "Teknik Sipil", 3.4},
        {"Opang", "20081010133", "Teknik Industri", 3.3},
    };

    int jmlMahasiswa = sizeof(identitas) / sizeof(identitas[0]);

    printf("Urutan Sebelumnya :\n");
    displayMahasiswa(identitas, jmlMahasiswa);

    printf("\nSorting by nama (bubble):\n");
    bubbleSort(identitas, jmlMahasiswa, compareByNama);

    printf("\nSorted by nama (bubble):\n");
    displayMahasiswa(identitas, jmlMahasiswa);

    printf("\nSorting by npm (selection):\n");
    selectionSort(identitas, jmlMahasiswa, compareByNpm);

    printf("\nSorted by npm (selection):\n");
    displayMahasiswa(identitas, jmlMahasiswa);

    return 0;
}
