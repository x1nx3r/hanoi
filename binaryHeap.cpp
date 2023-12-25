#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan heapify ke atas (untuk memastikan sifat heap terpenuhi setelah penambahan elemen)
void heapifyUp(vector<int>& heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Fungsi untuk melakukan heapify ke bawah (untuk memastikan sifat heap terpenuhi setelah penghapusan elemen)
void heapifyDown(vector<int>& heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Fungsi untuk menambahkan elemen ke dalam heap
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

// Fungsi untuk mengambil dan mengembalikan elemen minimum dari heap
int extractMin(vector<int>& heap) {
    if (heap.empty()) {
        cerr << "Heap is empty!" << endl;
        return -1; // Anda dapat menangani kasus ini secara berbeda berdasarkan aplikasi Anda
    }

    int minValue = heap[0];
    swap(heap[0], heap.back());
    heap.pop_back();
    heapifyDown(heap, 0);

    return minValue;
}

// Fungsi untuk mencetak isi heap
void printHeap(const vector<int>& heap) {
    cout << "Heap: ";
    for (int value : heap) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> binaryHeap;

    insert(binaryHeap, 4);
    insert(binaryHeap, 8);
    insert(binaryHeap, 2);
    insert(binaryHeap, 5);
    insert(binaryHeap, 1);

    printHeap(binaryHeap);

    cout << "Extracted Min: " << extractMin(binaryHeap) << endl;

    printHeap(binaryHeap);

    return 0;
}
