#include <iostream>
#include <string>
using namespace std;

struct dataBuku {
  string namaBuku;
  int hargaBuku;
  dataBuku *prev;
  dataBuku *next;
};

dataBuku *head, *tail, *cur, *newNode, *del;
const int maksimalBuku = 5;

void createBuku(string namaBuku, int hargaBuku) {
  head = new dataBuku();
  head->namaBuku = namaBuku;
  head->hargaBuku = hargaBuku;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countBuku() {
  if (head == NULL) {
    return 0;
  } else {
    int banyak = 0;
    cur = head;
    while (cur != NULL) {
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullBuku() {
  return countBuku() == maksimalBuku;
}

bool isEmptyBuku() {
  return countBuku() == 0;
}

void pushBuku(string namaBuku, int hargaBuku) {
  if (isFullBuku()) {
    cout << "Stack Full!!" << endl;
  } else {
    if (isEmptyBuku()) {
      createBuku(namaBuku, hargaBuku);
    } else {
      newNode = new dataBuku();
      newNode->namaBuku = namaBuku;
      newNode->hargaBuku = hargaBuku;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }
}

void popBuku() {
  if (!isEmptyBuku()) {
    del = tail;
    tail = tail->prev;
    if (tail != NULL) {
      tail->next = NULL;
    } else {
      head = NULL;
    }
    delete del;
  }
}

void displayBuku() {
  if (isEmptyBuku()) {
    cout << "Data Buku kosong" << endl;
  } else {
    cout << "\n\nData Buku : " << endl;
    cur = tail;
    while (cur != NULL) {
      cout << "Data Buku : " << cur->namaBuku << " - Rp." << cur->hargaBuku << endl;
      cur = cur->prev;
    }
  }
}

void peekBuku(int posisi) {
  if (isEmptyBuku()) {
    cout << "Data Buku kosong" << endl;
  } else {
    int nomor = 1;
    cur = tail;
    while (nomor < posisi && cur != NULL) {
      cur = cur->prev;
      nomor++;
    }
    if (cur != NULL) {
      cout << "Data Buku Posisi ke-" << posisi << " : " << cur->namaBuku << " - Rp." << cur->hargaBuku << endl;
    } else {
      cout << "Posisi tidak valid." << endl;
    }
  }
}

void changeBuku(string namaBuku, int hargaBuku, int posisi) {
  if (!isEmptyBuku()) {
    int nomor = 1;
    cur = tail;
    while (nomor < posisi && cur != NULL) {
      cur = cur->prev;
      nomor++;
    }
    if (cur != NULL) {
      cur->namaBuku = namaBuku;
      cur->hargaBuku = hargaBuku;
    } else {
      cout << "Posisi tidak valid." << endl;
    }
  } else {
    cout << "Data Buku kosong" << endl;
  }
}

void destroyBuku() {
  cur = head;
  while (cur != NULL) {
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main() {
  pushBuku("Book1", 100);
  pushBuku("Book2", 150);
  pushBuku("Book3", 200);

  displayBuku();

  popBuku();
  pushBuku("Book4", 180);

  displayBuku();

  peekBuku(2);

  changeBuku("ModifiedBook", 250, 1);

  displayBuku();

  destroyBuku();  // Clean up memory
  return 0;
}
