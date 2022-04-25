//progam konversi satuan panjang
#include <iostream> 

using namespace std;

float cm,meter,yard,inch,kaki;

int main () {
	//input
	cout << "Masukkan panjang dalam centimeter : " ; cin >> cm; 
	//proses
	meter= cm/100;
	yard= cm/91.44;
	inch= cm/2.54;
	kaki= cm/30.48;
	
	cout << cm << " centimeter = " << meter << " meter" << endl; 
	cout << cm << " centimeter = " << yard << " meter " << endl;
	cout << cm << " centimeter = " << inch << " meter" << endl;
	cout << cm << " centimeter = " << kaki << " meter" << endl;
	
	
	}
