#include "Date.hpp"

Date :: Date(int m, int y, int d) {
    cout << "Constructor for date object" << endl;

    if (m > 0 && m <= 12)
        month = m;
    else
        month = 1;

    year = ( (y > 1900 && y < 2075) ? y : 0 );
    day = checkday(d);
}


Date :: ~Date() {
    cout << "Destructor for date object" << endl;
}

void Date :: display() const {
    cout << day << "/" << month << "/" << year << endl;
}

int Date :: checkday(int today) {
    static const int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((today > 0) && (today <= daysOfMonth[month]))
        return today;

    if ((month == 2) && (today == 29) && ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
        return today;

    cout << "Invalid Day Value" << endl;
    return 1;
}
