#include <iostream>

using namespace std;

class SortPackage {
	public:
		void swap(int&, int&);
		void swap(float&, float&);
		void swap(char&, char&) ;
		void sort(int [], int);
		void sort(float [], int);
		void sort(char [], int);
};
