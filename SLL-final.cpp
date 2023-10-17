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

void appendNode(Mahasiswa*& head, const string& nama, const string& npm, int usia, int index) {
    // Create new node
    Mahasiswa* nodeBaru = createNode(nama, npm, usia);

    // Case 0: If inserting at the beginning (head)
    if (index == 0) {
        nodeBaru->next = head;
        head = nodeBaru;
        return;
    }

    // Case 1: Inserting in the middle or at the end
    Mahasiswa* current = head;
    Mahasiswa* prev = nullptr;

    int count = 0;
    while (current != nullptr && count < index) {
        prev = current;
        current = current->next;
        count++;
    }

    // Insert at the specified index
    if (current == nullptr && count == index) {
        // Case 2: Insert at the end
        prev->next = nodeBaru;
    } else if (current != nullptr) {
        // Case 3: Insert in the middle
        prev->next = nodeBaru;
        nodeBaru->next = current;
    } else {
        // Case 4: Index out of range
        std::cout << "Index out of range. Cannot insert." << std::endl;
        delete nodeBaru;
    }
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

void replaceNode(struct Mahasiswa* head, string nama, string npm, int usia, int index){
    deleteNode(head, index);
    appendNode(head, nama, npm, usia, index);
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
    // Variable initialization
    Mahasiswa* head = nullptr;

    // appendNode function is to add nodes based on index given
    // whether it's in front, middle, or last
    appendNode(head, "John Doe", "12345", 20, 0);
    appendNode(head, "Jane Smith", "67890", 22, 1);
    appendNode(head, "Mark Twain", "12345", 20, 2);
    // Print list to check if appendNode works correctly as an add node function
    cout << "Add Node :" << endl;
    cetakList(head);
    
    // replaceNode is just a wrapped together deleteNode and appendNode 
    // so it could be executed as a whole, one after another .
    // it gives the functionality of replacing node on specific index
    // Here the last, middle, and first node being replaced.
    replaceNode(head, "Chris Effendy", "12345", 20, 2);
    replaceNode(head, "Titus Black", "3314", 21, 1);
    replaceNode(head, "John Green", "12345", 20, 0);
    // Print list to check if replaceNode works correctly
    cout << "Replace Node :" << endl;
    cetakList(head);

    // deleteNode function is to delete a node on specific index
    // by using index it could be used to delete a node
    // whether i'ts in first, middle, or last of a list.
    deleteNode(head, 0); // deleting the front
    deleteNode(head, 1); // delete the last
    cout << "Delete last and first node :" << endl;
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
