//Add first, add last, add middle, change first, change last, change middle, delete first, delete last, delete middle

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Mahasiswa{
    string nama, npm;
    int usia;
    Mahasiswa *next;
};

void cetakList(struct Mahasiswa* data){
    // Traversing the list
    while (data!=NULL){
        // Print the data inside
        cout << "Nama : %s" << data -> nama;
        cout << "NPM : %s" << data -> npm;
        cout << "Usia : %d" << data -> usia;

        // Move to next
        data = data -> next;
    }
}

void appendNode(Mahasiswa*& data, string nama, string npm, int usia) {
    // Create new node with createNode
    Mahasiswa* nodeBaru = createNode(nama, npm, usia);

    // If the list is empty, set nodeBaru as head
    if (data == nullptr) {
        data = nodeBaru;
        return;
    }

    // Go to the last node to find the last node
    Mahasiswa* temp = data;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Attach newNode to the last node
    temp->next = nodeBaru;
}

struct Mahasiswa* createNode(char nama, char npm, int usia) {
    // Allocate memory for a new node
    Mahasiswa* newNode = new;

    // Check if memory allocation was successful
    if (newNode == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        exit(1); // Terminate the program with an error code
    }

    // Set the data of the new node to the provided value
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;

    // Set the next pointer of the new node to NULL
    newNode->next = nullptr;

    // Return the newly created node
    return newNode;
}


int main() {
    struct Mahasiswa* udin = NULL;
    appendNode(udin, "Yusron", "2008180004", 20);
    cetakList();
}