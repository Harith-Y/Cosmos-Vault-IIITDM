#include "Graduate.hpp"

Graduate :: Graduate(char *fname, char *lname, char *degree) : Student(fname, lname) {
    int len = 0;
    for (char *p = degree; *p; ++p)
        ++len;

    degree = new char[len + 1];
    for (int i = 0; i <= len; ++i) 
        degree[i] = degree[i];
}

ostream & operator << (ostream &o, const Graduate &grad) {
    o << "First Name is\t" << static_cast<Student>(grad) << endl << "Degree is\t" << grad.degree << endl;
    return o;
}


Graduate :: ~Graduate() {
    delete[] degree;
}
