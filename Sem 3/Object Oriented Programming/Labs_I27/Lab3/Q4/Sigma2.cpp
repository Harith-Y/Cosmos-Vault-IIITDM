#include "numberPackage.hpp"


int NumberPackage :: sigma2(int num) {
	if (num < 0) {
		cout << "Invalid Input";
		return 0;
	}
	
	else
		return (num * (num + 1) * (2 * num + 1)) / 6;
}
