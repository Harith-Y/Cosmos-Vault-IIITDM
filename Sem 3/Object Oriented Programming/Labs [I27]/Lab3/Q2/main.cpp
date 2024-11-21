#include "Date.hpp"

int main() {
    DatePackage date1(21, 11, 2024);

    date1.printDate();
    date1.displayDayOfWeek();
    cout << endl;

    DatePackage date2(1, 1, 2000);

    date2.printDate();
    date2.displayDayOfWeek();
    cout << endl;

    // Uncomment the following lines to test error handling
    // DatePackage invalidDate(32, 13, 2024);s

    return 0;
}
