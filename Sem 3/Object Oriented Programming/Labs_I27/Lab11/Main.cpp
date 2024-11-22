// main.cpp
#include "date.hpp"

int main() {
    DatePackage date1(28, 2, 2020); // Leap year case
    cout << "Initial (Given) Date: ";
    date1.printDate();
    ++date1;

    cout << "After pre-increment: ";
    date1.printDate();

    date1++; // Post-increment
    cout << "After post-increment: ";
    date1.printDate();

    int n;
    cout << "\nEnter the number of days to increment: ";
    cin >> n;

    DatePackage date2(28, 12, 2020); // End of year case
    cout << "Initial Date: ";
    date2.printDate();

    date2 += n; // Increment by n days
    cout << "After incrementing by " << n << " days: ";
    date2.printDate();

    return 0;
}
