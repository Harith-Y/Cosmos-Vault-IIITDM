#include <iostream>
#include "numberPackage.hpp"

using namespace std;

void NumberPackage :: init(int val) {
	if (val >= 0)
		data = val;
	else 
		cout << "Please enter a non-negative integer" << endl;
}
