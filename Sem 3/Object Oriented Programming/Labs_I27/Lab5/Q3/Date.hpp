#include <iostream>

using namespace std;

class Date {
    private:
        int month;
        int day;
        int year;
        int checkday(int);

    public:
        Date(int = 1, int = 1, int = 2003);
        void display() const;
        ~Date();
};
