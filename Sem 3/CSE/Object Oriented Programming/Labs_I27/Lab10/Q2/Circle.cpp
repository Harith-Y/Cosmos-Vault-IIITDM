#include "Circle.hpp"

Circle :: Circle(double Px, double Py, double Pz, double rad) : Point(Px, Py, Pz), radius(rad) {
    calcArea();
}

Circle :: ~Circle() {
    cout << "Destructor for circle " << x << " " << y << " " << z << " " << radius << " " << area << " " << "called" << endl;
}


istream& operator >> (istream& i, Circle& c) {
    i >> c.x >> c.y >> c.z >> c.radius;
    c.calcArea();
    return i;
}

ostream& operator << (ostream& o, const Circle& c) {
    o << "The circle is centered at: " << c.x << " " << c.y << " "  << c.z << " " << "with radius " << c.radius << " " << "and area " << c.area << endl;
    return o;
}


void Circle :: calcArea() {
    double pi = 3.14;
    area = pi * radius * radius;
}
