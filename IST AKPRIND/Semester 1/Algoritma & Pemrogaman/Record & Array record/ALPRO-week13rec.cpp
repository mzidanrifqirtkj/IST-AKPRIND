//week 13 record dan array record
#include <iostream>
#include <iomanip>
using namespace std;
typedef struct{
	string kode_brg,nama;
	float harga; int stok;
}rec_barang; //deklarasi type data record

typedef rec_barang larik_barang[20];//deklarasi larik
//deklarasi variabel
larik_barang barang;
int n,i,pil;

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

void cetak_barang(larik_barang &X){
	cout<<"Daftar Barang di Gudang saat ini\n";
	cout<<"--------------------------------\n";
	cout<<"No Kode Nama Harga Stok\n";
	cout<<"--------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(6)<<X[i].kode_brg<<setw(20)<<X[i].nama<<setw(8)
		<<X[i].harga<<setw(6)<<X[i].stok<<endl;
	cout<<"--------------------------------\n";
	}
	
void edit_barang(larik_barang &X){
	string edit; int pos, pilih, tambah_stok;bool ada = false;
	cetak_barang(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan kode barang yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
		if(X[i].kode_brg==edit){pos=i;ada=true;}
		}
	//jika ketemu
	if(ada){
		cout<<"Anda akan mengedit Kode Barang"<<edit<<"\n";
		cout<<"Posisi di record nomor : "<<pos<<"\n";
		cout<<"Nama barang  : "<<X[pos].nama<<"\n";
		cout<<"Harga barang  : "<<X[pos].harga<<"\n";
		cout<<"Stok saat ini  : "<<X[pos].stok<<"\n";
		cout<<"Anda bisa mengedit Harga barang dan menambahkan stok\n";
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
else cout<<"Kode barang "<<edit<<"tidak ditemukan,editing gagal\n";
	}
	
void hapus_barang(larik_barang &X){
	int hapus; char ya;
	cetak_barang(X);
	cout<<"Manghapus data barang\n";
	ulang:
	cout<<"Masukkan nomor record yang akan dihapus : ";cin>>hapus;
	//validasi
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
	
void cari_barang(larik_barang X){
	string cari;bool ada=false;
	cout<<"Mengecek harga barang\n";
	cout<<"Masukkan kode barang yang akan dicek : ";cin>>cari;
	//mengecek di larik record
	for(i=1;i<=n;i++){
		if(X[i].kode_brg==cari){ada=true;
			cout<<"Kode Barang = "<<cari<<endl;
			cout<<"Nama Barang = "<<X[i].nama<<endl;
			cout<<"Harga Barang = Rp "<<X[i].harga<<endl;}	
		}	
	if(not ada) cout<<"Kode"<<cari<<"tidak ditemukan\n";
	}

void penjualan (larik_barang &X){
	string beli;int jumbeli;bool ada=false;
	cout<<"Penjualan Barang\n";
	cetak_barang(X);
	cout<<"--------------------\n";
	cout<<"Masukkan kode barang yang akan dibeli :";cin>>beli;
	//cek dulu ada atau tidak kode
	//mengecek di larik record
	for(i=1;i<=n;i++){
		if(X[i].kode_brg==beli){ada=true;
			cout<<"Kode Barang = "<<beli<<endl;
			cout<<"Nama Barang = "<<X[i].nama<<endl;
			cout<<"Harga barang = Rp "<<X[i].harga<<endl;
			//penjualanya
			cout<<"Jumlah dibeli : ";cin>>jumbeli;
			//cek stok
			if(X[i].stok>=jumbeli){
			//lakukan proses pembayaran dan pengurangan stok
			cout<<"Anda membeli "<<X[i].nama<<" sebanyak "<<jumbeli<<endl;
			cout<<"Anda harus membayar Rp "<<jumbeli*X[i].harga<<endl;
			cout<<"Terimakasih"<<endl;
			//kurangi stok
			X[i].stok=X[i].stok-jumbeli;
			}
		else cout<<"Stok tidak cukup, pembelian dibatalkan, lakukan transaksi ulang\n";
		}
	}
	if (not ada) cout<<"Kode"<<beli<<"tidak tersedia\n";
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
