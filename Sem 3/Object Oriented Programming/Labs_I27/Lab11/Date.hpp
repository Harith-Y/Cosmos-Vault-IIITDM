// date.hpp
#include <iostream>
using namespace std;

class DatePackage {
    private:
        int day;
        int month;
        int year;

        bool isLeapYear(int y);
        int daysInMonth(int m, int y);

    public:
        DatePackage(int d, int m, int y);
        ~DatePackage();

        void displayDayOfWeek();
        void printDate();

        // Overload operators for increment
        DatePackage& operator ++ ();         // Pre-increment by 1 day
        DatePackage operator ++ (int);       // Post-increment by 1 day
        DatePackage& operator += (int days); // Increment by N days
};
