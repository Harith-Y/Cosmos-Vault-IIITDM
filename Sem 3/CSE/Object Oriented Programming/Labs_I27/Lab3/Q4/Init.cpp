#include "numberPackage.hpp"

void NumberPackage :: init(int val) {
	if (val >= 0)
		data = val;
	else 
		cout << "Please enter a non-negative integer" << endl;
}
