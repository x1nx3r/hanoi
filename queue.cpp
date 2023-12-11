#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string npm;
    int usia;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr;
Mahasiswa* rear = nullptr;
const int maksimalMahasiswa = 5;

int countMahasiswa() {
    int count = 0;
    Mahasiswa* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool isFull() {
    return countMahasiswa() == maksimalMahasiswa;
}

bool isEmpty() {
    return front == nullptr;
}

void enqueue(string nama, string npm, int usia) {
    if (isFull()) {
        cout << "Queue Full! Cannot enqueue more Mahasiswa." << endl;
        return;
    }

    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Enqueued: " << nama << " - " << npm << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Empty! Cannot dequeue from an empty queue." << endl;
        return;
    }

    Mahasiswa* temp = front;
    cout << "Dequeued: " << temp->nama << " - " << temp->npm << endl;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    delete temp;
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Queue Empty! Nothing to display." << endl;
        return;
    }

    Mahasiswa* temp = front;
    cout << "\n\nQueue Mahasiswa:" << endl;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << " - NPM: " << temp->npm << " - Usia: " << temp->usia << endl;
        temp = temp->next;
    }
}

void destroyQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {

    enqueue("John", "2008180001", 20);
    enqueue("Alice", "2008180002", 22);
    enqueue("Bob", "2008180003", 21);

    displayQueue();

    dequeue();
    enqueue("Charlie", "2008180004", 19);

    displayQueue();

    cout << "Queue Count: " << countMahasiswa() << endl;

    destroyQueue(); // Clean up memory
    return 0;
}
