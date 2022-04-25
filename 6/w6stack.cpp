//progam stack buku
#include <iostream>
#include <iomanip>
#define max 10 
using namespace std;
//deklarasi max stack
//deklarasi bstack#
typedef struct {
	string book_title[max], author[max];
	int top=0, bottom=1;
}stack_buku;

//deklarasi variabel
stack_buku book;

bool IsFull(stack_buku X){
	if (X.top==max) return true;else return false;
};

bool IsEmpty(stack_buku X){
	if (X.top==0) return true;else return false;
}


void Push_Stack(stack_buku &X){
	cout<<"Menambahkan buku ke tumpukan"<<endl;
	//naikkan top
	X.top++;
	//isikan datanya
	cout<<"Masukkan judul buku yang ingin ditambahkan"<<endl;cin>>X.book_title[X.top];
	cout<<"Masukkan Pengarang Buku"<<endl;cin>>X.author[X.top];
	cout<<"Penambahan buku ke Stack berhasil"<<endl;
}

void Pop_Stack(stack_buku &X){
	cout<<"Mengambil buku paling atas dari stack"<<endl;
	cout<<"Judul Buku "<<X.book_title[X.top];
	cout<<"Pengarang "<<X.author[X.top];
	X.top--;//menurunkan posisi top
	cout<<"Buku sudah diambil"<<endl;
	}
	
void Print_Stack (stack_buku X){
	cout<<"Menampilkan buku yang ada di Stack buku"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Posisi	Judul			Author"<<endl;
	cout<<"--------------------------------"<<endl;
	for(int i=X.top;i>=1;i--)
		cout <<setw(2)<<i<<setw(15)<<X.book_title[i]<<setw(10)<<X.author[i]<<endl; 
	cout<<"--------------------------------"<<endl;
	cout<<"Terdapat "<<X.top<<"buku di stack buku"<<endl;
}

int main () { 
	int pil=0;
	do{
		system("cls");
		cout<<"Stack of Book"<<endl;
		cout<<"1. Tambah buku ke tumpukan"<<endl;
		cout<<"2. Ambil buku dari tumpukan"<<endl;
		cout<<"3. Cetak tumpukan buku"<<endl;
		cout<<"0. Keluar"<<endl;
		cout<<"Pilih Menu : ";cin>>pil;
		switch(pil) {
			case 1: if (IsFull(book)) cout<<"Tumpukan sudah penuh, tidak bisa ditambah lagi"<<endl;else Push_Stack(book);break;
			case 2: if (IsEmpty(book)) cout<<"Tumpukan buku sedang kosong, tidak bisa diambil"<<endl;else Pop_Stack(book);break;
			case 3: if (IsEmpty(book)) cout<<"Tidak ada buku di tumpukan, pencetakan tidak bisa dilakukan"<<endl;else Print_Stack(book);break;
			case 0: cout<<"TerimaKasih"<<endl;break;
			default: cout<<"Salah pilih menu"<<endl;
		}//case
		system("pause");
	}//do 
	while (pil != 0);
}

//BOOLEAN, MINTANYA DIDALAM KURUNG.
