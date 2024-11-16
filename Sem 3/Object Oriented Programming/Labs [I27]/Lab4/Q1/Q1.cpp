#include<iostream>

using namespace std;

int one = 1;
int function();


int main() {
	cout << "AUTO GLOBAL VARIABLE ONE(1) HAS BEEN CONSTRUCTED" << endl;
	int two = 2;
	cout << "AUTO VARIABLE TWO(2) HAS BEEN CONSTRUCTED" << endl;
	static int three = 3;
	cout << "STATIC VARIABLE THREE(3) HAS BEEN CONSTRUCTED" << endl;
	
	function();

	int four = 4;
	cout << "AUTO VARIABLE FOUR(4) IS CONSTRUCTED" << endl;
	cout << "AUTO VARIABLE FOUR(4) HAS BEEN DESTRUCTED" << endl;
	cout << "AUTO VARIABLE TWO(2) HAS BEEN DESTRUCTED" << endl;
	cout << "AUTO VARIABLE GLOBAL VARIABLE ONE(1) HAS BEEN DESTRUCTED" << endl;
	cout << "STATIC VARIABLE SIX(6) HAS BEEN DESTRUCTED" << endl;
	cout << "STATIC VARIABLE THREE(3) HAS BEEN DESTRUCTED" << endl;
	return 0;
}

int function() {
	int five = 5;
	cout << "AUTO VARIABLE FIVE(5) HAS BEEN CONSTRUCTED" << endl;
	static int six = 6;
	cout << "STATIC VARIABLE SIX(6) HAS BEEN CONSTRUCTED" << endl;
	cout << "AUTO VARIABLE FIVE(5) HAS BEEN DESTRUCTED" << endl;
	return 0;
}

