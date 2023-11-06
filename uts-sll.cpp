#include <iostream>

using namespace std;
struct Makanan {
    string nama;
    string harga;
    Makanan* next;
};

Makanan* createNode(const string& nama, const string& harga) {
    Makanan* newNode = new Makanan;
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->next = nullptr;
    return newNode;
}

void appendNode(Makanan*& head, const string& nama, const string& harga, int index) {
    // Create new node
    Makanan* nodeBaru = createNode(nama, harga);

    // Case 0: If inserting at the beginning (head)
    if (index == 0) {
        nodeBaru->next = head;
        head = nodeBaru;
        return;
    }

    // Case 1: Inserting in the middle or at the end
    Makanan* current = head;
    Makanan* prev = nullptr;

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

int countNode(Makanan* head) {
    int count = 0;
    Makanan* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}


void deleteNode(Makanan*& head, int index) {
    // Case 0: If the list is empty
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Case 1: If the node to be deleted is the head
    if (index == 0) {
        Makanan* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: If the node to be deleted is in the middle or end
    Makanan* current = head;
    Makanan* tail = nullptr;

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

void replaceNode(struct Makanan* head, string nama, string harga, int index){
    deleteNode(head, index);
    appendNode(head, nama, harga, index);
}

void cetakList(struct Makanan* data){
    // Traversing the list
    while (data!=nullptr){
        // Print the data inside
        cout << "Nama : " << data -> nama << endl;
        cout << "harga : " << data -> harga << endl;

        // Move to next
        data = data -> next;
    }
}

// Example of usage:
int main() {
    // Variable initialization
    Makanan* head = nullptr;

    // appendNode function is to add nodes based on index given
    // whether it's in front, middle, or last
    appendNode(head, "Gado-gado", "12000", 0);
    appendNode(head, "Nasi Pecel", "14000", 1);
    appendNode(head, "Nasi Goreng", "20000", 2);
    // Print list to check if appendNode works correctly as an add node function
    cout << "Add Node :" << endl;
    cetakList(head);
    
    // replaceNode is just a wrapped together deleteNode and appendNode 
    // so it could be executed as a whole, one after another .
    // it gives the functionality of replacing node on specific index
    // Here the last, middle, and first node being replaced.
    replaceNode(head, "Nasi Goreng", "20000", 0);
    replaceNode(head, "Nasi Pecel", "14000", 1);
    replaceNode(head, "Gado-gado", "12000", 2);
    // Print list to check if replaceNode works correctly
    cout << "Replace Node :" << endl;
    cetakList(head);

    // Node Counting
    printf("jumlah node : %d\n",countNode(head));

    // deleteNode function is to delete a node on specific index
    // by using index it could be used to delete a node
    // whether i'ts in first, middle, or last of a list.
    deleteNode(head, 0); // deleting the front
    deleteNode(head, 1); // delete the last
    cout << "Delete last and first node :" << endl;
    cetakList(head);

    // Don't forget to free the memory when done with the list
    Makanan* current = head;
    while (current != nullptr) {
        Makanan* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
