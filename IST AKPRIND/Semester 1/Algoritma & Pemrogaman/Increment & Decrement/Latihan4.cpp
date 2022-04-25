//
#include <iostream> 

using namespace std;

int main () {

	//statement increment
	for (int index = 3; index < 5; index++) {
		cout << index << endl;
	}
	
	cout << endl;

	//statement decrement
	
	for (int i = 5; i >= 1; i--) {
		cout << i << endl;
	}
	
	//statement while
	int i = 10;
	while(i <= 20) {
		cout << i << ", ";
		i++;
		}
	cout << endl;
	
	//statement do while
	int angka = 30;
	do { 		
		cout << angka << ", ";
		angka++; 
	} while (angka < 40);
		
		
}

