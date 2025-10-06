#include "Graduate.hpp"

Graduate :: Graduate(char *fname, char *lname, char *degreeParam) : Student(fname, lname) {
    int len = 0;
    for (char *p = degreeParam; *p; ++p)
        ++len;

    degree = new char[len + 1];

    for (int i = 0; i <= len; ++i) 
        degree[i] = degreeParam[i];
}

ostream& operator << (ostream& o, const Graduate& grad) {
    o << "First Name is\t" << static_cast<const Student&>(grad) << endl << "Degree is\t" << grad.degree << endl;
    return o;
}


Graduate :: ~Graduate() {
    delete[] degree;
}
