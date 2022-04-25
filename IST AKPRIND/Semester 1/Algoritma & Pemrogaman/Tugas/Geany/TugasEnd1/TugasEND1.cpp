//nama anggota
// I Wayan Julianta
// Muhammad Zidan Rifqi Ramadhan
// Darrenesia

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
	string kode_produk,nama;
	float harga; int stok;
}rec_produk; 

typedef rec_produk larik_produk[30];
larik_produk produk;
int n,i,pil;

void tambah_produk(larik_produk &X){
	string produk_baru;
	cout<<"Tambah produk baru\n";
	ulang:
	cout<<"Masukkan kode produk baru : ";cin>>produk_baru;
	for(i=1;i<=n;i++){
		if(X[i].kode_produk==produk_baru){cout<<"Kode sudah digunakan, ulangi\n";goto ulang;}
		}
	n++;
	X[n].kode_produk=produk_baru;
	cout<<"Masukkan nama produk = ";cin>>X[n].nama;
	cout<<"Masukkan harga produk = ";cin>>X[n].harga;
	cout<<"Masukkan stok awal    = ";cin>>X[n].stok;
	cout<<"Input berhasil\n";
	}

void cetak_produk(larik_produk &X){
	cout<<"Daftar Produk di Gudang saat ini\n";
	cout<<"--------------------------------\n";
	cout<<"No Kode Nama Harga Stok\n";
	cout<<"--------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(6)<<X[i].kode_produk<<setw(20)<<X[i].nama<<setw(8)
		<<X[i].harga<<setw(6)<<X[i].stok<<endl;
	cout<<"--------------------------------\n";
	}
	
void edit_produk(larik_produk &X){
	string edit; int pos, pilih, tambah_stok;bool ada = false;
	cetak_produk(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan kode produk yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
		if(X[i].kode_produk==edit){pos=i;ada=true;}
		}
	//jika ketemu
	if(ada){
		cout<<"Anda akan mengedit Kode Produk"<<edit<<"\n";
		cout<<"Posisi di record nomor : "<<pos<<"\n";
		cout<<"Nama produk  : "<<X[pos].nama<<"\n";
		cout<<"Harga produk  : "<<X[pos].harga<<"\n";
		cout<<"Stok saat ini  : "<<X[pos].stok<<"\n";
		cout<<"Anda bisa mengedit Harga produk dan menambahkan stok\n";
		cout<<"1. Edit Harga 2. Tambah Stok\n";cin>>pilih;
		
	if(pilih==1){
		cout<<"Masukkan harga yang baru Rp ";cin>>X[pos].harga;
		}
	else if (pilih==2){
		cout<<"Masukkan tambahan stok ";cin>>tambah_stok;
		X[pos].stok=X[pos].stok+tambah_stok;
		}
	else cout<<"Salah Pilih\n";
	cout<<"Editing sudah dilakukan\n";
	}
else cout<<"Kode produk "<<edit<<"tidak ditemukan,editing gagal\n";
	}
	
void hapus_produk(larik_produk &X){
	int hapus; char ya;
	cetak_produk(X);
	cout<<"Manghapus data produk\n";
	ulang:
	cout<<"Masukkan nomor record yang akan dihapus : ";cin>>hapus;
	if((hapus<1) || (hapus>n)) {
		cout<<"Nomor record tidak valid, ulangi !\n";goto ulang;}
	//sudah valid
	cout<<"Yakin akan dihapus<y/t>?";cin>>ya;
	if((ya=='Y') || (ya=='y')){
		cout<<"Data telah dihapus"<<endl;
		for(i=hapus;i<n;i++)X[i]=X[i+1];
		n--;//kurangi jumlah record
		}
	else cout << "Data tidak jadi dihapus \n";
	}


int main () {
		
	do{
		system("cls");
		cout<<"Pengelolaan Data Barang"<<endl;
		cout<<"1. Input Barang\n";
		cout<<"2. Cetak Barang\n";	
		cout<<"3. Edit data barang\n";
		cout<<"4. Hapus Barang\n";
		cout<<"5. Cek Harga Barang\n";
		cout<<"6. Transaksi\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n>2)cout<<"Sudah penuh \n";else tambah_barang(barang);break;
			case 2:if(n==10)cout<<"Gudang masih kosong \n";else cetak_barang(barang);break;
			case 3:if(n==10)cout<<"Gudang masih kosong \n";else edit_barang(barang);break;
			case 4:if(n==10)cout<<"Gudang masih kosong \n";else hapus_barang(barang);break;
			case 5:if(n==10)cout<<"Gudang masih kosong \n";else cari_barang(barang);break;
			case 6:if(n==10)cout<<"Gudang masih kosong \n";else penjualan(barang);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
		system("pause");
	 
	}while(pil!=0);
		
	}
