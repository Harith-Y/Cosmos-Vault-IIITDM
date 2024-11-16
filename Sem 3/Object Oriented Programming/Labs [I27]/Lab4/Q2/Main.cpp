#include "Main.hpp"

using namespace std;

ExampleClass O1(1);

int fun() {
	ExampleClass O5(5);
	static ExampleClass o6(6);
	ExampleClass O7(7);
	return 0;
}

int main() {
	
	static ExampleClass O2(2);
	
	ExampleClass O3(3);
	
	fun();
	
	ExampleClass(4);
	
	cout << "Exiting..." << endl;
	return 0;
}	
