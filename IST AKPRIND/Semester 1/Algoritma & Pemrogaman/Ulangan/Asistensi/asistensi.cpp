//Nama : Muhammad Zidan Rifqi Ramadhan
//NIM : 211055002

#include <iostream>
#include <math.h>

using namespace std;

typedef int Matrix[3][3];
Matrix A,B,C;
int pil,bara,kola,barb,kolb,i,j,a,b,c,D;
float x1,x2;

void Isi_Matrix(Matrix &X,int m,int n){
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cout<<"Isi elemen matix ke ["<<i<<","<<j<<"] = ";
			cin>>X[i][j];}
		}
	cout<<"Pengisian berhasil \n";
	}

void Tambah_Matrix(Matrix &X, Matrix &Y,int m,int n){
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++) C[i][j]=X[i][j]+Y[i][j];
		}
	}
	
void Cetak_Matrix(Matrix &X,int m,int n){
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cout<<X[i][j]<<"   ";
			cout<<"\n";}
		}
	}

void DeterminanRumus(){
	D = (b*b)-(4*a*c);
	cout << "Diskriminan = " << D;
	}
void Input_nilai(){
	cout << "Format persamaan: ax^2 + bx + c = 0 " << endl;
	cout << "Input nilai a: ";
	cin >> a;
	cout << "Input nilai b: ";
	cin >> b;
	cout << "Input nilai c: ";
	cin >> c;
	}
	
void CDeterminan(){
	D = (b*b)-(4*a*c);
    cout << "Diskriminan = " << D;
    
    if (D>0){
        cout << " (akar real dan berbeda)" <<endl;
    
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
    
        cout << "x1 = " << x1 <<endl;
        cout << "x2 = " << x2 <<endl;
    }
    else if (D==0){
        cout << " (akar real dan sama)" <<endl;
    
        x1 = x2 = (-b + sqrt(D)) / (2*a);
    
        cout << "x1 = " << x1 <<endl;
        cout << "x2 = " << x2 <<endl;
    }
    else {
        cout << " (akar tidak real / imajiner)" <<endl;
    }
    
    return 0;
        }
	

int main () {
	do {
	cout<<"Pilih Menu Berikut ini! \n";
	cout<<"1. Isi Matrik A\n";
	//cout<<"1. Operasi penjumlahan matrik ordo 3x3 dan 3x3 \n";
	cout<<"2. Isi Matrik B \n";
	cout<<"";
	cout<<"3. A+B\n";
	cout<<"4. akar-akar persamaan kuadrat\n";
	cout<<"0. Selesai\n";cin>>pil;
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
			Cetak_Matrix(C,barb,kolb);}
			else cout<<"Orde tidak sama, operasi tidak diijinkan \n";
			break;}
		case 4:{
				cout << "##  Program C++ Mencari Akar Persamaan Kuadrat ##" << endl;
                cout << "=================================================" << endl;
                cout << endl;
                
                Input_nilai();
                
                cout << endl;
                
                CDeterminan();
                
               
			}
		}
	}while(pil!=0);
	
}
		
















