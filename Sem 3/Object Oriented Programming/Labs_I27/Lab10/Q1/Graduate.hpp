#include "Student.hpp"

class Graduate : public Student {
    friend ostream& operator << (ostream& , const Graduate& );

    public:
        Graduate (char * = " ", char * = " ", char * = " ");
        ~Graduate();

    protected : 
        char * degree;
};