
// Muhammad Zidan Rifqi Ramadhan
//NIM = 211055002

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct{
	string nama, jenis, NA, jadwal;
	float harga;
} data_asesor; //deklarasi type data record

typedef data_asesor zidan[10];//deklarasi larik
//deklarasi variabel
zidan asesor,mirror;//asesor adalah variabel bertipe array record
int n=0,i,pil,pil2;

void add_asesor(zidan &X){
	string na_baru;int jns;
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
	cout<<"1. Kering 2. Basah \n";
	cout<<"Pilih jenis makanan :";cin>>jns;
	if (jns==1)X[n].jenis="Kering";
	else if (jns==2)X[n].jenis = "Basah";

	else {cout<<"jenis tidak tersedia, ulangi";goto ulangi;}
	X[n].harga=0;
	X[n].jadwal="XX";
	cout<<"Input berhasil\n"; 
}

void print_asesor(zidan &X){
	cout<<"Daftar Data Asesor di LSP Informatika IST AKPRIND \n";
	cout<<"---------------------------------------------------------------------------\n";
	cout<<"No NA Nama jenis makanan Jadwal Harga \n";
	cout<<"---------------------------------------------------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<setw(2)<<i<<setw(4)<<X[i].NA<<setw(7)<<X[i].nama<<setw(25)
		<<X[i].jenis<<setw(12)<<X[i].jadwal<<setw(12)<<X[i].harga<<endl;
	cout<<"---------------------------------------------------------------------------\n";
}

void add_schedule(zidan &X){
	string adjadwal; int pos; bool ada=false;
	print_asesor(X);
	cout<<"Menginputkan Jadwal Asesor LSP Informatika \n";
	cout<<"Masukkan Nomor Asesor yang akan ditambah jadwal: ";cin>>adjadwal;
	//cek di larik recordnya
	for(i=1;i<=n;i++){
	if ((X[i].NA==adjadwal) && (X[i].harga==0)) {pos=i;ada=true;}//mengecek dan mencatat posisi record jika ada dan harga msh 0
	}
	//jika ketemu dan memenuhi syarat harga masih nol
	if(ada){
	cout<<"Anda akan menambah jadwal Asesor dengan Nomor Asesor "<<adjadwal<<"\n";
	cout<<"Posisi di record nomor : "<<pos<<"\n";
	cout<<"Nama Asesor : "<<X[pos].nama<<"\n";
	cout<<"Jenis Makanan : "<<X[pos].jenis<<"\n";
	//masukkan jadwal asesor
	 cout<<"Masukkan tanggal asesment <misal : 2-3-2022 > : ";
	 cin>>X[pos].jadwal;
	 //menentukan harga
	 if (X[pos].jenis=="Kering") 
	 {X[pos].harga=100000;}
	 else X[pos].harga=150000;
	 
	cout<<"Input jadwal sudah dilakukan\n";
	}
	else cout<<"Penambahan jadwal tidak bisa dilakukan\n";
}

void edit_asesor(zidan &X){
	string edit; int pos,jns; bool ada = false; char ya;
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
	cout<<"Jenis Makanan : "<<X[pos].jenis<<"\n";
	cout<<"Anda bisa mengedit Jenis Makanan\n";
	cout<<"Apakah anda yakin akan mengeditnya <y/t>?";cin>>ya;
	if ((ya == 'y') || (ya == 'Y')){
	ulangi:
	cout<<"1. Kering 2. Basah\n";
	cout<<"Pilih jenis makanan : ";cin>>jns;
	if (jns==1) X[pos].jenis="Kering";else if (jns==2) X[pos].jenis="Basah";
	
	else {cout<<"jenis tidak tersedia,ulangi";goto ulangi;}
	//menyesuaikan harga sesuai jenis jika barang sudah ada jadwal
	if (X[pos].harga!=0) {
	if (X[pos].jenis=="Kering") X[pos].harga=100000;
	else X[pos].harga=150000;

	}
	} else cout<<"Tidak jadi dilakukan editing jenis makanan"<<endl;
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

void cek_jadwal_asesor(zidan &X){
	string jns, skedul;bool ada=false;
	cout<<"Mengecek kadaluarsa barang berdasar jenis\n";
	cout<<"Masukkan jenis yang dicari : ";cin>>jns;
	cout<<"Berikut adalah asesor bidang"<<jns<<"yang sudah ada jadwal : \n";
	cout<<"NA	NamaAsesor	Jadwal \n";
	cout<<"-------------------------------\n";
	for (i=1;i<=n;i++){
		if((X[i].jenis==jns)&&(X[i].jadwal!="XX")){
			ada = true;
			cout<<setw(4)<<X[i].NA<<setw(10)<<X[i].nama<<setw(12)<<X[i].jadwal<<"\n"; }
		}
		cout<<"-----------------------------\n";
		if (not ada) cout<<"Tidak ada Asesor bidang"<<jns<<"yang sudah memiliki jadwal\n";
	
}

void cetak_jenis(zidan X,int a){
	string jns;int ii=0;bool ada;
	if (a==1) jns="Kering";else jns="Basah";
	cout<<"Daftar Data Asesor di LSP Informatika IST AKPRIND \n";
	cout<<"Skema"<<jns<<"\n";
	cout<<"--------------------------------------------------------\n";
	cout<<"No  NA	Nama	 Jadwal		Harga\n";
	cout<<"---------------------------------------------------------\n";
	for(i=1;i<=n;i++){
		if(X[i].jenis==jns)
		{
			ii++;ada=true;
			cout<<setw(2)<<ii<<setw(4)<<X[i].NA<<setw(10)<<X[i].nama<<setw(12)<<X[i].jadwal<<setw(12)<<X[i].harga<<endl;}
		}
	cout<<"----------------------------------------------------------\n";
	if (not ada)cout<<"Barang dengan jenis "<<jns<<"tidak ditemukan\n";
}

void filtering_asesor(zidan &X){
	//menu untuk filtering_asesor
	cout<<"Filtering Jenis Barang : \n";
	cout<<"1. Kering\n";
	cout<<"2. Basah\n";
	
	cout<<"Pilih jenis yang akan ditampilkan <1-3> :";
	cin>>pil2;
	switch(pil2){
	case 1:cetak_jenis(X,pil2);break;
	case 2:cetak_jenis(X,pil2);break;
	case 3:cetak_jenis(X,pil2);break;
	default:cout<<"salah pilih menu, filtering gagal\n";}
}

void sorting_asesor(zidan &X){
	int i,j;
	data_asesor temp;
	zidan mirror=X;//mirror yang nanti akan diurutkan
	cout<<"Mengurutkan data asesor berdasarkan harga\n";
	//proses pengurutan
	for (i=1;i<n;i++){
		for(j=1;j<=i;j++){
			if(mirror[j].harga<mirror[j+1].harga){
				temp=mirror[j];mirror[j]=mirror[j+1];mirror[j+1]=temp;}//swap
			}//loop j
		}//loop i
	//  for(i=1; i<=n; i++)
	//  {
    //    for(j=i; j<=n; j++)
    //    {
    //           if(harga[i] < harga[j])
    //           {
    //                  temp = harga[j];
    //                  harga[j] = harga[i];
    //                  harga[i] = temp;
    //           }
    //    }
	//  }
	//kirim ke cetak untuk mencetak data yang sudah diurutkan
	print_asesor(mirror);
}
//void sorting 

void find_asesor(zidan &X){
	int i,j;
	string cari;bool ada=false;data_asesor temp;
	//mengurutkan binary searching data harus diurutkan
	//mengurutkan data dengan kunci NA sesuai dengan kunci pencarian
	cout<<"Berikut adalah data asesor diurutkan berdasarkan NA\n";
	//for 
	zidan mirror=X;
	//lakukan pengurutan dengan metode selection
	for (i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
		if(mirror[i].NA>mirror[j].NA){temp=mirror[i];mirror[i]=mirror[j];mirror[j]=temp;}
		}	
	}

//sorting selesai
print_asesor(mirror);
cout<<"Masukkan kode asesor yang dicari :";cin>>cari;
//menggunakan binarySearch
int low=1,mid,high=n;
while (low<=high){
	mid=low + (high-low)/2;
	if(mirror[mid].NA==cari){ada=true;cout<<"Asesor ditemukan diposisi ke "<<mid<<endl;}
	if(mirror[mid].NA < cari)
		low=mid+1;
	else
		high=mid-1;
	}
	if (not ada)cout<<"Asesor dengan nomor"<<cari<<"tidak ditemukan\n";
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
		cout<<"6. Cek Kadaluarsa asesor berdasar jenis barang\n";
		cout<<"7. Filtering berdasar jenis barang\n";
		cout<<"8. Mengurutkan data berdasar harga asesor\n";
		cout<<"9. Menemukan asesor\n";
		cout<<"0. Selesai\n";
		cout<<"Pilihan menu : ";cin>>pil;
		system("cls");
		switch(pil){
			case 1:if(n==10)cout<<" Asesor sudah memenuhi kuota \n";else add_asesor(asesor);break;
			case 2:if(n<=0)cout<<"Belum ada Asesor yang akan diberikan jadwal\n";else add_schedule(asesor);break;
			case 3:if(n<=0)cout<<"Belum ada asesor yang bisa dicetak datanya\n";else print_asesor(asesor);break;
			case 4:if(n<=0)cout<<"Belum ada asesor yang bisa diedit \n";else edit_asesor(asesor);break;
			case 5:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else del_asesor(asesor);break;
			case 6:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else cek_jadwal_asesor(asesor);break;
			case 7:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else filtering_asesor(asesor);break;
			case 8:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else sorting_asesor(asesor);break;
			case 9:if(n<=0)cout<<"Belum ada asesor yang terdaftar\n";else find_asesor(asesor);break;
			case 0:cout<<"Terimakasih \n";break;
			default:cout<<"Salah pilih menu\n";
			}
			system("pause");
			

	}while(pil!=0);
}
