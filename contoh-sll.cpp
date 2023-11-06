#include <iostream>
using namespace std;
struct Mahasiswa{
    string nama, npm;
    int usia;
    Mahasiswa *next;
};
Mahasiswa *head, *tail, *cur, *newNode, *del;
void createSLL(string nama, string npm, int usia){
    head = new Mahasiswa();
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
    head->next = NULL;
    tail = head;
}
void addFirst(string nama, string npm, int usia){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}
void addLast(string nama, string npm, int usia){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}
void changeFirst(string nama, string npm, int usia){
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
}
void changeLast(string nama, string npm, int usia){
    tail->nama = nama;
    tail->npm = npm;
    tail->usia = usia;
}
void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}
void deleteLast(){
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}


void cetakSLL(){
    cur = head;
    while(cur != NULL){
        cout << "Nama Mhs : " << cur->nama << endl;
        cout << "NPM Mhs : " << cur->npm << endl;
        cout << "Usia Mhs : " << cur->usia << endl;
        cur = cur->next;
    }
}

int main() {
    createSLL("Yusron", "2008180004", 20);
    cetakSLL();
    cout << "\n";
    addFirst("Sarah", "2008180014", 17);
    cetakSLL();
    cout << "\n";
    addLast("Vendy", "2008180024", 18);
    cetakSLL();
    cout << "\n";
    changeFirst("Putri", "2008180034", 18);
    changeLast("Sandy", "2008180044", 18);
    cetakSLL();
    cout << "\n";
    deleteFirst();
    cetakSLL();
    cout << "\n";
    deleteLast();
    cetakSLL();
    cout << "\n";
}