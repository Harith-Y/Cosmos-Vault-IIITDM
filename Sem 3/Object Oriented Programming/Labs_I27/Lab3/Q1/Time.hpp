#include <iostream>

using namespace std;

class TimePackage {
	private: 
		int hours;
		int minutes;
		int seconds;
	
	public: 
		TimePackage(int h, int m, int s);
		~TimePackage();
	
		void convertTo12HourFormat();
		void printTime();
};
