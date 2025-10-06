#include "NumberPackage.hpp"

int main () {

	NumberPackage test;
	
	int n;
	cout << "Enter the number you want the calculation to be performed on: ";
	cin >> n;
	test.init(n);

	int choice = 0;
	while ((cout << "1. Factorial" << endl << "2. Fibonacii" << endl << "3. Summation" << endl << "4. Square Summation" << endl << "5. Cube Summation" << endl << "6. Exit" << endl << "Please Enter a valid Input: ") && (cin >> choice) && (choice != 6)) {
		if (choice == 1)
			cout << "Result: " << test.factorial(test.getVal()) << endl << endl;
			
		else if (choice == 2)
			cout << "Result: " << test.fibonacii(test.getVal()) << endl << endl;
			
		else if (choice == 3)
			cout << "Result: " << test.sigma(test.getVal()) << endl << endl;
			
		else if (choice == 4)
			cout << "Result: " << test.sigma2(test.getVal()) << endl << endl;
			
		else if (choice == 5)
			cout << "Result: " << test.sigma3(test.getVal()) << endl << endl;
			
		else
			cout << "Please Enter a valid input!" << endl << endl;
	}
	
	cout << "Exiting..." << endl;

	return 0;
}
