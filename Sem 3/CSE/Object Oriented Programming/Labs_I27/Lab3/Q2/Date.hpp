#include <iostream>

using namespace std;

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

