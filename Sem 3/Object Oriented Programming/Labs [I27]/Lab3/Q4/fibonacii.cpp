#include "numberPackage.hpp"

int NumberPackage :: fibonacii(int num) {
	if (num == 0) {
		cout << "Invalid Input";
		return 0;
	}
	
	else if ((num == 1) || (num == 2))
		return 1;
	
	else
		return fibonacii(num - 1) + fibonacii(num - 2);
}
