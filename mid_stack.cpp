#include<iostream>
using namespace std;
#define MAX 5

struct File{
	string nama;
	string jenisFile;
};

struct Stack{
	File data[MAX];
	int top;
	
};

void createStack(Stack &s){
	s.top=-1;
}

bool isEmpty(Stack s){
	return s.top==-1;
}

bool isFull(Stack s){
	return s.top == MAX-1;
}

void push (Stack &s, File f){
	if(isFull(s)){
		cout<<"Stack penuh "<<endl;
	} else{
	s.top++;
	s.data[s.top]=f;
	cout<<f.nama<<" berhasil ditambahkan"<<endl;
	}
}

void pop (Stack &s){
	if(isEmpty(s)){
		cout<<"Tidak ada file"<<endl;
	}else{
	cout<<s.data[s.top].nama<<" berhasil dihapus"<<endl;
	s.top--;
	}
}

void tampil(Stack s){
	if(isEmpty(s)){
		cout<<"Tidak ada file"<<endl;
	}else{
	cout<<"Daftar file yang ada dalam stack: "<<endl;
	for(int i=s.top;i>=0;i--){
		cout<<"- "<<s.data[i].nama<<"."<<s.data[i].jenisFile<<endl;
		}
	}
}

int main(){
	Stack tumpukanFile;
	createStack(tumpukanFile);
	File f;
	int pilihan;
	
	do{
		cout<<"PROGRAM TUMPUKAN FILE"<<endl;
		cout<<"====================="<<endl;
		cout<<"1.Tambah file"<<endl;
		cout<<"2.Hapus file"<<endl;
		cout<<"3.Tampilkan tumpukan file"<<endl;
		cout<<"4.Kosongkan tumpukan file"<<endl;
		cout<<"5.Keluar"<<endl;
		cout<<"Pilihan Menu [1-5] : ";
		cin>>pilihan;
		cout<<endl;
		
		switch(pilihan){
			case 1:
				cout<<"Nama file : ";
				cin>>f.nama;
				cout<<"Jenis file: ";
				cin>>f.jenisFile;
				push(tumpukanFile,f);
				cout<<endl;
				break;
			case 2:
				pop(tumpukanFile);
				cout<<endl;
				break;
			case 3:
				tampil(tumpukanFile);
				cout<<endl;
				break;
			case 4: 
				createStack(tumpukanFile);
				cout<<"Tumpukan file berhsil dikosongkan"<<endl;
				cout<<endl;
				break;
			case 5:  
				cout<<"Program Selesai!!"<<endl;
				cout<<"Selamat Tinggal!!"<<endl;
		}
	}while(pilihan !=5);
	return 0;
}