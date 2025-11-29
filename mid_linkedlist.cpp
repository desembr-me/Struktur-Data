#include <iostream> // Mengimpor library iostream untuk input-output
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std:: di setiap perintah

// Mendefinisikan struktur File untuk menyimpan data file
struct File{
	string nama; // Variabel untuk menyimpan nama file
	string jenisFile; // Variabel untuk menyimpan jenis file
};

// Mendefinisikan struktur Node untuk linked list
struct Node{
	File data; // Variabel untuk menyimpan data file
	Node *next; // Pointer untuk menunjuk ke node berikutnya
};

// Deklarasi pointer global
Node *n=NULL; // Pointer n untuk node baru yang akan dibuat
Node *head=NULL; // Pointer head menunjuk ke node pertama (awal list)
Node *tail=NULL; // Pointer tail menunjuk ke node terakhir (akhir list)
Node *x=NULL; // Pointer x untuk proses traversal (perjalanan) dalam list

// ======== FUNGSI-FUNGSI OPERASI LINKED LIST ========

// Fungsi untuk membuat node pertama (node awal)
void buatNodeAwal(string nama, string jenis){ // Parameter nama dan jenis file
	n = new Node; // Alokasi memori baru untuk node
	n->data.nama = nama; // Menyimpan nama file ke dalam data node
	n->data.jenisFile = jenis; // Menyimpan jenis file ke dalam data node
	n->next = NULL; // Mengatur pointer next ke NULL (tidak ada node berikutnya)
	tail = n; // tail menunjuk ke node pertama
	head = n; // head menunjuk ke node pertama
}

// Fungsi untuk menambah node di posisi belakang
void tambahDiBelakang(string nama, string jenis){ // Parameter nama dan jenis file
	n = new Node; // Alokasi memori baru untuk node
	n->data.nama = nama; // Menyimpan nama file ke dalam data node
	n->data.jenisFile = jenis; // Menyimpan jenis file ke dalam data node
	tail->next = n; // Menghubungkan node terakhir dengan node baru
	tail = n; // Menggeser tail ke node baru (sekarang menjadi node terakhir)
	tail->next = NULL; // Mengatur pointer next node terakhir ke NULL
}

// Fungsi untuk menambah node di posisi depan
void tambahDiDepan(string nama, string jenis){ // Parameter nama dan jenis file
	n = new Node; // Alokasi memori baru untuk node
	n->data.nama = nama; // Menyimpan nama file ke dalam data node
	n->data.jenisFile = jenis; // Menyimpan jenis file ke dalam data node
	n->next = head; // Menghubungkan node baru dengan node pertama lama
	head = n; // Menggeser head ke node baru (sekarang menjadi node pertama)
}

// Fungsi untuk menambah node di posisi tengah
void tambahDiTengah(string nama, string jenis, string namaReferensi){ // nama = nama baru, namaReferensi = nama file setelah posisi penyisipan
	x = head; // Mulai dari node pertama
	while(x->data.nama != namaReferensi) x = x->next; // Cari node yang namanya sama dengan namaReferensi
	n = new Node; // Alokasi memori baru untuk node
	n->data.nama = nama; // Menyimpan nama file ke dalam data node
	n->data.jenisFile = jenis; // Menyimpan jenis file ke dalam data node
	n->next = x->next; // Node baru menunjuk ke node yang sebelumnya ditunjuk oleh x
	x->next = n; // Node x menunjuk ke node baru
}

// Fungsi untuk menghapus node di posisi depan
void hapusDiDepan(){ // Fungsi tanpa parameter karena menghapus node pertama
	x = head; // Menyimpan pointer head ke x
	head = head->next; // Menggeser head ke node berikutnya
	delete(x); // Menghapus node lama (dealokasi memori)
}

// Fungsi untuk menghapus node di posisi belakang
void hapusDiBelakang(){ // Fungsi tanpa parameter karena menghapus node terakhir
	x = head; // Mulai dari node pertama
	while(x->next != tail) x = x->next; // Cari node yang pointer nextnya adalah tail
	tail = x; // Menggeser tail ke node sebelum tail lama
	delete(x->next); // Menghapus node terakhir lama (dealokasi memori)
	tail->next = NULL; // Mengatur pointer next tail ke NULL
}

// Fungsi untuk menghapus node di posisi tengah
void hapusDiTengah(string nama){ // Parameter nama adalah nama file yang akan dihapus
	Node *temp = NULL; // Pointer temp untuk menyimpan node sebelumnya
	x = head; // Mulai dari node pertama
	while(x->data.nama != nama){ // Cari node yang namanya sama dengan nama
		temp = x; // Simpan node saat ini ke temp
		x = x->next; // Lanjut ke node berikutnya
	}
	temp->next = x->next; // Node sebelumnya menunjuk ke node sesudahnya
	delete(x); // Menghapus node yang dicari (dealokasi memori)
}

// Fungsi untuk menampilkan semua data dalam linked list
void tampilData(){ // Fungsi tanpa parameter
	x = head; // Mulai dari node pertama
	cout << "Daftar File dalam Linked List:" << endl; // Tampilkan label
	int nomor = 1; // Variabel untuk nomor urut
	while(x != NULL){ // Selama x tidak NULL (masih ada node)
		cout << nomor << ". " << x->data.nama << "." << x->data.jenisFile << endl; // Tampilkan nomor, nama file, dan jenis file
		x = x->next; // Lanjut ke node berikutnya
		nomor++; // Tambah nomor urut
	}
}

// ======== PROGRAM UTAMA ========

int main(){ // Titik awal program
	
	int pilihan; // Variabel untuk menyimpan pilihan menu user
	string nama, jenis, namaReferensi; // Variabel untuk nama file, jenis file, dan nama referensi
	
	buatNodeAwal("dokumen", "pdf"); // Membuat node pertama dengan nama "dokumen" dan jenis "pdf"
	
	// Loop menu utama
	do{ // Mulai loop do-while (minimal dijalankan 1 kali)
		cout << "PROGRAM MANAJEMEN FILE" << endl; // Tampilkan judul
		cout << "========================" << endl; // Tampilkan garis pembatas
		cout << "Menu:" << endl; // Tampilkan judul menu
		cout << "1. Tambah File di Depan" << endl; // Pilihan 1
		cout << "2. Tambah File di Belakang" << endl; // Pilihan 2
		cout << "3. Tambah File di Tengah" << endl; // Pilihan 3
		cout << "4. Hapus File di Depan" << endl; // Pilihan 4
		cout << "5. Hapus File di Belakang" << endl; // Pilihan 5
		cout << "6. Hapus File di Tengah" << endl; // Pilihan 6
		cout << "7. Tampilkan Data" << endl; // Pilihan 7
		cout << "8. Keluar" << endl; // Pilihan 8
		cout << "Masukkan pilihan [1...8]: "; // Meminta user memasukkan pilihan
		cin >> pilihan; // Membaca pilihan dari user
		
		cout << endl; // Tampilkan baris kosong
		
		// Memproses pilihan user
		switch(pilihan){ // Memeriksa nilai pilihan
			case 1: // Jika pilihan = 1 (Tambah di depan)
				cout << "Masukkan nama file: "; // Minta user memasukkan nama file
				cin >> nama; // Baca nama file dari user
				cout << "Masukkan jenis file: "; // Minta user memasukkan jenis file
				cin >> jenis; // Baca jenis file dari user
				tambahDiDepan(nama, jenis); // Panggil fungsi tambahDiDepan dengan parameter nama dan jenis
				cout << endl; // Tampilkan baris kosong
				cout << "File berhasil ditambah di depan!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 2: // Jika pilihan = 2 (Tambah di belakang)
				cout << "Masukkan nama file: "; // Minta user memasukkan nama file
				cin >> nama; // Baca nama file dari user
				cout << "Masukkan jenis file: "; // Minta user memasukkan jenis file
				cin >> jenis; // Baca jenis file dari user
				tambahDiBelakang(nama, jenis); // Panggil fungsi tambahDiBelakang dengan parameter nama dan jenis
				cout << endl; // Tampilkan baris kosong
				cout << "File berhasil ditambah di belakang!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 3: // Jika pilihan = 3 (Tambah di tengah)
				cout << "Masukkan nama file: "; // Minta user memasukkan nama file
				cin >> nama; // Baca nama file baru dari user
				cout << "Masukkan jenis file: "; // Minta user memasukkan jenis file
				cin >> jenis; // Baca jenis file dari user
				cout << "Masukkan nama file referensi (file setelah penempatan): "; // Minta nama referensi
				cin >> namaReferensi; // Baca nama referensi dari user
				tambahDiTengah(nama, jenis, namaReferensi); // Panggil fungsi tambahDiTengah dengan parameter nama, jenis, dan namaReferensi
				cout << endl; // Tampilkan baris kosong
				cout << "File berhasil ditambah di tengah!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 4: // Jika pilihan = 4 (Hapus di depan)
				hapusDiDepan(); // Panggil fungsi hapusDiDepan (tanpa parameter)
				cout << "File di depan berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
			
			case 5: // Jika pilihan = 5 (Hapus di belakang)
				hapusDiBelakang(); // Panggil fungsi hapusDiBelakang (tanpa parameter)
				cout << "File di belakang berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 6: // Jika pilihan = 6 (Hapus di tengah)
				cout << "Masukkan nama file yang ingin dihapus: "; // Minta user memasukkan nama file
				cin >> nama; // Baca nama file dari user
				hapusDiTengah(nama); // Panggil fungsi hapusDiTengah dengan parameter nama
				cout << "File di tengah berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 7: // Jika pilihan = 7 (Tampilkan data)
				tampilData(); // Panggil fungsi tampilData untuk menampilkan semua elemen
				cout << endl; // Tampilkan baris kosong
				break; // Keluar dari switch
				
			case 8: // Jika pilihan = 8 (Keluar)
				cout << "Program Selesai!!" << endl; // Tampilkan pesan
				cout << "Selamat Tinggal!!" << endl; // Tampilkan pesan perpisahan
				cout << endl; // Tampilkan baris kosong
				break; // Keluar dari switch
				
			default: // Jika pilihan tidak sesuai dengan case manapun
				cout << "Pilihan tidak valid!" << endl; // Tampilkan pesan error
				break; // Keluar dari switch
		}
	} while(pilihan != 8); // Ulangi loop selama pilihan bukan 8 (lanjutkan selama belum pilih keluar)
	
	return 0; // Program berakhir dengan mengembalikan nilai 0 (sukses)
}