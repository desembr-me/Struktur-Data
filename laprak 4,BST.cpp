#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node *right;
	Node *left;
};

Node *root=NULL, *n=NULL, *temp=NULL;

Node *createNode(int data){
	n=new Node;
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void insert(Node *&root, int data){
	if(root==NULL)
		root=createNode(data);
	else if (data <= root->data)
		insert(root->left,data);
	else if(data>root->data)
		insert(root->right,data);
}

void levelOrder(Node *root){
	if(root==NULL)return;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		cout<<q.front()->data<<" ";
		if(q.front()->left !=NULL)
			q.push(q.front()->left);
		if(q.front()->right !=NULL)
			q.push(q.front()->right);
		q.pop();
	}
}

void preOrder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root){
	if(root==NULL)return;
	inOrder (root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node *root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

bool cari(Node *root,  int data){
	if (root==NULL)
		return false;
	else if(data<root->data)
		return cari(root->left,data);
	else if(data> root->data)
		return cari(root->right,data);
	else
		return true;
}

Node *cariMin(Node *root){
	if(root==NULL)
		return NULL;
	while (root->left !=NULL)
		root=root->left;
	return root;
}

void hapus(Node *&root, int data){
	if(root==NULL)
		return;
	else if(data<root->data)
		return hapus(root->left,data);
	else if(data>root->data)
		return hapus(root->right,data);
	else{
		//Kasus 1
		if(root->left==NULL&&root->right==NULL){
			delete(root);
			root=NULL;
		}
		//Kasus 2
		else if(root->left==NULL){
			temp=root;
			root=root->right;
			delete(temp);
			temp=NULL;
		}
		else if(root->right==NULL){
			temp=root;
			root=root->left;
			delete(temp);
			temp=NULL;
		}
		//Kasus 3
		else{
			temp=cariMin(root->right);
			root->data=temp->data;
			hapus(root->right,root->data);
		}
	}
}

int main(){
	int pilihan,nilai,pilih_BST;
	Node *root=NULL;

	do{	
	cout<<"===BINARY SEARCH TREE==="<<endl<<endl;
	cout<<"1. Insert Node"<<endl;
	cout<<"2. Pencarian Data"<<endl;
	cout<<"3. Hapus Node"<<endl;
	cout<<"4. Binary Search Traversal"<<endl;
	cout<<"5. Keluar"<<endl;
	cout<<"Pilihan Menu [1...5]: ";
	cin>>pilihan;
	cout<<endl;
	

		switch(pilihan){
			case 1:
				cout<<"Masukkan data yang ingin ditambahkan : ";
				cin>>nilai;
				insert(root,nilai);
				cout<<"Data berhasil ditambahkan"<<endl<<endl;
				break;
			case 2:
				cout<<"Masukkan data yang ingin dicari: ";
				cin>>nilai;
				if(cari(root, nilai)){ 
					cout<<"Data ditemukan!"<<endl<<endl;
				}
				else{
					cout<<"Data tidak ditemukan!"<<endl<<endl;
				}
				break;
			case 3:
				cout<<"Masukkan data yang ingin dihapus: ";
				cin>>nilai;
				hapus(root,nilai);
				cout<<"Data berhasil dihapus"<<endl<<endl;
				break;
			case 4:
				cout<<"Menu Binary Search Traversal:"<<endl;
				cout<<"1. Level Order"<<endl;
				cout<<"2. Preorder"<<endl;
				cout<<"3. Inorder"<<endl;
				cout<<"4. Postorder"<<endl;
				cout<<"Pilih Menu[1...4]: ";
				cin>>pilih_BST;
				cout<<endl;
				switch(pilih_BST){
					case 1:
						cout<<"Level Order: ";
						levelOrder(root);
						cout<<endl<<endl;
						break;
					case 2:
						cout<<"Preorder: ";
						preOrder(root);
						cout<<endl<<endl;
						break;
					case 3:
						cout<<"Inorder: ";
						inOrder(root);
						cout<<endl<<endl;
						break;
					case 4:
						cout<<"Postorder: ";
						postOrder(root);
						cout<<endl<<endl;
						break;
					default:
						cout<<"Piilihan Tidak Valid!"<<endl;
						break;
				}
				break;
			case 5:
				cout<<"Program Selesai!!"<<endl;
				break;
			default:
				cout<<"Pilihan Tidak valid!!"<<endl;
				break;
		}
	}while (pilihan  != 5);
}