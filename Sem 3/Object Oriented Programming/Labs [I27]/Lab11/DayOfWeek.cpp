#include "date.hpp"

// Function to calculate the day of the week
const char* getDayOfWeek(int day, int month, int year) {
    // Adjust months so March is the first month (for Zeller's Congruence)
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    return days[dayOfWeek];
}

// Method to display the day of the week
void DatePackage :: displayDayOfWeek() {
    const char* dayName = getDayOfWeek(day, month, year);
    cout << "Day of the week: " << dayName << endl;
}
