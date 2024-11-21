#include "Date.hpp"

class Employee {
    private:
        char fname[25];
        char lname[25];
        const Date BirthDate;
        const Date JoinDate;

    public:
        Employee(const char*, const char*, int, int, int, int, int, int);
        void display() const;
        ~Employee();
};
