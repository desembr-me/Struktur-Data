#include<iostream>
using namespace std;

struct Biodata{
	int id;
	string nama;
	string alamat;
};

struct Node{
	Biodata data;
	Node *prev;
	Node *next;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void nodeBaru(int i, string j, string y){
	n= new Node;
	n->data.id = i;
	n->data.nama=j;
	n->data.alamat;
	n->prev= NULL;
	tail=n;
	head=n;
	n->next=NULL;
}

void tambahBelakang(int i, string j, string y){
	n=new  Node;
	n->data.id = i;
	n->data.nama=j;
	n->data.alamat;
	tail->next=n;
	n->next=NULL;
	n->prev=tail;
	tail=n;
}

void tambahDepan(int i, string j, string y){
	n=new Node;
	n->data.id = i;
	n->data.nama=j;
	n->data.alamat;
	head->prev=n;
	n->next=head;
	head=n;
	head->prev=NULL;
}


void hapusDepan(){
	x=head;
	head=x->next;
	head->prev=NULL;
	delete(x);
	x=NULL;
}

void hapusBelakang(){
	x=tail;
	tail=x->prev;
	tail->next=NULL;
	delete(x);
	x=NULL;
}

void tampilDepan(){
	x=head;
	while (x  != NULL){
		cout<<"ID: "<<x->data.id<<endl;
		cout<<"Nama: "<<x->data.nama<<endl;
		cout<<"Alamat: "<<x->data.alamat<<endl;
		cout<<"================================="<<endl;
		x=x->next;
	}
}

void  tampilBelakang(){
	x=tail;
	while(x != NULL){
		cout<<"ID: "<<x->data.id<<endl;
		cout<<"Nama: "<<x->data.nama<<endl;
		cout<<"Alamat: "<<x->data.alamat<<endl;
		cout<<"================================="<<endl;
		x=x->prev;
	}
}

int main(){
	
	int id,  pilihan;
	string nama;
	string alamat;
	
	do{
		cout<<"====DOUBLE LINKED LIST: BIODATA===="<<endl;
		cout<<"1. Tambah data awal"<<endl;
		cout<<"2. Tamabah depan"<<endl;
		cout<<"3. Tambah belakang"<<endl;
		cout<<"4. Hapus depan"<<endl;
		cout<<"5. Hapus belakang"<<endl;
		cout<<"6. Tampil dari depan"<<endl;
		cout<<"7. Tampil dari belakang"<<endl;
		cout<<"8. keluar"<<endl;
		cout<<"==================================="<<endl;
		cout<<"Masukkan pilihan: "; cin>>pilihan;
		
		
		
		switch(pilihan){
			case 1:
				cout<<"ID: "; cin>>id;
				cin.ignore();
				cout<<"nama: "; 
				getline (cin, nama);
				cout<<"alamat: ";  
				getline (cin, alamat);
				nodeBaru(id, nama, alamat);
				cout<<"Berhasil menambah node baru!"<<endl<<endl;
				break;
			case 2:
				cout<<"ID: "; cin>>id;
				cin.ignore();
				cout<<"nama: "; 
				getline (cin, nama);
				cout<<"alamat: ";  
				getline (cin, alamat);
				tambahDepan(id, nama, alamat);
				cout<<"Berhasil menambah node baru!"<<endl<<endl;
				break;
			case 3:
				cout<<"ID: "; cin>>id;
				cin.ignore();
				cout<<"nama: "; getline (cin, nama);
				cout<<"alamat: ";  getline (cin, alamat);
				tambahBelakang(id, nama, alamat);
				cout<<"Berhasil menambah node baru!"<<endl<<endl;
				break;
			case 4:
				hapusDepan();
				cout<<"Node depan berhasil dihapus"<<endl<<endl;
				break;
			case 5:
				hapusBelakang();
				cout<<"Node depan berhasil dihapus"<<endl<<endl;
				break;
			case 6:
				tampilDepan();
				break;
			case 7:
				tampilBelakang();
				break;
			case  8: 
				cout<<"selamat tinggal!!"<<endl;
				break;
		}
		
	}while (pilihan != 8);
	
}

















