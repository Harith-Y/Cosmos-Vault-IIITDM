#include "Student.hpp"

int mystrlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char* mystrcpy(char* dest, char* src) {
    char* start = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return start;
}


Student :: Student(char* first, char* last) {
    fname = new char[mystrlen(first) + 1];
    mystrcpy(fname, first);
    lname = new char[mystrlen(last) + 1];
    mystrcpy(lname, last);
}


ostream & operator << (ostream &o, const Student &stud) {
    o << "First Name is\t" << stud.fname << endl << "Last Name is\t" << stud.lname << endl;
    return o;
}


Student :: ~Student() {
    delete[] fname;
    delete[] lname;
}

