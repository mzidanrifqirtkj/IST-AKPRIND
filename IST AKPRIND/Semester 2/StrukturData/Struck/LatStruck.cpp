#include <iostream>
using namespace std;

struct siswa {
    string nama, nis, kelas;
};

int main () {
    struct siswa budi, thoriq;
    budi.nama = "budi";
    budi.nis = "2604";
    budi.kelas = "XII RPL C";

    thoriq.nama = "Mr Thoriq";
    thoriq.nis = "2605";
    thoriq.kelas  = "X TKJ C";

    cout<<"Nama Siswa 1  :"<<budi.nama<<endl;
    cout<<"NIS Siswa 1   :"<<budi.nis<<endl;
    cout<<"Kelas Siswa 1 :"<<budi.kelas<<endl;

    cout<<"Nama Siswa 2  :"<<budi.nama<<endl;
    cout<<"NIS Siswa 2   :"<<budi.nis<<endl;
    cout<<"Kelas Siswa 2 :"<<budi.kelas<<endl;    
}