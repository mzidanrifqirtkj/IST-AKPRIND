#include <iostream>
using namespace std;

typedef int larik[10]; //mendeklarasikan tipe data
int n = 0,i;
larik angka;//deklarasi variabel

//function untuk input data
void input_data(larik &X) {
    cout <<"Menginputkan data Numerik" <<endl;
    do {
    n++;
    cout <<"Masukkan data ke " <<n <<" :";cin>>X[n];
    }

    while ((X[n] != 0) and (n <= 10));
    n--;
}

void cetak_data(larik X){
    cout <<"Data yang sudah diinputkan \n";
    cout <<"----------------"<<endl;
    cout <<"No    Data\n";
    cout <<"----------------"<<endl;
    for (i = 1; i <= n; i++)
    cout <<i <<"     " <<X[i]<<endl;
    cout <<"-------------"<<endl;
    cout <<"Data sebanyak " <<n <<"buah\n";
}

float hitung_jumlah(larik X){
    float jum=0;
    for(i=1;i<=n;i++) jum+=X[i];
    return jum;
}
int main () {
    input_data(angka);//void
    cetak_data(angka);//void
    cout <<"Jumlah seluruh data = " <<hitung_jumlah(angka) <<endl; //funct
    cout <<"rata-rata dari " <<n <<"data tsb = " <<hitung_jumlah(angka)/n <<endl;
}

// coutMM setw(3)<<i<<setw(6)<<X[i]<<endl;