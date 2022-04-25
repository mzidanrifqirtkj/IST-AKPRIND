//contoh kasus harus dikerjakan menggunakan whilee
//Si Joy berkendara dari kota A ke kota B dengan mobil yang diisi x liter BBM
//kecepatan mobil y km/jam, sedangkan jarak A ke B z km
//jika Joy sampai, berapa liter konsumsi bbm ke kota tujuan, BBM sisa berapa liter
//jika Joy tidak sampai tujuan (krn kehabisan BBM), di km brpa dia kehabisan BBM
//kbbm: 17 km/liter maka jika jaraknya 167 km
#include <iostream>

using namespace std;
float jarak, tempuh=0,sisa,bbm,kec,kbbm;
char ya;
int main () {
	//isi data awal
	do {
		system("cls");
		cout<<"Mengawal Perjalanan Joy dari kota A ke kota B "<<endl;
		cout<<"Jarak ke kota tujuan : ";cin>>jarak;
		//cout
		cout<<"BBM yang diisikan ke mobil : ";cin>>bbm;
		cout<<"Konsumsi bbm per liter ? ";cin>>kbbm;

		float x=1;tempuh=0;
		while ((bbm>0) && (tempuh<=jarak)) {
			tempuh=tempuh+kbbm;
			cout<<"liter ke "<<x<<" jarak yang ditempuh "<<tempuh<<" km "<<endl;
			bbm--; x++;
			}
			if ((bbm>=0) && (tempuh>=jarak))
			{ sisa=tempuh-jarak;
				cout<<"Joy sampai dengan selamat, sisa bbm di mobil "<<bbm+((tempuh-jarak)/kbbm)<<" liter"<<endl;}
			else {
				cout<<"Joy kehabisan BBM di jalan, pada km ke "<<tempuh<<endl;
				cout<<"Joy dari kota tujuan "<<jarak-tempuh<<" km"<<endl;
				}

		cout<<"Apakah akan mencoba lagi <y/t>?";cin>>ya;
	}
	while ((ya=='y')||(ya=='Y'));
	cout<<"Terimakasih"<<endl;
}
