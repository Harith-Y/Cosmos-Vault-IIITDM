#include "date.hpp"

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
    // Destructor logic
    cout << "Destructor called" << endl;
}

void DatePackage :: printDate() {
    cout << "Date: ";
    cout << (day < 10 ? "0" : "") << day << "/";
    cout << (month < 10 ? "0" : "") << month << "/";
    cout << year << endl;
}

bool DatePackage :: isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DatePackage :: daysInMonth(int m, int y) {
    if (m == 2)
        return isLeapYear(y) ? 29 : 28;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return daysInMonth[m - 1];
}

DatePackage& DatePackage :: operator++() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    return *this;
}

DatePackage DatePackage :: operator++(int) {
    DatePackage temp = *this;
    ++(*this);

    return temp;
}

DatePackage& DatePackage :: operator+=(int days) {
    while (days-- > 0)
        ++(*this);

    return *this;
}

