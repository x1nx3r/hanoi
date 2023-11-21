#include <iostream>
using namespace std;

struct DataMahasiswa{
  string nama;
  string jurusan;
  string npm;

  // pointer
  DataMahasiswa *prev;
  DataMahasiswa *next;
};

DataMahasiswa *head, *tail, *cur, *newNode, *del;
int maksimalData = 5;


void createData(string nama, string jurusan, string npm){
  head = new DataMahasiswa();
  head->nama = nama;
  head->jurusan = jurusan;
  head->npm = npm;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countData()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullData()
{
  if( countData() == maksimalData ){
    return true;
  }else{
    return false;
  }
}

bool isEmptyData()
{
  if( countData() == 0 ){
    return true;
  }else{
    return false;
  }
}

void pushData( string nama, string jurusan, string npm ){

  if( isFullData() ){
    cout << "Stack Full!!" << endl;
  }else{
    if( isEmptyData() ){
      createData(nama, jurusan,npm);
    }else{
      newNode = new DataMahasiswa();
      newNode->nama = nama;
      newNode->jurusan = jurusan;
      newNode->npm = npm;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }

}

void popData()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}

void displayData()
{
  if( isEmptyData() ){
    cout << "Data Mahasiswa Kosong" << endl;
  }else{
    cur = tail;
    while( cur != NULL ){
      cout << "\nNama Mahasiswa : " << cur->nama << "\nJurusan : " << cur->jurusan <<"\nNPM : "<<cur->npm<< endl;
      cur = cur->prev;
    }
  }
}


void peekData(int posisi){

  if( isEmptyData() ){
    cout << "Data Mahasiswa kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cout << "Data Mahasiswa Posisi ke-" << posisi << " Nama Mahasiswa : " << cur->nama << " Jurusan : " << cur->jurusan <<"NPM : "<<cur->npm<< endl;
  }

}

void changeData(string nama, string jurusan, string npm, int posisi){

  if( isEmptyData() ){
    cout << "Data Hero kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cur->nama = nama;
    cur->jurusan = jurusan;
    cur->npm = npm;
  }

}

void destroyData()
{
  cur = head;
  while( cur != NULL ){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){
    int x=1;
    int pil, posisi;
    string data[3];

    string nama, npm, jurusan;
        while (x=1){
        cout << "\nMenu Utama\n1. Data Baru\n2. Tambahkan\n3.Lihat data\n4.Tampilkan data\n5. Hapus Data\n";
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
                createData(nama,jurusan,npm);
                break;

            case 2 :
                // Input for Nama
                cout << "Masukkan Nama : ";
                getline(cin, nama);

                // Input for Jurusan
                cout << "Masukkan Jurusan : ";
                getline(cin, jurusan);

                // Input for NPM
                cout << "Masukkan NPM : ";
                getline(cin, npm);
                pushData(nama,jurusan,npm);
                break;
            case 3 :
                cout<<"Data ke : ";
                cin>> posisi;
                peekData(posisi);
                break;
            case 4 :
                int jumlah;
                for (int i=0;i<countData();i++){
                    peekData(i);
                }
            case 5 :
                system("cls");
                destroyData();     
                x=0;
                break;         
            }
        }
}