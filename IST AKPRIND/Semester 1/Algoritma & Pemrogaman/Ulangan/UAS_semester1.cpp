//Nama = Muhammad Zidan Rifqi Ramadhan
//NIM = 211055002

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct{
	string nama_as, keahlian_as, na_as;
	float gaji; 
	int jadwal_as;
} data_as; //deklarasi type data record

typedef data_as zidan[100];//deklarasi larik
//deklarasi variabel
zidan isi;
int n,i,pil;


void add_asesor(zidan &X){
	string na_baru;
	cout<<"Tambah Data Baru\n";
	ulang:
	cout<<"Masukkan Nomor Asesor : ";cin>>na_baru;
	//validasi
	for(i=1;i<=n;i++){
		if(X[i].na_as==na_baru){cout<<"Kode telah digunakan, ulangi lagi!\n";goto ulang;}
		}
	//sudah valid
	n++;
	X[n].na_as=na_baru;
	cout<<"Input Nama Asesor = ";cin>>X[n].nama_as;
	cout<<"Input Keahlian Asesor = ";cin>>X[n].keahlian_as;
	cout<<"Input Gaji = ";cin>>X[n].gaji;
	cout<<"Input berhasil\n";
	}

void print_asesor(zidan &X){
	cout<<"Daftar Data Sekarang\n";
	cout<<"--------------------------------\n";
	cout<<"No  NA 	Nama 	Keahlian 	Gaji \n";
	cout<<"--------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(4)<<X[i].na_as<<setw(7)<<X[i].nama_as<<setw(10)
		<<X[i].keahlian_as<<setw(12)<<X[i].gaji<<endl;
	cout<<"--------------------------------\n";
	}

void add_schedule(zidan &X){
	string edit; int pos, tambah; bool ada = false; char ya;
	print_asesor(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan Nomor Asesor yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
		if(X[i].na_as==edit){pos=i;ada=true;}
		}
	//jika ketemu
	if(ada){
		cout<<"Anda akan mengedit Nomor Asesor "<<edit<<"\n";
		cout<<"Posisi di record nomor : "<<pos<<"\n";
		cout<<"Nama Asesor  : "<<X[pos].nama_as	<<"\n";
		cout<<"Keahlian Asesor  : "<<X[pos].keahlian_as<<"\n";
		cout<<"Gaji  : "<<X[pos].gaji<<"\n";
		cout<<"Anda akan menambahkan Jadwal Asesor\n";
		cout<<"Apakah anda yakin akan menambahkanya <y/t>?";cin>>ya;
		
		if ((ya == 'y') || (ya == 'Y')){
			cout<<"Keterangan Input Jadwal\n";
			cout<<"1 = Progammer\n";
			cout<<"2 = Database Administrator\n";
			cout<<"3 = Network Analyst\n";
			cout<<"Masukkan Jadwal Asesment : ";cin>>tambah;
			
			if (tambah==1){
			X[pos].gaji=X[pos].gaji+250000;
			;}
		else if (tambah==2){
			X[pos].gaji=X[pos].gaji+175000;
			;}
		else if(tambah==3){
			X[pos].gaji=X[pos].gaji+200000;
			;}
		
		} else cout<<"Terimakasih"<<endl;
		
	cout<<"Editing sudah dilakukan\n";
	}
else cout<<"Nomor Asesor "<<edit<<"tidak ditemukan,editing gagal\n";
	}

void edit_asesor(zidan &X){
	string edit; int pos; bool ada = false; char ya;
	print_asesor(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan Nomor Asesor yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
		if(X[i].na_as==edit){pos=i;ada=true;}
		}
	//jika ketemu
	if(ada){
		cout<<"Anda akan mengedit Nomor Asesor "<<edit<<"\n";
		cout<<"Posisi di record nomor : "<<pos<<"\n";
		cout<<"Nama Asesor  : "<<X[pos].nama_as	<<"\n";
		cout<<"Keahlian Asesor  : "<<X[pos].keahlian_as<<"\n";
		cout<<"Anda bisa mengedit Keahlian Asesor\n";
		cout<<"Apakah anda yakin akan mengeditnya <y/t>?";cin>>ya;
		
		if ((ya == 'y') || (ya == 'Y')){
			cout<<"Input Nama Keahlian Baru : ";cin>>X[pos].keahlian_as;
		} else cout<<"Terimakasih"<<endl;
		
	cout<<"Editing sudah dilakukan\n";
	}
else cout<<"Nomor Asesor "<<edit<<"tidak ditemukan,editing gagal\n";
	}
	
int main () {
	do{
		system("cls");
		cout<<"Lembaga Sertifikasi Keahlian"<<endl;
		cout<<"1. Add Asesor\n";
		cout<<"2. Add Schedule\n";	
		cout<<"3. Print Asesor\n";
		cout<<"4. Edit Asesor\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n==50)cout<<"Sudah penuh \n";else add_asesor(isi);break;
			case 2:if(n==50)cout<<"Gudang masih kosong \n";else add_schedule(isi);break;
			case 3:if(n==50)cout<<"Gudang masih kosong \n";else print_asesor(isi);break;
			case 4:if(n==50)cout<<"Gudang masih kosong \n";else edit_asesor(isi);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
		system("pause");
	 
	}while(pil!=0);
	
}



