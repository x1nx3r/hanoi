//Add first, add last, add middle, change first, change last, change middle, delete first, delete last, delete middle

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char nama[30], npm[12];
    int usia;
    struct Node* next;
};

struct Node* createNode(char nama, char npm, int usia) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Terminate the program with an error code
    }

    // Set the data of the new node to the provided value
    newNode->nama = nama;
    

    // Set the next pointer of the new node to NULL
    newNode->next = NULL;

    // Return the newly created node
    return newNode;
}

void appendNode(struct Node** head, int value) {
    // Create a new node with the given value
    struct Node* newNode = createNode(value);

    // If the linked list is empty, set the head to the new node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse the linked list to find the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Attach the new node to the last node's 'next' pointer
    temp->next = newNode;
}


void printList(struct Node* head) {
    // Traverse the linked list
    while (head != NULL) {
        // Print the data of the current node
        printf("%d -> ", head->data);
        
        // Move to the next node
        head = head->next;
    }

    // Print "NULL" to signify the end of the list
    printf("NULL\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* udin = NULL;

    // Add first

    // Add last

    // Add middle

    // Change first

    // Change last

    // Change middle

    // Delete first 

    // Delete last

    // Delete middle
    appendNode(&udin, 1);
    appendNode(&udin, 2);
    appendNode(&udin, 3);

    printf("Linked List: ");
    printList(udin);

    freeList(udin);

    return 0;
}
