#include "time.hpp"	
#include <iostream>

using namespace std;

TimePackage::TimePackage(int h, int m, int s) {
    if ((h < 0) || (h > 23)) {
        cerr << "Error: Value of Hours must be from 0 to 23." << endl;
        exit(EXIT_FAILURE);
    }
    if ((m < 0) || (m > 59)) {
        cerr << "Error: Value of Minutes must be from 0 to 59." << endl;
        exit(EXIT_FAILURE);
    }
    if ((s < 0) || (s > 59)) {
        cerr << "Error: Value of Seconds must be from 0 to 59." << endl;
        exit(EXIT_FAILURE);
    }

    hours = h;
    minutes = m;
    seconds = s;
}

TimePackage::~TimePackage() {
    // Destructor logic
}

