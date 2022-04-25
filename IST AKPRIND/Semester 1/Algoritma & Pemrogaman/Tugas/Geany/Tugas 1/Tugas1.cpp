//Mendeteksi status kesehatan berdasarkan data
#include <iostream>
#include <math.h>

using namespace std;

string nama;
int td,ktd;
char ya,t;

int main () {
	kembali:
	cout<<"Mendeteksi status kesehatan berdasarkan data"<<endl;
	cout<<"Masukkan nama anda : ";cin>>nama;
	//Tekanan darah
	cout<<"Input Tekanan darah :";cin>>td;
	if (td>300){cout<<"Hipertensi akut"<<endl;} //bisa dikategorikan dengan status 1,2,3,...
		else if (td<=300 && td>=150){cout<<"Hipertensi ringan"<<endl;}
		else if (td<150 && td>=100) {cout<<"normal"<<endl;}
		else if(td<100){cout<<"hipertensi"<<endl;} 
		
	//Kadar gula darah
	cout<<"Input kadar gula darah : ";cin>>ktd;
	if (ktd>300){cout<<"Diabet"<<endl;}
		else if (ktd<=300 && ktd>=120) {cout<<"Waspada diabet"<<endl;}
		else if (ktd<120){cout<<"normal"<<endl;}
		
	//pernyataan sehat atau kurang sehat
	cout<<"Apakah keduanya berstatus normal <y/t>?";cin>>ya; 
	if ((ya=='y') || (ya=='Y')) {cout<<"Hore, saudara "<<nama<<" ,Anda termasuk dalam keadaan Sehat"<<endl;}
	if ((ya=='t') || (ya='T')){cout<<"Mohon maaf "<<nama<<" ,Anda Kurang Sehat"<<endl;}
	cout<<endl; 
	
	cout<<"Apakah anda ingin mencoba kembali <y/t>?";cin>>ya;
	if ((ya=='y') || (ya=='Y')) {goto kembali;}
		else {cout<<"Terimakasih saudara "<<nama<<", sudah mencoba progam ini"<<endl;}
	//cout<<"Status kadar gula darah : ";cin>>ktd;
	
	return 0-600;
	
	
	
	
	
	}
