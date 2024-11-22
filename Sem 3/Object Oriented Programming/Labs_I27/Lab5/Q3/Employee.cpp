#include <cstring>
#include "Employee.hpp"

Employee :: Employee(const char *fn, const char *ln, int bm, int bd, int by, int jd, int jm, int jy) : BirthDate(bm, bd, by), JoinDate(jm, jd, jy) {
    int length = strlen(fn);
    strncpy(fname, fn, length);
    fname[length] = '\0';

    length = strlen(ln);
    strncpy(lname, ln, length);
    lname[length] = '\0';
    
    cout << "Constructor for employee object " << fname << lname << endl;
}

void Employee :: display() const {
    cout << lname << ", " << fname;
    JoinDate.display();
    BirthDate.display();
    cout << endl;
}

Employee :: ~Employee() {
    cout << "Destructor called for employee " << fname << lname << endl;
}
