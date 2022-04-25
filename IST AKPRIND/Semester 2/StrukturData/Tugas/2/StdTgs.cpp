// Muhammad Zidan Rifqi Ramadhan
//NIM = 211055002

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct{
	string nama, jns, NP, tanggal;
	float tarif;
} data_motor; //deklarasi type data record

typedef data_motor motor[10];//deklarasi larik
//deklarasi variabel
motor data,mirror;//data adalah variabel bertipe array record
int n=0,i,pil,pil2;

void add_motor(motor &X){
	string np_baru;int xx;
	cout<<"Tambah Data Baru\n";
	ulang:
	cout<<"Masukkan Nomor Plat : ";cin>>np_baru;
	//validasi
	for(i=1;i<=n;i++){
		if(X[i].NP==np_baru){cout<<"Nomor Plat telah digunakan, ulangi lagi!\n";goto ulang;}
	}
	//sudah valid
	n++;
	X[n].NP=np_baru;
	cout<<"Input Nama Peminjam = ";cin>>X[n].nama;
	ulangi:
	cout<<"1. Matic 2. kopling 3.bebek\n";
	cout<<"Pilih Jenis Motor :";cin>>xx;
	if (xx==1)X[n].jns="Matic";
	else if (xx==2)X[n].jns = "kopling";
	else if (xx==3)X[n].jns = "bebek";
	else {cout<<"Jenis motor tidak tersedia, ulangi";goto ulangi;}
	X[n].tarif=0;
	X[n].tanggal="XX";
	cout<<"Input berhasil\n"; 
}

void print_motor(motor &X){
	cout<<"Daftar Data Plat di LSP Informatika IST AKPRIND \n";
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"No NP 	  Nama 		Jenis 	   Tanggal 		Tarif \n";
	cout<<"---------------------------------------------------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(4)<<X[i].NP<<setw(8)<<X[i].nama<<setw(12)
		<<X[i].jns<<setw(16)<<X[i].tanggal<<setw(20)<<X[i].tarif<<endl;
	cout<<"---------------------------------------------------------------------------\n";
}

void add_schedule(motor &X){
	string adtanggal; int pos; bool ada=false;
	print_motor(X);
	cout<<"Menginputkan Tanggal Peminjaman LSP Informatika \n";
	cout<<"Masukkan Nomor Plat yang akan ditambah tanggal meminjam: ";cin>>adtanggal;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
	if ((X[i].NP==adtanggal) && (X[i].tarif==0)) {pos=i;ada=true;}//mengecek dan mencatat posisi record jika ada dan tarif msh 0
	}
	//jika ketemu dan memenuhi syarat tarif masih nol
	if(ada){
	cout<<"Anda akan menambah tanggal peminjaman dengan Nomor Plat "<<adtanggal<<"\n";
	cout<<"Posisi di record nomor : "<<pos<<"\n";
	cout<<"Nama Peminjaman : "<<X[pos].nama<<"\n";
	cout<<"Jenis Motor : "<<X[pos].jns<<"\n";
	//masukkan tanggal peminjaman
	 cout<<"Masukkan tanggal asesment <misal : 2-3-2022 > : ";
	 cin>>X[pos].tanggal;
	 //menentukan tarif
	 if (X[pos].jns=="Matic") 
	 {X[pos].tarif=500000;}
	 else if(X[pos].jns=="kopling") X[pos].tarif=400000;
	 else X[pos].tarif=300000;
	cout<<"Input tanggal sudah dilakukan\n";
	}
	else cout<<"Penambahan tanggal tidak bisa dilakukan\n";
}

void edit_motor(motor &X){
	string edit; int pos,xx; bool ada = false; char ya;
	print_motor(X);
	cout<<"Mengedit data \n";
	cout<<"Masukkan Nomor Plat yang akan diedit : ";cin>>edit;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
	if(X[i].NP==edit){pos=i;ada=true;}
	}
	//jika ketemu
	if(ada){
	cout<<"Anda akan mengedit Nomor Plat "<<edit<<"\n";
	cout<<"Posisi di record nomor : "<<pos<<"\n";
	cout<<"Nama Peminjam : "<<X[pos].nama<<"\n";
	cout<<"Jenis Motor : "<<X[pos].jns<<"\n";
	cout<<"Anda bisa mengedit Jenis Motor\n";
	cout<<"Apakah anda yakin akan mengeditnya <y/t>?";cin>>ya;
	if ((ya == 'y') || (ya == 'Y')){
	ulangi:
	cout<<"1. Matic 2. kopling 3. bebek\n";
	cout<<"Pilih Jenis Motor : ";cin>>xx;
	if (xx==1) X[pos].jns="Matic";else if (xx==2) X[pos].jns="kopling";
	else if (xx==3) X[pos].jns="bebek";
	else {cout<<"Jenis Motor tidak tersedia,ulangi";goto ulangi;}
	//menyesuaikan tarif sesuai jenis, jika motor sudah ada tanggal
	if (X[pos].tarif!=0) {
	if (X[pos].jns=="Matic") X[pos].tarif=250000;
	else if(X[pos].jns=="Network Administrator") X[pos].tarif=175000;
	else X[pos].tarif=200000;
	}
	} else cout<<"Tidak jadi dilakukan editing jenis motor"<<endl;
	cout<<"Editing sudah dilakukan\n";
	}
	else cout<<"Nomor Plat "<<edit<<"tidak ditemukan,editing gagal\n";
}
	
void del_motor(motor &X){
	int hapus; char ya;
	cout<<"Menghapus Data Peminjam dari LSP Informatika\n";
	print_motor(X);
	cout<<"Menghapus Data \n";
	ulang:
	cout<<"Masukkan Nomor urut data yang akan dihapus: ";cin>>hapus;
	if ((hapus<1) || (hapus>n)) {
	cout<<"Nomor record tidak valid, ulangi\n";goto ulang;}//validasi nomor plat
	//sudah valid
	cout<<"Yakin akan menghapus no data? "<<hapus<<" <y/t> ?";cin>>ya;
	if((ya=='y') || (ya=='Y')){ //lakukan penghapusan
	for(i=hapus;i<n;i++) {X[i]=X[i+1];}
	n--; //hapus record terakhir atau kurangi jumlah record
	cout<<"Record nomor "<<hapus<<" telah dihapus\n";
	}
	else cout<<"Record nomor "<<hapus<<" Tidak jadi dihapus\n";
}	

void cek_tanggal_motor(motor &X){
	string xx, skedul;bool ada=false;
	cout<<"Mengecek tanggal peminjaman berdasar jenis motor\n";
	cout<<"Matic, Kopling, Bebek";
	cout<<"Masukkan jenis motor yang dicari : ";cin>>xx;
	cout<<"Berikut adalah motor jenis "<<xx<<"yang sudah ada tanggal : \n";
	cout<<"NP	Nama 	Jenis	Tanggal \n";
	cout<<"-------------------------------\n";
	for (i=1;i<=n;i++){
		if((X[i].jns==xx)&&(X[i].tanggal!="XX")){
			ada = true;
			cout<<setw(2)<<X[i].NP<<setw(7)<<X[i].nama<<setw(12)<<X[i].jns<<setw(15)<<X[i].tanggal<<"\n"; }
		}
		cout<<"-----------------------------\n";
		if (not ada) cout<<"Tidak ada motor jenis "<<xx<<"yang sudah memiliki tanggal\n";
	
}

void cetak_jenis(motor X,int a){
	string xx;int ii=0;bool ada;
	if (a==1) xx="Matic";else if (a==2)xx="kopling";else xx="bebek";
	cout<<"Daftar Data Peminjaman di LSP Informatika IST AKPRIND \n";
	cout<<"Skema"<<xx<<"\n";
	cout<<"--------------------------------------------------------\n";
	cout<<"No   NP		Nama	 tanggal		Tarif \n";
	cout<<"---------------------------------------------------------\n";
	for(i=1;i<=n;i++){
		if(X[i].jns==xx)
		{
			ii++;ada=true;
			cout<<setw(2)<<ii<<setw(6)<<X[i].NP<<setw(10)<<X[i].nama<<setw(14)<<X[i].tanggal<<setw(18)<<X[i].tarif<<endl;}
		}
	cout<<"----------------------------------------------------------\n";
	if (not ada)cout<<"Peminjam dengan jenis motor "<<xx<<"tidak ditemukan\n";
}

void filtering_motor(motor &X){
	//menu untuk filtering_peminjam
	cout<<"Filtering Jenis Motor : \n";
	cout<<"1. Matic\n";
	cout<<"2. kopling\n";
	cout<<"3. bebek\n";
	cout<<"Pilih jenis motor yang akan ditampilkan <1-3> :";
	cin>>pil2;
	switch(pil2){
	case 1:cetak_jenis(X,pil2);break;
	case 2:cetak_jenis(X,pil2);break;
	case 3:cetak_jenis(X,pil2);break;
	default:cout<<"salah pilih menu, filtering gagal\n";}
}

void sorting_motor(motor &X){
	int i,j;
	data_motor temp;
	motor mirror=X;//mirror yang nanti akan diurutkan
	cout<<"Mengurutkan data peminjaman berdasarkan tarif\n";
	//proses pengurutan
	for (i=1;i<n;i++){
		for(j=1;j<=i;j++){
			if(mirror[j].tarif<mirror[j+1].tarif){
				temp=mirror[j];mirror[j]=mirror[j+1];mirror[j+1]=temp;}//swap
			}//loop j
		}//loop i
	//kirim ke cetak untuk mencetak data yang sudah diurutkan
	print_motor(mirror);
}
//void sorting 

void find_motor(motor &X){
	int i,j;
	string cari;bool ada=false;data_motor temp;
	//mengurutkan binary searching data harus diurutkan
	//mengurutkan data dengan kunci NP sesuai dengan kunci pencarian
	cout<<"Berikut adalah data peminjaman diurutkan berdasarkan NP\n";
	//for 
	motor mirror=X;
	//lakukan pengurutan dengan metode selection
	for (i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
		if(mirror[i].NP>mirror[j].NP){temp=mirror[i];mirror[i]=mirror[j];mirror[j]=temp;}
		}	
	}

//sorting selesai
print_motor(mirror);
cout<<"Masukkan nomor plat yang dicari :";cin>>cari;
//menggunakan binarySearch
int low=1,mid,high=n;
while (low<=high){
	mid=low + (high-low)/2;
	if(mirror[mid].NP==cari){ada=true;cout<<"Jenis motor ditemukan diposisi ke "<<mid<<endl;}
	if(mirror[mid].NP < cari)
		low=mid+1;
	else
		high=mid-1;
	}
	if (not ada)cout<<"Peminjam dengan nomor Plat"<<cari<<"tidak ditemukan\n";
}

int main () {
	do{
		system("cls");
		cout<<"Daftar Rental Motor"<<endl;
		cout<<"1. Tambah Data\n";
		cout<<"2. Tambah Tanggal Pinjam\n";
		cout<<"3. Cetak Data\n";
		cout<<"4. Edit Data\n";
		cout<<"5. Hapus Data\n";
		cout<<"6. Cek tanggal peminjaman berdasar jenis motor\n";
		cout<<"7. Filtering berdasar jenis motor\n";
		cout<<"8. Mengurutkan data berdasar biaya peminjaman\n";
		cout<<"9. Posisi nomor Peminjam\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n==10)cout<<"Peminjaman Motor sudah penuh \n";else add_motor(data);break;
			case 2:if(n<=0)cout<<"Belum ada Motor yang akan diberikan tanggal\n";else add_schedule(data);break;
			case 3:if(n<=0)cout<<"Belum ada Motor yang bisa dicetak datanya\n";else print_motor(data);break;
			case 4:if(n<=0)cout<<"Belum ada Motor yang bisa diedit \n";else edit_motor(data);break;
			case 5:if(n<=0)cout<<"Belum ada Motor yang terdaftar\n";else del_motor(data);break;
			case 6:if(n<=0)cout<<"Belum ada Motor yang terdaftar\n";else cek_tanggal_motor(data);break;
			case 7:if(n<=0)cout<<"Belum ada Motor yang terdaftar\n";else filtering_motor(data);break;
			case 8:if(n<=0)cout<<"Belum ada Motor yang terdaftar\n";else sorting_motor(data);break;
			case 9:if(n<=0)cout<<"Belum ada Motor yang terdaftar\n";else find_motor(data);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
			system("pause");
	}while(pil!=0);
}
