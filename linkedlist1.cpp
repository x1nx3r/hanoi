//Add first, add last, add middle, change first, change last, change middle, delete first, delete last, delete middle

#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama, npm;
    int usia;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del;
