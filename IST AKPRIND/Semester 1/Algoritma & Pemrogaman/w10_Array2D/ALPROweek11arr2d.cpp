#include <iostream>
using namespace std;
//deklarasi tipe data baru
typedef int Matrix[10][10];
Matrix A,B,C;
int pil,bara,kola,barb,kolb,i,j;

void Isi_Matrix(Matrix &X,int m,int n){
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cout<<"Isi elemen matix ke ["<<i<<","<<j<<"] = ";
			cin>>X[i][j];}
		}
	cout<<"Pengisian sukses \n";
	}

void Cetak_Matrix(Matrix &X,int m,int n){
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cout<<X[i][j]<<"   ";
			cout<<"\n";}
		}
	}

void Tambah_Matrix(Matrix &X, Matrix &Y,int m,int n){
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++) C[i][j]=X[i][j]+Y[i][j];
		}
	}

void Kurang_Matrix(Matrix &X, Matrix &Y,int m,int n){
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++) C[i][j]=X[i][j]-Y[i][j];
		}
	}
	
void Transpose_Matrix(Matrix &X,int m,int n){
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++) C[i][j]=X[j][i];
		}
	}


main () {
do {
	//system("cls");
	cout<<" Operasi Matrix \n";
	cout<<"1. Isi matrix A\n";
	cout<<"2. Isi Matrix B\n";
	cout<<"3. A+B\n";
	cout<<"4. A-B\n";
	cout<<"5. A Transpose\n";
	cout<<"6. B Transpose\n";
	cout<<"7. Cetak A\n";
	cout<<"8. Cetak B\n";
	cout<<"0. Keluar\n";
	cout<<"Pilih menu 0-8\n";cin>>pil;
	switch(pil){
		case 1:{cout<<"Baris A = ";cin>>bara;
			cout<<"Kolom A = ";cin>>kola;
			//panggil function
			Isi_Matrix(A,bara,kola);break;}
		case 2:{cout<<"Baris B = ";cin>>barb;
			cout<<"Kolom B = ";cin>>kolb;
			//panggil function
			Isi_Matrix(B,barb,kolb);break;}
		case 3:{if((bara==barb)&&(kola==kolb)){
			cout<<"Hasil A+B adalah = \n";
			Tambah_Matrix(A,B,bara,kola);
			Cetak_Matrix(C,bara,kola);}
			else cout<<"Orde tidak sama, operasi tidak diijinkan \n";
			break;}
		case 4:{if((bara==barb)&&(kola==kolb)){
			cout<<"Hasil A+B adalah = \n";
			Kurang_Matrix(A,B,bara,kola);
			Cetak_Matrix(C,bara,kola);}
			else cout<<"Orde tidak sama, operasi tidak diijinkan \n";
			break;}
		case 5:{cout<<"Matrix A= \n";
			Cetak_Matrix(A,bara,kola);
			cout<<"Hasil A transpose : \n";
			Transpose_Matrix(A,bara,kola);
			Cetak_Matrix(C,kola,bara);
			break;}
		case 6:{cout<<"Matrix B= \n";
			Cetak_Matrix(B,barb,kolb);
			cout<<"Hasil B transpose : \n";
			Transpose_Matrix(B,barb,kolb);
			Cetak_Matrix(C,kolb,barb);
			break;}
		case 7:{cout<<"Matrix A = \n";
			Cetak_Matrix(A,bara,kola);break;}
		case 8:{cout<<"Matrix B = \n";
			Cetak_Matrix(B,barb,kolb);break;}
		case 0:{cout<<"Terimakasih \n";break;}
		default:cout<<"Anda salah pilih menu \n";
			}//end switch
		cout<<"Tekan enter untuk lanjut";getchar();
	}while(pil!=0);
}
	

