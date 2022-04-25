//Progam soal no 3
//Muhammad Zidan Rifqi Ramadhan
//211055002
#include <iostream>
using namespace std;

int bb,bt,hj,jml,laba,untung,rugibesar,rugi,impas,a;
string nama;

int main () {
	
	cout << "Masukkan Nama : ";cin>>nama;
	cout<<" Masukkan Biaya bahan baku : ";cin>>bb;
	cout<<" Masukkan Biaya tambahan : ";cin>>bt;
	cout<<" Masukkan Harga Jual : ";cin>>hj;
	cout<<" Jumlah produk terjual : ";cin>>jml;
	
	cout << "Kategori Dagangan "<<nama <<" adalah = ";
	if((bb+bt) > (hj*jml)) {cout<<"Untung"<<endl;}
	else if((bb+bt) < (hj*jml)) {cout<<"Rugi"<<endl;}
	else if((bb+bt) == (hj*jml)) {cout<<"Impas"<<endl;}
	
	cout << "Dan "<<nama <<" Mendapatkan ";
	if((hj*jml) - (bb+bt)) {cout<<"Laba"<<endl;}
		else if ((bb+bt) - (hj*jml)) {cout<<"Rugi"<<endl;}
	
	}
