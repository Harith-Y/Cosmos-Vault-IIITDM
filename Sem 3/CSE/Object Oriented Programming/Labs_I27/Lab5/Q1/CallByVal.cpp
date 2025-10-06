#include <iostream>

using namespace std;

void swap (int, int);

int main() {
	int a = 0, b = 0;
	cout << "Enter Number 1: ";
	cin >> a;
	
	cout << "Enter Number 2: ";
	cin >> b;
	
	swap(a, b);
	
	cout << endl << "OUTSIDE FUNCTION: Numbers after swapping are:" << endl
		 << "Number 1: " << a << endl << "Number 2: " << b << endl;
	
	return 0;
}

void swap (int no1, int no2) {
	int temp;
	temp = no1;
	no1 = no2;
	no2 = temp;
	
	cout << endl << "IN FUNCTION: Numbers after swapping are:" << endl
		 << "Number 1: " << no1 << endl << "Number 2: " << no2 << endl;
}
