#include <iostream>

using namespace std;

int a[10],n,jum=0;
float mean;

int main () {
	//input data
	int i =0;
	
	cout << "masukkan berapa data yang akan diinputkan : ";cin>>n;
	for (i=0; i<n; i++){
		
		cout<<"masukkan bilangan bulat ke "<<i+1<<" = ";
		cin>>a[i];
		
		jum=jum+a[i];
		}
	
		mean =jum/n;
		cout<<endl;
		
		//mencetak hasil
		for (i=0; i<n; i++) {
			
			cout<<"Bilangan ke : "<<i+1<<" = "<<a[i]<<endl;
			cout<<endl<<"Rata-rata bilangan di atas adalah = "<<mean;
			}
	}
