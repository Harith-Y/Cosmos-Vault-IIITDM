#include <iostream>
#include "numberPackage.hpp"

using namespace std;

int NumberPackage :: factorial(int num) {
	if (num < 0) {
		cout << "Invalid Input";
		return 0;
	}
	else if ((num == 0) || (num == 1))
		return 1;
	else
		return num * factorial(num - 1);
}
