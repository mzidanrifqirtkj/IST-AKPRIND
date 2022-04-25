//progam week5 Kondisional
#include <iostream>

using namespace std;
int a;
char ya;

int main () {
	ulang:
	cout<<"Masukkan bilangan bulat: ";cin>>a;
	if(a==0){cout<<"Anda memasukkan bilangan nol"<<endl;}
	else if((a%2==0)&&(a>0)){cout<<"Anda memasukkan bilangan genap positif"<<endl;}
	//else {cout<<"Anda memasukkan bilangan ganjil"<<endl;}
	else if((a%2==0)&&(a<0)){cout<<"Anda memasukkan bilangan genap negatif"<<endl;}
	
	else if((a%2!=0)&&(a>0)){cout<<"Anda memasukkan bilangan ganjil positif"<<endl;}
	else {cout<<"Anda memasukkan bilangan ganjil negatif"<<endl;}
	
	//statement di luar Kondisional
	cout<<endl;
	cout<<"Apakah anda akan mencoba lagi <y/t>?";cin>>ya;
	if ((ya=='y')||(ya=='Y')){goto ulang;} 
	
	cout<<"Terima Kasih"<<endl;
	
	
	}

