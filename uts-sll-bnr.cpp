#include <iostream>
using namespace std;

struct Makanan{
    string nama;
    int harga;
    Makanan *next;
};

Makanan *head, *tail, *cur, *newNode, *del;

void createSLL(string nama, int harga){
    head = new Makanan();
    head->nama = nama;
    head->harga = harga;
    head->next = NULL;
    tail = head;
}

void addLast(string nama, int harga){
    newNode = new Makanan();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}

void deleteLast(){
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void countNode() {
    int count = 0;
    Makanan* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("panjang node : %d", count);
}

void addMiddle(string nama, int harga, int position) {
    if (position < 0) {
        cout << "Invalid position. Cannot insert." << endl;
        return;
    }
    newNode = new Makanan();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = NULL;
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Makanan* current = head;
    Makanan* prev = nullptr;
    int count = 0;
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    if (count == position) {
        prev->next = newNode;
        newNode->next = current;
    } else {
        cout << "Invalid position. Cannot insert." << endl;
        delete newNode;
    }
}
