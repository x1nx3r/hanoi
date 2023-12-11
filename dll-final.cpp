#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, npm;
    int usia;
    Mahasiswa *next, *prev;
};
Mahasiswa *head, *tail, *cur, *newNode, *del, *afterNode;

void createDLL(string nama, string npm, int usia) {
    head = new Mahasiswa();
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void addFirst(string nama, string npm, int usia) {
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addLast(string nama, string npm, int usia) {
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMiddle(string nama, string npm, int usia, int posisi) {
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;

    cur = head;
    int seq = 1;
    while (seq < posisi - 1) {
        cur = cur->next;
        seq++;
    }
    afterNode = cur->next;
    newNode->prev = cur;
    newNode->next = afterNode;
    cur->next = newNode;
    afterNode->prev = newNode;
}

void deleteMiddle(int posisi) {
    cur = head;
    int seq = 1;
    while (seq < posisi - 1) {
        cur = cur->next;
        seq++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    if (afterNode != NULL) {
        afterNode->prev = cur;
    }
    delete del;
}

void deleteFirst() {
    del = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete del;
}

void deleteLast() {
    del = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    }
    delete del;
}

void changeFirst(string newNama, string newNpm, int newUsia) {
    if (head != NULL) {
        head->nama = newNama;
        head->npm = newNpm;
        head->usia = newUsia;
    }
}

void changeLast(string newNama, string newNpm, int newUsia) {
    if (tail != NULL) {
        tail->nama = newNama;
        tail->npm = newNpm;
        tail->usia = newUsia;
    }
}

void changeMiddle(string newNama, string newNpm, int newUsia, int posisi) {
    cur = head;
    int seq = 1;
    while (seq < posisi && cur != NULL) {
        cur = cur->next;
        seq++;
    }

    if (cur != NULL) {
        cur->nama = newNama;
        cur->npm = newNpm;
        cur->usia = newUsia;
    }
}

void printDLL() {
    cur = head;
    while (cur != NULL) {
        cout << "Nama Mahasiswa : " << cur->nama << endl;
        cout << "NPM Mahasiswa : " << cur->npm << endl;
        cout << "Usia Mahasiswa : " << cur->usia << endl;
        cur = cur->next;
    }
}

int main() {
    createDLL("Yusron", "2008180004", 20);
    printDLL();
    cout << "\n";

    addFirst("Sarah", "2008180014", 17);
    printDLL();
    cout << "\n";

    addLast("Yudo", "2008180024", 19);
    printDLL();
    cout << "\n";

    deleteFirst();
    printDLL();
    cout << "\n";

    deleteLast();
    printDLL();
    cout << "\n";

    addFirst("Sarah", "2008180014", 17);
    printDLL();
    cout << "\n";

    addLast("Yudo", "2008180024", 19);
    printDLL();
    cout << "\n";

    addMiddle("Fani", "2008180034", 17, 3);
    printDLL();
    cout << "\n";

    deleteMiddle(3);
    printDLL();
    cout << "\n";

    changeFirst("John", "2008180054", 25);
    changeLast("Doe", "2008180064", 22);
    changeMiddle("Alice", "2008180074", 21, 2);

    printDLL();
    cout << "\n";

    return 0;
}
