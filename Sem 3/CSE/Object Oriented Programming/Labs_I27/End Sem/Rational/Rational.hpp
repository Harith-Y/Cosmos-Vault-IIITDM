#include <iostream>

using namespace std;

class Rational {
    private:
        double num;
        double denom;
    public:
        Rational(double num = 0, double denom = 1) : num(num), denom(denom) {}
        friend ostream& operator << (ostream&, Rational&);

        Rational operator = (Rational);
        Rational operator + (Rational);
        


};

/*

Taking two Rational numbers as input of the format a+ib . 
i) Add 
ii) Subtract 
iii) Power
iv) Multiply 
v) Divide 
vi) Pre-increament 
vii) Post-increament (1/2 to 2/3 fashion)
viii) Overload istream and ostream

Use All the concepts of OOPS in C++, i.e. Data encapsulation, Abstraction, Inheritence, Polymorphism, Class Templates, Operator Overloading, Error/Exception Handling, 
Follow good practices of coding, i.e. Principal of Least Previlige, Interface and inmpementation seperation, etc.
Make all 3 types of Constructors. Handle Edge Cases


*/