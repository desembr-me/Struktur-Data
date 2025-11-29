#include<iostream>
using namespace std;
#define MAX 5

struct Stack{
	int top;
	int elemen[MAX];
};

void createStack (Stack &stack){
	stack.top= -1;
	
}
//pengecekan jika full
bool isFull( Stack stack){
	return stack.top== MAX-1;
		
}
//pengecekan jika kosong
bool isEmpty (Stack stack){
	return stack.top==-1;
	
}
//push
void push(Stack &stack, int i){
	stack.top++;
	stack.elemen[stack.top]=i;
}
//pop
void pop(Stack &stack,int &i){
	i =stack.elemen[stack.top];
	stack.top--;
}
// show elemen
void showStack(Stack stack){
	if (isEmpty(stack)){
		cout<<"Kosong "<<endl;
	}
	else{
		for(int i=0;i<=stack.top;i++){
			cout<<stack.elemen[i]<<" ";
		}
	}cout<<endl;
}

int main (){
	
	Stack A;
	int pilihan;
	int nilai;
	
	createStack (A);
	
	cout<<"Implementasi Stack dengan Array"<<endl;
	cout<<"================================="<<endl;
	cout<<endl;
	
	
	do{
		cout<<"Menu:"<<endl;
		cout<<"1.Push data"<<endl;
		cout<<"2.Pop data"<<endl;
		cout<<"3.Tampilkan Isi Stack"<<endl;
		cout<<"4.Kosongkan Stack"<<endl;
		cout<<"5.Keluar"<<endl;
		cout<<"Masukkan pilihan [1...5]: ";
		cin>>pilihan;
		
		cout<<endl;
		
		switch(pilihan){
			case 1:
				if(isFull(A)){
					cout<<"Sudah Penuh!"<<endl;
				}else{
					cout<<"Masukkan data yang ingin ditambah: ";
					cin>>nilai;
					push(A,nilai);
					cout<<"Data "<<nilai<<" berhasil ditambahkan!"<<endl;
				}
				cout<<endl;
				break;
			case 2:
				if(isEmpty(A)){
					cout<<"Stack kosong"<<endl;
				}else{
					pop(A, nilai);
					cout<<"Data berhasil di pop ";
				}
				cout<<endl;
				
				break;
			case 3:
				cout<<"Isi Stack saat ini"<<endl;
				showStack(A);
				cout<<endl;
				
				break;
			case 4:
				createStack(A);
				cout<<"Stack sekarang kosong!"<<endl;
				cout<<endl;
				break;
				
			case 5:
				cout<<"Program Selesai"<<endl;
				cout<<"Selamat Tinggal!!!!"<<endl;
				break;
				
			default:
				cout<<"Pilihan tidak valid!"<<endl;
				break;
				
		}
	} while(pilihan != 5);
cout<<endl;
}