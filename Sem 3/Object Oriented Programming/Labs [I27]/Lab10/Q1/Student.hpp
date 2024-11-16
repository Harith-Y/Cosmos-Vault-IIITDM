#include <iostream>

using namespace std;

class Student {
    protected : char * fname;
    protected : char * lname;

    friend ostream & operator << (ostream &, const Student &);
    public : Student(char * = " ", char * = " ");

    ~Student();
};
