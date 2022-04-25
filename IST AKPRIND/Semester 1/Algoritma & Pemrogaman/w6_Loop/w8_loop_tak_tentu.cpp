//loop tak tentu 
//w8 inf
#include <iostream>
using namespace std;

int a,b;

int main () {
	cout << "Uji coba Loop tak tentu dengan while do"<<endl;
	a=1
	while (a <= 10) {
		cout << "Bilangan tercetak"<<a<<" "<<endl;
		a+=2;
		}
	cout<<"\nSekarang sdh di luar blok"<<endl;
	}

void tambah_barang(larik_barang &X){
	string barang_baru;
	cout<<"Tambah barang baru\n";
	ulang:
	cout<<"Masukkan kode barang baru : ";cin>>barang_baru;
	//validasi
	for(i=1;i<=n;i++){
		if(X[i].kode_brg==barang_baru){cout<<"Kode sudah digunakan, ulangi\n";goto ulang;}
		}
	//sudah valid
	n++;
	X[n].kode_brg=barang_baru;
	cout<<"Masukkan nama barang = ";cin>>X[n].nama;
	cout<<"Masukkan harga barang = ";cin>>X[n].harga;
	cout<<"Masukkan stok awal    = ";cin>>X[n].stok;
	cout<<"Input berhasil\n";
	}
