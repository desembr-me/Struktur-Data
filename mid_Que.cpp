#include<iostream>
using namespace std;
#define MAX 5

struct Lagu{
	string judul;
	string penyanyi;
};

struct Que{
	int front, rear;
	Lagu data[MAX];
};

void createQue(Que &q){
	q.front=q.rear=-1;
}

bool isEmpty(Que q){
	return q.front==-1;
}

bool isFull(Que q){
	return q.rear==MAX-1;
}

void enque(Que &q, Lagu l){
	if(isFull(q)){
		cout<<"Playlist sudah penuh!"<<endl;
		return;
	}if(isEmpty(q)){
		q.front=q.rear=0;
	}
		q.data[q.rear]=l;
		q.rear++;
		cout<<"Lagu '"<<l.judul<<"' berhasil dimasukkan kedalam Playlist";
		cout<<endl;
}


void deque(Que &q){
	if(isEmpty(q)){
		cout<<"Tidak ada lagu didalam Playlist!"<<endl;
		return;
	}else{
		cout<<"Lagu "<<q.data[q.front].judul<<" berhasil dihapus"<<endl;
		q.front++;
	}
}

void tampil(Que q){
	if(isEmpty(q)){
		cout<<"Playlist kosong!"<<endl;
	}else{
		cout<<"Daftar lagu dalam playlist: "<<endl;
		for(int i=q.front;i<q.rear;i++){
			cout<<"~ "<<q.data[i].judul<<"-"<<q.data[i].penyanyi<<endl;
		}cout<<endl;
	}
}

int main(){
	Que playlist;
	createQue(playlist);
	
	Lagu l;
	int pilihan;
	
	do{
		cout<<"PROGRAM DAFTAR LAGU DI PLAYLIST"<<endl;
		cout<<"================================="<<endl;
		cout << "1. Tambah Lagu ke Playlist (Enqueue)\n";
        cout << "2. Hapus lagu (Dequeue)\n";
        cout << "3. Tampilkan daftar Lagu\n";
        cout << "4. Kosongkan Playlist\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu [1-5]: ";
        cin >> pilihan;
        cout<<endl;
        
        switch(pilihan){
        	case 1:
        		cin.ignore();
        		cout<<"Judul lagu   : ";
        		getline (cin, l.judul);
        		cout<<"Nama penyanyi: ";
        		getline (cin, l.penyanyi);
        		enque(playlist,l);
        		cout<<endl;
        		break;
        	case 2:
        		deque(playlist);
        		cout<<endl;
        		break;
        	case 3:
        		tampil(playlist);
        		cout<<endl;
        		break;
        	case 4:
        		createQue(playlist);
        		cout<<"Playlist berhasil dikosongkan!"<<endl;
        		cout<<endl;
        		break;
        	case 5:
        		cout<<"Program Selesai!!"<<endl;
        		cout<<"Selamat Tinggal!!"<<endl;
        		break;
		}
	}while(pilihan != 5);
}