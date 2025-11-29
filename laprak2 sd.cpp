#include <iostream> // Mengimpor library iostream untuk input-output
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std:: di setiap perintah

// Mendefinisikan struktur Node untuk linked list
struct Node{
	int data; // Variabel untuk menyimpan nilai data
	Node *next; // Pointer untuk menunjuk ke node berikutnya
};

// Deklarasi pointer global
Node *n=NULL; // Pointer n untuk node baru yang akan dibuat
Node *head=NULL; // Pointer head menunjuk ke node pertama (awal list)
Node *tail=NULL; // Pointer tail menunjuk ke node terakhir (akhir list)
Node *x=NULL; // Pointer x untuk proses traversal (perjalanan) dalam list

// ======== FUNGSI-FUNGSI OPERASI LINKED LIST ========

// Fungsi untuk membuat node pertama (node awal)
void buatNodeAwal(int i){ // Parameter i adalah nilai data yang disimpan
	n = new Node; // Alokasi memori baru untuk node
	n->data = i; // Menyimpan nilai i ke dalam data node
	n->next = NULL; // Mengatur pointer next ke NULL (tidak ada node berikutnya)
	tail = n; // tail menunjuk ke node pertama
	head = n; // head menunjuk ke node pertama
}

// Fungsi untuk menambah node di posisi belakang
void tambahDiBelakang(int i){ // Parameter i adalah nilai data yang akan ditambahkan
	n = new Node; // Alokasi memori baru untuk node
	n->data = i; // Menyimpan nilai i ke dalam data node
	tail->next = n; // Menghubungkan node terakhir dengan node baru
	tail = n; // Menggeser tail ke node baru (sekarang menjadi node terakhir)
	tail->next = NULL; // Mengatur pointer next node terakhir ke NULL
}

// Fungsi untuk menambah node di posisi depan
void tambahDiDepan(int i){ // Parameter i adalah nilai data yang akan ditambahkan
	n = new Node; // Alokasi memori baru untuk node
	n->data = i; // Menyimpan nilai i ke dalam data node
	n->next = head; // Menghubungkan node baru dengan node pertama lama
	head = n; // Menggeser head ke node baru (sekarang menjadi node pertama)
}

// Fungsi untuk menambah node di posisi tengah
void tambahDiTengah(int i, int j){ // i = nilai baru, j = nilai node setelah posisi penyisipan
	x = head; // Mulai dari node pertama
	while(x->data != j) x = x->next; // Cari node yang datanya sama dengan j
	n = new Node; // Alokasi memori baru untuk node
	n->data = i; // Menyimpan nilai i ke dalam data node
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
void hapusDiTengah(int i){ // Parameter i adalah nilai data node yang akan dihapus
	Node *temp = NULL; // Pointer temp untuk menyimpan node sebelumnya
	x = head; // Mulai dari node pertama
	while(x->data != i){ // Cari node yang datanya sama dengan i
		temp = x; // Simpan node saat ini ke temp
		x = x->next; // Lanjut ke node berikutnya
	}
	temp->next = x->next; // Node sebelumnya menunjuk ke node sesudahnya
	delete(x); // Menghapus node yang dicari (dealokasi memori)
}

// Fungsi untuk menampilkan semua data dalam linked list
void tampilData(){ // Fungsi tanpa parameter
	x = head; // Mulai dari node pertama
	while(x != NULL){ // Selama x tidak NULL (masih ada node)
		cout << x->data << " "; // Tampilkan data node saat ini
		x = x->next; // Lanjut ke node berikutnya
	}
}

// ======== PROGRAM UTAMA ========

int main(){ // Titik awal program
	
	int pilihan; // Variabel untuk menyimpan pilihan menu user
	int i, j; // i untuk nilai baru, j untuk nilai referensi
	
	buatNodeAwal(10); // Membuat node pertama dengan nilai 10
	
	cout << "Implementasi Program Single Linked List" << endl; // Tampilkan judul
	cout << "=================================" << endl; // Tampilkan garis pembatas
	
	// Loop menu utama
	do{ // Mulai loop do-while (minimal dijalankan 1 kali)
		cout << endl; // Tampilkan baris kosong
		cout << "Menu:" << endl; // Tampilkan judul menu
		cout << "1. Tambah di depan" << endl; // Pilihan 1
		cout << "2. Tambah di belakang" << endl; // Pilihan 2
		cout << "3. Tambah di tengah" << endl; // Pilihan 3
		cout << "4. Hapus di depan" << endl; // Pilihan 4
		cout << "5. Hapus di belakang" << endl; // Pilihan 5
		cout << "6. Hapus di tengah" << endl; // Pilihan 6
		cout << "7. Tampilkan data" << endl; // Pilihan 7
		cout << "8. Keluar" << endl; // Pilihan 8
		cout << "Masukkan pilihan [1...8]: "; // Meminta user memasukkan pilihan (perbaikan: ganti 5 jadi 8)
		cin >> pilihan; // Membaca pilihan dari user
		
		cout << endl; // Tampilkan baris kosong
		
		// Memproses pilihan user
		switch(pilihan){ // Memeriksa nilai pilihan
			case 1: // Jika pilihan = 1 (Tambah di depan)
				cout << "Masukkan nilai yang ingin ditambah: "; // Minta user memasukkan nilai
				cin >> i; // Baca nilai dari user
				tambahDiDepan(i); // Panggil fungsi tambahDiDepan dengan parameter i
				cout << endl; // Tampilkan baris kosong
				cout << "Data berhasil ditambah di depan!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 2: // Jika pilihan = 2 (Tambah di belakang)
				cout << "Masukkan nilai yang ingin ditambah: "; // Minta user memasukkan nilai
				cin >> i; // Baca nilai dari user
				tambahDiBelakang(i); // Panggil fungsi tambahDiBelakang dengan parameter i
				cout << endl; // Tampilkan baris kosong
				cout << "Data berhasil ditambah di belakang!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 3: // Jika pilihan = 3 (Tambah di tengah)
				cout << "Masukkan nilai yang ingin ditambah: "; // Minta user memasukkan nilai
				cin >> i; // Baca nilai baru dari user
				cout << "Masukkan nilai posisi (data setelah penempatan): "; // Minta nilai referensi
				cin >> j; // Baca nilai referensi dari user (perbaikan: pemisahan input lebih jelas)
				tambahDiTengah(i, j); // Panggil fungsi tambahDiTengah dengan parameter i dan j
				cout << endl; // Tampilkan baris kosong
				cout << "Data berhasil ditambah di tengah!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 4: // Jika pilihan = 4 (Hapus di depan)
				hapusDiDepan(); // Panggil fungsi hapusDiDepan (tanpa parameter)
				cout << "Data di depan berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
			
			case 5: // Jika pilihan = 5 (Hapus di belakang)
				hapusDiBelakang(); // Panggil fungsi hapusDiBelakang (tanpa parameter)
				cout << "Data di belakang berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 6: // Jika pilihan = 6 (Hapus di tengah)
				cout << "Masukkan nilai yang ingin dihapus: "; // Minta user memasukkan nilai
				cin >> i; // Baca nilai dari user
				hapusDiTengah(i); // Panggil fungsi hapusDiTengah dengan parameter i
				cout << "Data di tengah berhasil dihapus!!" << endl; // Tampilkan pesan sukses
				break; // Keluar dari switch
				
			case 7: // Jika pilihan = 7 (Tampilkan data)
				cout << "Data saat ini: "; // Tampilkan label
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