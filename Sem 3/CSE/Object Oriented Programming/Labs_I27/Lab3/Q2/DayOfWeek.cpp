#include "Date.hpp"
#include <cstring>

string getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[dayOfWeek];
}

void DatePackage :: displayDayOfWeek() {
    string dayName = getDayOfWeek(day, month, year);
    cout << "Day of the week: " << dayName << endl;
}
