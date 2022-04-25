
#include <iostream>
#define max 10
using namespace std;

typedef int matriks[max][max];

void isi_matriks(matriks M, int kolom, int baris){
	for (int index=0; index < kolom; index++)
	{
		for (int index_j = 0; index_j < baris; index_j++)
		{
		cout << "Masukin elemen ke " << index << " dan" << index_j << " = ";
		cin >> M[index][index_j];
		}
	}
}

void menampilkan_matriks(matriks M, int kolom, int baris){
	cout <<"Jumlah Mahasiswa\n";
	cout<<"Tahun : ";
	for(int index=0; index<1; index++){
		for(int index_j=0; index_j<kolom; index_j++){cout<<M[index][index_j]<<" | ";}
		cout<<"\n"<<endl;
	}
	cout<<"Informatika : ";
	for(int index=0; index<1; index++){
		for(int index_j=0; index_j<kolom; index_j++){cout<<M[index][index_j]<<" | ";}
		cout<<"\n"<<endl;
	}
	cout<<"Kimia : ";
	for(int index=0; index<1; index++){
		for(int index_j=0; index_j<kolom; index_j++){cout<<M[index][index_j]<<" | ";}
		cout<<"\n"<<endl;		
	}
}	
		
int main () {
	matriks M;
	
	int kolom, baris, pil;
do {	
system("cls");
 cout<<"Daftar Mahasiswa"<<endl;
 cout<<"1. Input\n";
 cout<<"2. Cetak\n";
 cout<<"0. Keluar"<<endl;
 cout<<"Pilih ";cin>>pil;
 switch(pil){
		case 1 :
		cout<<"Mengisi matriks"<<endl;
		cout<<"Masukkan baris : ";cin>>baris;
		cout<<"Masukkan kolom : ";cin>>kolom;
		isi_matriks(M, baris, kolom);
		break;
		case 2 :
		menampilkan_matriks(M, baris, kolom);;
		break;
		case 0 :
		cout<<"Terimakasih"<<endl;
		break;
		default:cout<<"Anda salah pilih \n";
		}
		system("pause");
	} while(pil!=0);
}


