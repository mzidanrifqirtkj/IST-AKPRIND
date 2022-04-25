#include <iostream>
using namespace std;

struct barang{
    string kd_barang, nama;
    int harga;
};

int n=0, i, pil;
struct barang brg[20];

void tambah_barang(){
    cout<<"Masukkan kode barang : ";
    cin>>brg[n].kd_barang;
    cout<<"Masukkan nama barang : ";
    cin>>brg[n].nama;
    cout<<"Masukkan harga barang : ";
    cin>>brg[n].harga;
    n++;

    cout<<" Data berhasil ditambahkan"<<endl;
}

void tampil_barang(){
    cout<<"Tampilkan data barang"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"no   kode    nama    harga"<<endl;
    cout<<"----------------------------------"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<" "<<brg[i].kd_barang<<" "<<brg[i].nama<<" "<<brg[i].harga<<endl;
    }
    cout<<"----------------------------------"<<endl;
}

void edit_barang() {
    string edit;int i, pos, pilih;bool ada=false;
    tampil_barang();
    cout << "Masukkan kode barang yang akan diedit : ";cin>>edit;
    for (i = 0; i < n; i++)
    {
        if(brg[i].kd_barang==edit) {pos=i;ada=true;}
    }
    cout << edit << endl;
    
    if(ada)
    {
        cout<<"Anda akan mengedit barang"<<edit<<endl;
        cout<<"Posisi di record"<<pos<<endl;
        cout<<"Nama produk : "<<brg[pos].nama<<endl;
        cout<<"Harga produk : "<<brg[pos].harga<<endl;
        cout<<"Anda bisa mengedit barang : "<<endl;
        cout<<"1. Nama barang 2. Harga "<<endl;cin>>pilih;

        if (pilih==1)
            {   
                cout<<"Masukkan nama baru : ";cin>>brg[pos].nama;
            }
        else if(pilih==2)
            {
                cout<<"Masukkan harga barang yang baru : Rp ";cin>>brg[pos].harga;
            }

        else {cout<<"Salah Pilih "<<endl;
             cout<<"Editing telah dilakukan : "<<endl;}

    }
    else cout<<"Kode produk"<<edit<<"tidak ditemukan";
}

void hapus_barang () {
    string hapus; char ya;  
    tampil_barang();
    cout<<"Menghapus data barang : ";
    cout<<"Masukkan kode barang yang ingin diedit ";cin>>hapus;

    cout<<"Apakah yakin akan dihapus? ";cin>>ya;
    if((ya=='Y') || (ya=='y')){
		cout<<"Data telah dihapus "<<endl;
		for(i=0;i<n;i++){
            if (brg[i].kd_barang==hapus) {
                for (int j=0;j<n;j++) {
                    brg[j]=brg[j+1];
                }
            }
        }
		n--;
		}
	else cout << "Data tidak jadi dihapus \n";
}

int main () {
    int pil;
    do{
    system("cls");
    cout<<"Progam CRUD Barang"<<endl;
    cout<<"1. Tambah Barang"<<endl;
    cout<<"2. Tampil Barang"<<endl;
    cout<<"3. Edit Barang"<<endl;
    cout<<"4. Hapus Barang"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Masukkan pilihan anda : "<<endl;
    cin>>pil;

    switch(pil) {
        case 1:
            tambah_barang();
            break;
        case 2:
            tampil_barang();
            break;
        case 3:
            edit_barang();
            break;
        case 4:
            hapus_barang();
            break;
        case 0:
            // tambah_barang();
            break;
    }
    cin.ignore();cin.get();//Pascal = 
} while(pil != 0);
}
