#include <iostream>
using namespace std;

struct Makanan {
    string nama;
    int harga;
    Makanan* next;
    Makanan* prev;
};

Makanan* head = nullptr;
Makanan* tail = nullptr;

void createDLL(string nama, int harga) {
    Makanan* newNode = new Makanan();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    head = newNode;
    tail = newNode;
}

void addLast(string nama, int harga) {
    Makanan* newNode = new Makanan();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    }

    tail = newNode;

    if (head == nullptr) {
        head = newNode;
    }
}

void addMiddle(string nama, int harga, int position) {
    if (position < 0) {
        cout << "Invalid position. Cannot insert." << endl;
        return;}
    Makanan* newNode = new Makanan();
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (position == 0) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;}
        head = newNode;
    } else {
        Makanan* current = head;
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;}
        if (count == position) {
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            } else {
                head = newNode;}
            current->prev = newNode;
        } else {
            cout << "Invalid position. Cannot insert." << endl;
            delete newNode;
        }
    }
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    Makanan* del = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete del;
}

void deleteLast() {
    if (tail == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Makanan* del = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    }

    delete del;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void countNode() {
    int count = 0;
    Makanan* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    cout << "Number of nodes: " << count << endl;
}

int main() {
    createDLL("Gado-gado", 12000);
    addLast("Nasi Pecel", 14000);
    addLast("Nasi Goreng", 20000);

    cout << "Add Node:" << endl;
    countNode();

    addMiddle("Soto Ayam", 15000, 2);

    cout << "Add Middle Node:" << endl;
    countNode();

    deleteFirst();
    deleteLast();

    cout << "Delete first and last Node:" << endl;
    countNode();

    Makanan* current = head;
    while (current != nullptr) {
        Makanan* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
