#include <iostream>

class DatePackage {
    private:
        int day;
        int month;
        int year;

    public:
        DatePackage(int d, int m, int y);
        ~DatePackage();

        void displayDayOfWeek();
        void printDate();
};

