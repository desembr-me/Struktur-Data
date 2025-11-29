#include<iostream>
using namespace std;
#define n 5  // Ukuran maksimal queue

// Struktur Queue dengan array
struct Que {
    int rear;      // Posisi belakang queue
    int front;     // Posisi depan queue
    int elemen[n]; // Array untuk menyimpan elemen
    int jml;       // Jumlah elemen dalam queue
};

// Fungsi untuk membuat/inisialisasi queue
void createQ(Que &q){
    q.front = 0;   // Posisi depan dimulai dari 0
    q.jml = 0;     // Jumlah elemen awal = 0
    q.rear = -1;   // Posisi belakang awal = -1 (kosong)
}

// Fungsi pengecekan jika queue penuh
bool isFull(Que q){
    return q.jml == n;  // Penuh jika jumlah = ukuran maksimal
}

// Fungsi pengecekan jika queue kosong
bool isEmpty(Que q){
    return q.jml == 0;  // Kosong jika jumlah = 0
}

// Fungsi enqueue (menambah elemen ke belakang)
void enque(Que &q, int i){
    if(isFull(q))      // Jika penuh, tidak bisa tambah
        return;
    
    q.rear++;          // Geser posisi belakang ke depan
    q.jml++;           // Tambah jumlah elemen
    q.elemen[q.rear] = i;  // Masukkan nilai ke posisi belakang
}

// Fungsi dequeue (menghapus elemen dari depan)
void deque(Que &q){
    if(isEmpty(q))     // Jika kosong, tidak bisa hapus
        return;
    
    int i = q.elemen[q.front];  // Simpan nilai yang akan dihapus
    q.front++;         // Geser posisi depan ke belakang
    q.jml--;           // Kurangi jumlah elemen
    cout<<"Data "<<i<<" berhasil dihapus dari queue!"<<endl;  // Tampilkan data yang dihapus
}

// Fungsi menampilkan isi queue
void showque(Que q){
    if(isEmpty(q)){    // Jika kosong
        cout<<"Queue Kosong!"<<endl;
    }
    else{              // Jika ada elemen
        cout<<"Isi Queue: ";
        for(int i = q.front; i <= q.rear; i++){  // Loop dari front sampai rear
            cout<<q.elemen[i]<<" ";  // Tampilkan setiap elemen
        }
        cout<<endl;
    }
}

// Fungsi kosongkan queue
void kosongkanQue(Que &q){
    q.front = 0;   // Reset posisi depan
    q.jml = 0;     // Reset jumlah elemen
    q.rear = -1;   // Reset posisi belakang
}

// Fungsi menampilkan sisa antrian
void sisa_Antrian(Que q){
    int sisa = n - q.jml;  // Hitung sisa kapasitas
    cout<<"Kapasitas Queue: "<<n<<endl;
    cout<<"Elemen saat ini: "<<q.jml<<endl;
    cout<<"Sisa kapasitas: "<<sisa<<endl;
}

// Fungsi utama
int main(){
    Que A;
    int pilihan;
    int nilai;
    
    createQ(A);  // Inisialisasi queue
    
    cout<<"Implementasi Queue dengan Array"<<endl;
    cout<<"================================="<<endl;
    cout<<endl;
    
    do{
        cout<<"Menu:"<<endl;
        cout<<"1. Enqueue Data"<<endl;
        cout<<"2. Dequeue Data"<<endl;
        cout<<"3. Tampil isi Queue"<<endl;
        cout<<"4. Kosongkan Queue"<<endl;
        cout<<"5. Tampilkan sisa antrian Queue"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Masukkan pilihan [1...6]: ";
        cin>>pilihan;
        
        cout<<endl;
        
        switch(pilihan){
            case 1:
                // Menu enqueue
                if(isFull(A)){
                    cout<<"Queue Sudah Penuh!"<<endl;
                }
                else{
                    cout<<"Masukkan data yang ingin di Enqueue: ";
                    cin>>nilai;
                    enque(A, nilai);  // Tambah elemen
                    cout<<"Data "<<nilai<<" berhasil dimasukkan!"<<endl;
                }
                cout<<endl;
                break;
                
            case 2:
                // Menu dequeue
                if(isEmpty(A)){
                    cout<<"Queue Kosong, tidak ada yang dihapus!"<<endl;
                }
                else{
                    deque(A);  // Hapus elemen dari depan
                }
                cout<<endl;
                break;
                
            case 3:
                // Menu tampil isi queue
                cout<<"Isi Queue saat ini:"<<endl;
                showque(A);  // Tampilkan semua elemen
                cout<<endl;
                break;
                
            case 4:
                // Menu kosongkan queue
                kosongkanQue(A);  // Kosongkan queue
                cout<<"Queue sekarang kosong!"<<endl;
                cout<<endl;
                break;
                
            case 5:
                // Menu tampil sisa antrian
                sisa_Antrian(A);  // Tampilkan info kapasitas
                cout<<endl;
                break;
                
            case 6:
                // Menu keluar
                cout<<"Selamat Tinggal!!!!"<<endl;
                break;
                
            default:
                cout<<"Pilihan tidak Valid!"<<endl;
                cout<<endl;
                break;
        }
    } while(pilihan != 6);  // Loop sampai pilih keluar
    
    return 0;
}