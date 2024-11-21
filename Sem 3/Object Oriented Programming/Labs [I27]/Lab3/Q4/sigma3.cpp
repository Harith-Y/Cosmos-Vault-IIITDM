#include "numberPackage.hpp"

int NumberPackage :: sigma3(int num) {
	if (num < 0) {
		cout << "Invalid Input";
		return 0;
	}
	
	else
		return (num * num * (num + 1) * (num + 1)) / 4;
}
