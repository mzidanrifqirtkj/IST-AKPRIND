//3 pangkat 4 = 3x3 pangkat 3
//3 pangkat 3 = 3x3 pangkat 2
//3 pangkat 2 = 3x3 pangkat 1
//3 pangkat 1 = 3x3 pangkat 0
//3 pangkat 0 = 1
#include <iostream>
#include <math.h>

using namespace std;

int a,b;
int pangkat(int x,int y){
	if (y==0)return 1;else return x*pangkat(x,y-1);
	}
	
int main() {
	cout<<"Bilangan yang akan dipangkatkan :";cin>>a;
	cout<<"Pangkat berapa ? ";cin>>b;
	if(b<0) cout<<"Pangkat negatif, hasil tidak bulat";
	else {
		cout<<a<<" pangkat "<<b<<" = "<<pangkat(a,b)<<endl;
		cout<<"menghitung pangkat dengan function pow\n";
		cout<<a<<" pangkat "<<b<<" = "<<pow(a,b)<<endl;
	}
}
