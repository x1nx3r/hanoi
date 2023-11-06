#include <iostream>
using namespace std;

struct Makanan {
    string nama;
    string harga;
    Makanan* next;
    Makanan* prev;
};

Makanan* createNode(const string& nama, const string& harga) {
    Makanan* newNode = new Makanan;
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void appendNode(Makanan*& head, const string& nama, const string& harga, int index) {
    Makanan* nodeBaru = createNode(nama, harga);

    if (head == nullptr) {
        head = nodeBaru;
        return;
    }

    Makanan* current = head;
    Makanan* prev = nullptr;
    int count = 0;

    while (current != nullptr && count < index) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        prev->next = nodeBaru;
        nodeBaru->prev = prev;
    } else {
        if (prev != nullptr) {
            prev->next = nodeBaru;
            nodeBaru->prev = prev;
        } else {
            head = nodeBaru;
        }

        nodeBaru->next = current;
        current->prev = nodeBaru;
    }
}

void deleteNode(Makanan*& head, int index) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (index == 0) {
        Makanan* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    } else {
        Makanan* current = head;
        int count = 0;

        while (current != nullptr && count < index) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Index out of range. Cannot delete." << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }
}

void replaceNode(Makanan* head, string nama, string harga, int index) {
    deleteNode(head, index);
    appendNode(head, nama, harga, index);
}

void cetakList(Makanan* data) {
    while (data != nullptr) {
        cout << "Nama: " << data->nama << endl;
        cout << "Harga: " << data->harga << endl;
        data = data->next;
    }
}

int main() {
    Makanan* head = nullptr;

    appendNode(head, "Gado-gado", "12000", 0);
    appendNode(head, "Nasi Pecel", "14000", 1);
    appendNode(head, "Nasi Goreng", "20000", 2);

    cout << "Add Node :" << endl;
    cetakList(head);

    replaceNode(head, "Nasi Goreng", "25000", 0);
    replaceNode(head, "Nasi Pecel", "17000", 1);
    replaceNode(head, "Gado-gado", "13000", 2);

    cout << "Replace Node :" << endl;
    cetakList(head);

    deleteNode(head, 0);
    deleteNode(head, 1);

    cout << "Delete last and first node :" << endl;
    cetakList(head);

    Makanan* current = head;
    while (current != nullptr) {
        Makanan* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
