#include <iostream>
using namespace std;

int*addpoint1=0, *addpoint2=0;//membuka memory
int isi=10;

int main (){
	addpoint1=&isi;
	cout<<"NIlai dari variabel isi adalah = "<<isi<<endl;
	cout<<"Nilai variabel pointer addpoint1 adalah = "<<addpoint1<<endl;
	cout<<"Nilai dari alamat yang disimpan oleh addpoint1 adalah = "<<*addpoint1<<endl;
	cout<<"Alamat dari variabel addpoint1 adalah = "<<&addpoint1<<endl;
	addpoint2=addpoint1;
	cout<<"Nilai variabel pointer addpoint2 adalah = "<<addpoint2<<endl;
	cout<<"Nilai dari alamat yang disimpan oleh addpoint2 adalah = "<<*addpoint2<<endl;
	cout<<"Alamat dari variabel addpoint2 adalah = "<<&addpoint2<<endl;
	delete addpoint1; //menutup kembali memori
	delete addpoint2;
}
