#include <iostream>
#include "time.hpp"

using namespace std;

void TimePackage::printTime() {
    cout << "24-hour format: ";
    cout << (hours < 10 ? "0" : "") << hours << ":";
    cout << (minutes < 10 ? "0" : "") << minutes << ":";
    cout << (seconds < 10 ? "0" : "") << seconds << endl;
}

