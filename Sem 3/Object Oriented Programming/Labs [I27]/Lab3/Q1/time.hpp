#include <iostream>

class TimePackage {
	private: int hours;
	private: int minutes;
	private: int seconds;
	
	public: TimePackage(int h, int m, int s);
	public: ~TimePackage();
	
	public: void convertTo12HourFormat();
	public: void printTime();
};

