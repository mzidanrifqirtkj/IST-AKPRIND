#include <iostream>
using namespace std;

int *a=0, *b=0;
int c,d;

void isi_data(int *x, int *y){//value
	*x=12; *y=10;
	cout<<"x= "<<x<<" y = "<<*y<<endl;
}

void isi_juga(int &x, int &y){//reference
	x=3;y=6;
}

void tes_kirim(int *x, int *y){
	cout<<"xx = "<<*x<<" yy= "<<*y<<endl;
}

int main() {
	a=new int; b=new int;
	isi_data(a,b);
	cout<<"a= "<<*a<<"  b= "<<*b<<endl;
	cout<<"a= "<<a<<"  b= "<<*b<<endl;
	tes_kirim(a,b);
	isi_juga(c,d);
	cout<<"c = "<<c<<" d= "<<d<<endl;
	delete a;delete b;
}
