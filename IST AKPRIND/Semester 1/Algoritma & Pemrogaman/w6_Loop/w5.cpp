#include <iostream>
using namespace std;

int a[10];

int main () {
    //Input data
    int i=0;
    for ( i = 1; i <=4 ; i++) {
        cout<<"Masukkan bilangan bulat ke "<<i<<" ="<<endl;
        cin>>a[i];
    }
        cout<<endl;
    
        //mencetak hasil
    for ( i = 1; i <= 4; i++){
            cout<<"Bilangan ke : "<<i<<" ="<<a[i]<<endl;
    }
        
    
    

}
