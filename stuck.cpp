#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct DataMahasiswa{
  string nama;
  string jurusan;
  string npm;
};

// Function to display all elements of a stack
template <typename T>
void displayStack(const stack<T>& s) {
    stack<T> tempStack = s;  // Create a temporary stack for iteration
    if (tempStack.empty()){
        cout << "Stack kosong";
        exit;
    }
    while (!tempStack.empty()) {
        cout << "Identitas Mahasiswa : " << tempStack.top().nama << " "
                  << tempStack.top().jurusan << " "
                  << tempStack.top().npm << std::endl;
        tempStack.pop();  // Move to the next element
    }

}

int main() {
    // Define stack pf DataMahasiswa struct as stackMahasiswa
    stack<DataMahasiswa> stackMahasiswa;

    int x=1;
    int pil, posisi;
    string nama, npm, jurusan;
        while (x==1){
        cout << "\nMenu Utama\n1. Data Baru\n2.Lihat data\n";
        cout<<"Pilih Menu : "; 
        cin >> pil;
        cin.ignore(); // Clear the newline character from the input buffer
        
        switch (pil) {  
            case 1 :
                // Input for Nama
                cout << "Masukkan Nama : ";
                getline(cin, nama);

                // Input for Jurusan
                cout << "Masukkan Jurusan : ";
                getline(cin, jurusan);

                // Input for NPM
                cout << "Masukkan NPM : ";
                getline(cin, npm);
                stackMahasiswa.push({nama, jurusan, npm});
                break;

            case 2 :
                displayStack(stackMahasiswa);
                break;}
        }
    return 0;
}
