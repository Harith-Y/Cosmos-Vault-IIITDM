#include "Time.hpp"
#include <cstring>

void TimePackage :: convertTo12HourFormat() {
    int hour12 = hours % 12;
    if (hour12 == 0)
    	hour12 = 12;

    string period = (hours >= 12) ? "PM" : "AM";

    cout << "12-hour format: ";
    cout << (hour12 < 10 ? "0" : "") << hour12 << ":";
    cout << (minutes < 10 ? "0" : "") << minutes << ":";
    cout << (seconds < 10 ? "0" : "") << seconds << " ";
    cout << period << endl;
}
