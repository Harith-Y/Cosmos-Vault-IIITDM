#include "Student.hpp"

class Graduate : public Student {
    friend ostream & operator << (ostream &, const Graduate &);
    public : Graduate (char * = " ", char * = " ", char * = " ");
    public : ~Graduate();

    protected : char * degree;
};
