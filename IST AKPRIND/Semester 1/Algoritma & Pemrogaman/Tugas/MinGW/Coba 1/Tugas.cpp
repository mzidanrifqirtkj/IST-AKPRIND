//progam week 3
#include <iostream> //library dasar c++
using namespace std;
const string kampus = "Institut Sains & Teknologi AKPRIND";
string nama, alamat;
int umur;

int main() //fungsi main, fungsi wajib di c++
{		   //awal progam

	cout << "Hello...salam kenal" << endl;
	cout << "Siapakah nama 
	cin >> nama;
	cout << "Alamat anda dimana?";
	cin >> alamat;
	cout << "Umur anda berapa?";
	cin >> umur;
	cout << "Halo, nama saya : " << nama << "alamat di" << alamat << endl;
	cout << "Saya berumur : " << umur << "tahun" << endl;
	cout << "Saya berkuliah di" << kampus << endl;
} //akhir progam
