#include <iostream>

using namespace std;
struct Mahasiswa {
    string nama;
    string npm;
    int usia;
    Mahasiswa* next;
};

Mahasiswa* createNode(const string& nama, const string& npm, int usia) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = nullptr;
    return newNode;
}

void appendNode(Mahasiswa*& data, const string& nama, const string& npm, int usia) {
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

void deleteNode(Mahasiswa*& head, int index) {
    // Case 0: If the list is empty
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Case 1: If the node to be deleted is the head
    if (index == 0) {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: If the node to be deleted is in the middle or end
    Mahasiswa* current = head;
    Mahasiswa* tail = nullptr;

    int count = 0;
    while (current != nullptr && count < index) {
        tail = current;
        current = current->next;
        count++;
    }

    // Case 2 or Case 3: Delete the node
    if (current == nullptr) {
        std::cout << "Index out of range. Cannot delete." << std::endl;
        return;
    }

    tail->next = current->next;
    delete current;
}

void cetakList(struct Mahasiswa* data){
    // Traversing the list
    while (data!=nullptr){
        // Print the data inside
        cout << "Nama : " << data -> nama << endl;
        cout << "NPM : " << data -> npm << endl;
        cout << "Usia : " << data -> usia << endl << endl;

        // Move to next
        data = data -> next;
    }
}

// Example of usage:
int main() {
    Mahasiswa* head = nullptr;
    appendNode(head, "John Doe", "12345", 20);
    appendNode(head, "Jane Smith", "67890", 22);

    // Print the list or perform other operations...
    cetakList(head);

    // Delete 1
    deleteNode(head, 1);
    cetakList(head);


    // Don't forget to free the memory when done with the list
    Mahasiswa* current = head;
    while (current != nullptr) {
        Mahasiswa* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
