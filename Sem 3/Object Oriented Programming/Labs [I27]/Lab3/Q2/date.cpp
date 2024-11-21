#include "Date.hpp"

DatePackage :: DatePackage(int d, int m, int y) {
    if ((d < 1) || (d > 31)) {
        cerr << "Error: Day must be from 1 to 31." << endl;
        exit(EXIT_FAILURE);
    }
    if ((m < 1) || (m > 12)) {
        cerr << "Error: Month must be from 1 to 12." << endl;
        exit(EXIT_FAILURE);
    }
    if (y < 1) {
        cerr << "Error: Year must be a positive integer." << endl;
        exit(EXIT_FAILURE);
    }

    day = d;
    month = m;
    year = y;
}

DatePackage :: ~DatePackage() {
    cout << "Destructor called for Date Package" << endl;
}
