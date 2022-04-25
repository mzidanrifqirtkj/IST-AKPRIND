//nama anggota
// I Wayan Julianta
// Muhammad Zidan Rifqi Ramadhan
// Darrenesia

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
	string kode_dagangan,nama;
	float harga; int persediaan;
}rec_dagangan; 

typedef rec_dagangan larik_dagangan[30];
larik_dagangan dagangan;
int n,i,pil;

void tambah_dagangan(larik_dagangan &X){
	string dagangan_baru;
	cout<<"Tambah dagangan baru\n";
	ulang:
	cout<<"Masukkan kode dagangan baru : ";cin>>dagangan_baru;
	for(i=1;i<=n;i++){
		if(X[i].kode_dagangan==dagangan_baru){cout<<"Kode sudah digunakan, ulangi\n";goto ulang;}
		}
	n++;
	X[n].kode_dagangan=dagangan_baru;
	cout<<"Masukkan nama dagangan = ";cin>>X[n].nama;
	cout<<"Masukkan harga dagangan = ";cin>>X[n].harga;
	cout<<"Masukkan persediaan awal    = ";cin>>X[n].persediaan;
	cout<<"Input berhasil\n";
	}

void cetak_dagangan(larik_dagangan &X){
	cout<<"Daftar Dagangan di Gudang saat ini\n";
	cout<<"--------------------------------\n";
	cout<<"No Kode Nama Harga Persediaan\n";
	cout<<"--------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(6)<<X[i].kode_dagangan<<setw(20)<<X[i].nama<<setw(8)
		<<X[i].harga<<setw(6)<<X[i].persediaan<<endl;
	cout<<"--------------------------------\n";
	}
	
void edit_dagangan(larik_dagangan &X){
	string edit; int pos, pilih, tambah_persediaan;bool ada = false;
	cetak_dagangan(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan kode dagangan yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
		if(X[i].kode_dagangan==edit){pos=i;ada=true;}
		}
	if(ada){
		cout<<"Anda akan mengedit Kode Dagangan "<<edit<<"\n";
		cout<<"Posisi di record nomor : "<<pos<<"\n";
		cout<<"Nama dagangan  : "<<X[pos].nama<<"\n";
		cout<<"Harga dagangan  : "<<X[pos].harga<<"\n";
		cout<<"Persediaan saat ini  : "<<X[pos].persediaan<<"\n";
		cout<<"Anda bisa mengedit Harga dagangan dan menambahkan persediaan\n";
		cout<<"1. Edit Harga 2. Tambah Persediaan\n";cin>>pilih;
		
	if(pilih==1){
		cout<<"Masukkan harga yang baru Rp ";cin>>X[pos].harga;
		}
	else if (pilih==2){
		cout<<"Masukkan tambahan persediaan ";cin>>tambah_persediaan;
		X[pos].persediaan=X[pos].persediaan+tambah_persediaan;
		}
	else cout<<"Salah Pilih\n";
	cout<<"Editing sudah dilakukan\n";
	}
else cout<<"Kode dagangan "<<edit<<"tidak ditemukan,editing gagal\n";
	}
	
void hapus_dagangan(larik_dagangan &X){
	int hapus; char ya;
	cetak_dagangan(X);
	cout<<"Manghapus data dagangan\n";
	ulang:
	cout<<"Masukkan nomor record yang akan dihapus : ";cin>>hapus;
	if((hapus<1) || (hapus>n)) {
		cout<<"Nomor record tidak valid, ulangi !\n";goto ulang;}
	//sudah valid
	cout<<"Yakin akan dihapus<y/t>?";cin>>ya;
	if((ya=='Y') || (ya=='y')){
		cout<<"Data telah dihapus"<<endl;
		for(i=hapus;i<n;i++)X[i]=X[i+1];
		n--;
		}
	else cout << "Data tidak jadi dihapus \n";
	}

void cek_dagangan(larik_dagangan X){
	string cek;bool ada=false;
	cout<<"Mengecek harga dagangan\n";
	cout<<"Masukkan kode dagangan yang akan dicek : ";cin>>cek;
	//mengecek di larik record
	for(i=1;i<=n;i++){
		if(X[i].kode_dagangan==cek){ada=true;
			cout<<"Kode Dagangan = "<<cek<<endl;
			cout<<"Nama Dagangan = "<<X[i].nama<<endl;
			cout<<"Harga Dagangan = Rp "<<X[i].harga<<endl;}	
		}	
	if(not ada) cout<<"Kode"<<cek<<"tidak ditemukan\n";
	}

void penjualan (larik_dagangan &X){
	string beli;int jumbeli;bool ada=false;
	cout<<"Penjualan Dagangan\n";
	cetak_dagangan(X);
	cout<<"--------------------\n";
	cout<<"Masukkan kode dagangan yang akan dibeli :";cin>>beli;
	//cek dulu ada atau tidak kode
	//mengecek di larik record
	for(i=1;i<=n;i++){
		if(X[i].kode_dagangan==beli){ada=true;
			cout<<"Kode Dagangan = "<<beli<<endl;
			cout<<"Nama Dagangan = "<<X[i].nama<<endl;
			cout<<"Harga dagangan = Rp "<<X[i].harga<<endl;
			//penjualanya
			cout<<"Jumlah dibeli : ";cin>>jumbeli;
			//cek persediaan
			if(X[i].persediaan>=jumbeli){
			//lakukan proses pembayaran dan pengurangan persediaan
			cout<<"Anda membeli "<<X[i].nama<<" sebanyak "<<jumbeli<<endl;
			cout<<"Anda harus membayar Rp "<<jumbeli*X[i].harga<<endl;
			cout<<"Terimakasih"<<endl;
			//kurangi persediaan
			X[i].persediaan=X[i].persediaan-jumbeli;
			}
		else cout<<"Persediaan tidak cukup, pembelian dibatalkan, lakukan pembelian ulang\n";
		}
	}
	if (not ada) cout<<"Kode"<<beli<<"tidak tersedia\n";
}
int main () {
		
	do{
		system("cls");
		cout<<"Pengelolaan Data Dagangan"<<endl;
		cout<<"1. Input Dagangan\n";
		cout<<"2. Cetak Dagangan\n";	
		cout<<"3. Edit Dagangan\n";
		cout<<"4. Hapus Dagangan\n";
		cout<<"5. Cek Harga Dagangan\n";
		cout<<"6. Penjualan\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n>2)cout<<"Sudah penuh \n";else tambah_dagangan(dagangan);break;
			case 2:if(n==100)cout<<"Tempat masih kosong \n";else cetak_dagangan(dagangan);break;
			case 3:if(n==100)cout<<"Tempat masih kosong \n";else edit_dagangan(dagangan);break;
			case 4:if(n==100)cout<<"Tempat masih kosong \n";else hapus_dagangan(dagangan);break;
			case 5:if(n==100)cout<<"Tempat masih kosong \n";else cek_dagangan(dagangan);break;
			case 6:if(n==100)cout<<"Tempat masih kosong \n";else penjualan(dagangan);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
		system("pause");
	 
	}while(pil!=0);
		
	}
