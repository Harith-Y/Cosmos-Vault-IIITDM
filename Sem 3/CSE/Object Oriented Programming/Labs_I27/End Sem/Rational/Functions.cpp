#include "Rational.hpp"

Rational Rational :: operator = (Rational other) {
    num = other.num;
    denom = other.denom;

    return *this;
}

Rational Rational :: operator + (Rational other) {
    Rational temp;

    temp.num = num + other.num;
    temp.denom = denom + other.denom;
    
    return temp;
}

ostream& operator << (ostream&o, Rational&R) {
    o << R.num << " " << R.denom << endl;
}
