#include "Time.hpp"

int main() {
	int h = 0, m = 0, s = 0;
	cout << "Enter hours: ";
	cin >> h;
	
	cout << "Enter minutes: ";
	cin >> m;
	
	cout << "Enter seconds: ";
	cin >> s;
	
    TimePackage time(h, m, s);

    time.printTime();
    time.convertTo12HourFormat();

    return 0;
}
