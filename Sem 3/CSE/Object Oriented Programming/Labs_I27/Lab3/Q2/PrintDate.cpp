#include "Date.hpp"

void DatePackage :: printDate() {
    cout << "Date: ";
    cout << (day < 10 ? "0" : "") << day << "/";
    cout << (month < 10 ? "0" : "") << month << "/";
    cout << year << endl;
}
