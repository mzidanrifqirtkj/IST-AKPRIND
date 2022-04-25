//cetaklah bilangan ganjil diantara dua buah bilangan
//a=30 b=25 output 29 27
//a=10 b=20 output 11 13 15 17 19
#include <iostream>

using namespace std;
int a,b;
bool ada;
char ya;

int main () {
	ulang:
	ada = false;
	
	cout << "Mencetak bilangan ganjil diantara dua buah bilangan"<<endl;
	cout << "Masukkan awal : ";cin >> a;
	cout << "Masukkan akhir : ";cin >> b;
	if (a==b)cout << "Tidak ada bilangan diantara a dan b"<<endl;
	if (a<b){//LOOP NAIK
	for(int i=a+1;i<b;i++){
		if(i%2!=0) {ada=true;cout<<i<<" ";}
		}
		cout<<endl;
	}
	else 
	{for(int i=a-1;i>b;i--) {if(i%2!=0) {ada=true;cout<<i<<" ";}}
		cout<<endl;
		}
	
	if (not ada)cout <<"Tidak ada bilangan yang memenuhi"<<endl;
	cout<<endl;
	cout<<"Apakah akan mencoba lagi <y/t>?";cin>>ya;
	if ((ya == 'y') || (ya == 'Y')) goto ulang;else cout<<"Terimakasih"<<endl;
}


