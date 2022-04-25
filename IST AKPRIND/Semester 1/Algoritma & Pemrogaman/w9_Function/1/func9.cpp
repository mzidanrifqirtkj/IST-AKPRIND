//procedute
#include <iostream>
using namespace std;

void greeting () {
	
	cout<<"Selamat siang kita belajar Function di C++ \n";
	}

void kampus () {
	string kampusku = "Institiut Sains & Teknologi AKPRIND";
	cout<<"kampusku"<<endl;
	}

char nilaihuruf (int x) {
	if (x >= 80) return 'A'; 
	 else if (x >= 60) return 'B';
	 else if (x >= 50) return 'C';
	 else if (x >= 20) return 'D';
	 else return 'E';
	}
	
int bobot (char y){
	int a;
	switch(y){
		case 'A': a= 4; break;
		case 'B': a= 3; break;
		case 'C': a= 2; break;
		case 'D': a= 1; break;
		case 'E': a= 0;break;
		return a;
		}
}	

int main () {
	int nilai;
	greeting ();
	kampus ();
	cout<<"Masukkan nilai 0-100 :";cin>>nilai;
	cout<<"Nilaimu ="<<nilai<<"nilai huruf ="<<nilaihuruf(nilai)<<endl;
	cout<<"Bobot nilaimu adalah "<<bobot(nilaihuruf(nilai))<<endl;
	}
