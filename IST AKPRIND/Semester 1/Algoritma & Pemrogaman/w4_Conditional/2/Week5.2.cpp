//progam week5 Kondisional menentukan status keikutsertaan di pilkade
#include <iostream>

using namespace std;
string nama;
int umur,wn,statusp;
bool status;//hakpilih
char ya;


int main (){
	ulang:
	cout<<"Menentukan Status Hak Pilih Seseorang dalam Pilkada"<<endl;
	cout<<"Masukkan nama anda : ";cin>>nama;
	ulang1:
	cout<<"Pilih Status Kewarganegaraan 1.WNI 2.WNA : ";cin>>wn;
	if ((wn<1)||(wn>2)){cout<<"Ulangi masukan anda tidak valid"<<endl;goto ulang1;}//validasi input data
	if (wn==2){status=false;}
	else//WNI
	{ cout<<"Masukkan status perkawinan 1. Menikah/Pernah Menikah 2.Belum Menikah : ";
		cin>>statusp;
		if(statusp==1){status=true;}
		else//belum menikah
		{cout<<"Masukkan umur anda : ";cin>>umur;
			if(umur>17){status=true;} else{status=false;}	
			}
		}
	
	//status after school
	if(status==true){cout<<"Selamat saudara"<<nama<<"anda berhak ikut pilkada"<<endl;}
	else {cout<<"Maaf saudara"<<nama<<"tidak memiliki hak dalam Pilkada"<<endl;}
	//tanya mau cek lagi atau tidak
	cout<<endl;
	cout<<"Apakah akan mencoba lagi<y/t>?";cin>>ya;
	if((ya=='y')||(ya=='Y')){goto ulang;} else{cout<<"Terimakasih sudah mencoba progam ini"<<endl;}
	}
