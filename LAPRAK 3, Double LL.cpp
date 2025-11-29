#include<iostream>
using namespace std;

struct Node{
	string data;
	Node *next;
	Node *prev;
	
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(string i){
	n=new Node;
	n->data=i;
	n->prev=NULL;
	head=n;
	tail=n;
	tail->next=NULL;
}

void tambahDiBelakang(string i){
	n=new Node;
	n->data=i;
	n->prev=tail;
	tail->next=n;
	tail=n;
	tail->next=NULL;
}

void tambahDiDepan(string i){
	n=new Node;
	n->data=i;
	n->next=head;
	head->prev=n;
	n->prev=NULL;
	head=n;
}

void tambahDiTengah(string i, string j){
	x=head;
	while(x->data !=j) x=x->next;
	n=new Node;
	n->data=i;
	n->next =x->next;
	x->next=n;
	n->prev=x;
	x=n->next;
	x->prev=n;
}

void hapusDiDepan(){
	x=head;
	head=x->next;
	head->prev=NULL;
	delete(x);
	x=NULL;

}

void hapusDiBelakang(){
	x=tail;
	tail=tail->prev;
	tail->next=NULL;
	delete(x);
	x=NULL;
}

void hapusDiTengah(string i){
	n=NULL;
	x=head;
	while (x->data !=i){
		n=x;
		x=x->next;
	}
	n->next=x->next;
	x=x->next;
	delete(x->prev);
	x->prev=n;
}

void tampilDariDepan(){
	x=head;
	while(x !=NULL){
		cout<<"- "<<x->data<<endl;
		x=x->next;
	}
}

void tampilDariBelakang(){
	x=tail;
	while(x != NULL){
		cout<<"- "<<x->data<<endl;
		x=x->prev;
	}
}

int main(){
	int pilihan;
	string lagu, setelahLagu;
	bool pertama = true;
	
	do{
		cout<<"===PLAYLIST MUSIK [Mekar Wangi R_206]==="<<endl;
		cout<<"1.Tambah lagu di depan"<<endl; 
		cout<<"2.Tambah lagu di belakang"<<endl; 
		cout<<"3.Tambah lagu setelah lagu tertentu"<<endl;
		cout<<"4.Hapus lagu pertama"<<endl;
		cout<<"5.Hapus lagu terakhir"<<endl;
		cout<<"6.Hapus lagu tertentu"<<endl; 
		cout<<"7.Tampilkan playlist dari awal"<<endl;
		cout<<"8.Tampilkan playlist dari akhir"<<endl;
		cout<<"9.Keluar"<<endl;
		cout<<"Pilih menu [1...9]: ";
		cin>>pilihan;
		cin.ignore();
		cout<<endl;
		
		switch(pilihan){
			case 1:
				cout<<"Masukkan judul lagu: ";
				getline(cin, lagu);
				if (pertama){
					buatNodeBaru(lagu);
					pertama=false;
				}else{
				tambahDiDepan(lagu);
				}
				cout<<"Lagu berhasil di tambahkan di depan!"<<endl<<endl;
				break;
			case 2:
				cout<<"Masukkan judul lagu: ";
				getline(cin, lagu);
				tambahDiBelakang(lagu);
				cout<<"Lagu berhasil di tambahkan di belakang!"<<endl<<endl;
				break;
			case 3:
				cout<<"Masukkan judul lagu: ";
				getline (cin, lagu);
				cout<<"setelah lagu: ";
				getline (cin, setelahLagu);
				tambahDiTengah(lagu, setelahLagu);
				cout<<"Lagu berhasil di tambahkan di Tengah!"<<endl<<endl;
				break;
			case 4:
				hapusDiDepan();
				cout<<"Lagu pertama berhasil dihapus dari playlist!"<<endl<<endl;
				break;
			case 5:
				hapusDiBelakang();
				cout<<"Lagu terakhir berhasil dihapus dari playlist!"<<endl<<endl;
				break;
			case 6:
				cout<<"Masukkan judul lagu yang ingin dihapus: ";
				getline (cin, lagu);
				hapusDiTengah(lagu);
				cout<<"Lagu berhasil dihapus dari playlist!"<<endl<<endl;
				break;
			case 7:
				cout<<"Menampilkan playlist dari awal: "<<endl;
				tampilDariDepan();
				cout<<endl;
				break;
			case 8:
				cout<<"Menampilkan playlist dari akhir: "<<endl;
				tampilDariBelakang();
				cout<<endl;
				break;
			case 9:
				cout<<"Program Selesai!!"<<endl;	
				break;
				
			default :
				cout<<"pilihan tidak valid!!"<<endl;
				break;
				
		}
	}while (pilihan != 9);
	
	
	
}
