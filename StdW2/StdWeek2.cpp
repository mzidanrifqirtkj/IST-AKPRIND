// Muhammad Zidan Rifqi Ramadhan
//NIM = 211055002

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct{
	string nama, keahlian, NA, jadwal;
	float gaji;
} data_asesor; //deklarasi type data record

typedef data_asesor zidan[10];//deklarasi larik
//deklarasi variabel
zidan asesor;//asesor adalah variabel bertipe array record
int n=0,i,pil;

void add_asesor(zidan &X){
	string na_baru;int ahli;
	cout<<"Tambah Data Baru\n";
	ulang:
	cout<<"Masukkan Nomor Asesor : ";cin>>na_baru;
	//validasi
	for(i=1;i<=n;i++){
		if(X[i].NA==na_baru){cout<<"Nomor Asesor telah digunakan, ulangi lagi!\n";goto ulang;}
	}
	//sudah valid
	n++;
	X[n].NA=na_baru;
	cout<<"Input Nama Asesor = ";cin>>X[n].nama;
	ulangi:
	cout<<"1. Progammer 2. Database Administrator 3.Network Analyst\n";
	cout<<"Pilih keahlian :";cin>>ahli;
	if (ahli==1)X[n].keahlian="Progammer";
	else if (ahli==2)X[n].keahlian = "Database Administrator";
	else if (ahli==3)X[n].keahlian = "Network Analyst";
	else {cout<<"Keahlian tidak tersedia, ulangi";goto ulangi;}
	X[n].gaji=0;
	X[n].jadwal="XX";
	cout<<"Input berhasil\n"; 
}

void print_asesor(zidan &X){
	cout<<"Daftar Data Asesor di LSP Informatika IST AKPRIND \n";
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"No NA Nama Keahlian Jadwal Gaji \n";
	cout<<"---------------------------------------------------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(4)<<X[i].NA<<setw(7)<<X[i].nama<<setw(25)
		<<X[i].keahlian<<setw(12)<<X[i].jadwal<<setw(12)<<X[i].gaji<<endl;
	cout<<"---------------------------------------------------------------------------\n";
}

void add_schedule(zidan &X){
	string adjadwal; int pos; bool ada=false;
	print_asesor(X);
	cout<<"Menginputkan Jadwal Asesor LSP Informatika \n";
	cout<<"Masukkan Nomor Asesor yang akan ditambah jadwal: ";cin>>adjadwal;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
	if ((X[i].NA==adjadwal) && (X[i].gaji==0)) {pos=i;ada=true;}//mengecek dan mencatat posisi record jika ada dan gaji msh 0
	}
	//jika ketemu dan memenuhi syarat gaji masih nol
	if(ada){
	cout<<"Anda akan menambah jadwal Asesor dengan Nomor Asesor "<<adjadwal<<"\n";
	cout<<"Posisi di record nomor : "<<pos<<"\n";
	cout<<"Nama Asesor : "<<X[pos].nama<<"\n";
	cout<<"Keahlian Asesor : "<<X[pos].keahlian<<"\n";
	//masukkan jadwal asesor
	 cout<<"Masukkan tanggal asesesment <misal : 2-3-2022 > : ";
	 cin>>X[pos].jadwal;
	 //menentukan gaji
	 if (X[pos].keahlian=="Programmer") X[pos].gaji=250000;
	 else if(X[pos].keahlian=="Network Administrator") X[pos].gaji=175000;
	 else X[pos].gaji=200000;
	cout<<"Input jadwal sudah dilakukan\n";
	}
	else cout<<"Penambahan jadwal tidak bisa dilakukan\n";
}

void edit_asesor(zidan &X){
	string edit; int pos,ahli; bool ada = false; char ya;
	print_asesor(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan Nomor Asesor yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
	if(X[i].NA==edit){pos=i;ada=true;}
	}
	//jika ketemu
	if(ada){
	cout<<"Anda akan mengedit Nomor Asesor "<<edit<<"\n";
	cout<<"Posisi di record nomor : "<<pos<<"\n";
	cout<<"Nama Asesor : "<<X[pos].nama<<"\n";
	cout<<"Keahlian Asesor : "<<X[pos].keahlian<<"\n";
	cout<<"Anda bisa mengedit Keahlian Asesor\n";
	cout<<"Apakah anda yakin akan mengeditnya <y/t>?";cin>>ya;
	if ((ya == 'y') || (ya == 'Y')){
	ulangi:
	cout<<"1. Programmer 2. Database Administrator 3. Network Analyst\n";
	cout<<"Pilih keahlian : ";cin>>ahli;
	if (ahli==1) X[pos].keahlian="Programmer";else if (ahli==2) X[pos].keahlian="Database Administrator";
	else if (ahli==3) X[pos].keahlian="Network Analyst";
	else {cout<<"keahlian tidak tersedia,ulangi";goto ulangi;}
	//menyesuaikan gaji sesuai keahlian jika asesor sudah ada jadwal
	if (X[pos].gaji!=0) {
	if (X[pos].keahlian=="Programmer") X[pos].gaji=250000;
	else if(X[pos].keahlian=="Network Administrator") X[pos].gaji=175000;
	else X[pos].gaji=200000;
	}
	} else cout<<"Tidak jadi dilakukan editing keahlian"<<endl;
	cout<<"Editing sudah dilakukan\n";
	}
	else cout<<"Nomor Asesor "<<edit<<"tidak ditemukan,editing gagal\n";
}
	
void del_asesor(zidan &X){
	int hapus; char ya;
	cout<<"Menghapus Asesor dari LSP Informatika\n";
	print_asesor(X);
	cout<<"Menghapus Asesor \n";
	ulang:
	cout<<"Masukkan Nomor Record asesor yang akan dihapus: ";cin>>hapus;
	if ((hapus<1) || (hapus>n)) {
	cout<<"Nomor record tidak valid, ulangi\n";goto ulang;}//validasi nomorrecord
	//sudah valid
	cout<<"Yakin akan menghapus no record "<<hapus<<" <y/t> ?";cin>>ya;
	if((ya=='y') || (ya=='Y')){ //lakukan penghapusan
	for(i=hapus;i<n;i++) {X[i]=X[i+1];}
	n--; //hapus record terakhir atau kurangi jumlah record
	cout<<"Record nomor "<<hapus<<" telah dihapus\n";
	}
	else cout<<"Record nomor "<<hapus<<" Tidak jadi dihapus\n";
}	

int main () {
	do{
		system("cls");
		cout<<"Daftar Asesor"<<endl;
		cout<<"1. Add Asesor\n";
		cout<<"2. Add Schedule\n";
		cout<<"3. Print Asesor\n";
		cout<<"4. Edit Asesor\n";
		cout<<"5. Delete Asesor\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n==10)cout<<" Asesor sudah memenuhi kuota \n";else add_asesor(asesor);break;
			case 2:if(n<=0)cout<<"Belum ada Asesor yang akan diberikan jadwal\n";else add_schedule(asesor);break;
			case 3:if(n<=0)cout<<"Belum ada asesor yang bisa dicetak datanya\n";else print_asesor(asesor);break;
			case 4:if(n<=0)cout<<"Belum ada asesor yang bisa diedit \n";else edit_asesor(asesor);break;
			case 5:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else del_asesor(asesor);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
			system("pause");
			

	}while(pil!=0);
}
