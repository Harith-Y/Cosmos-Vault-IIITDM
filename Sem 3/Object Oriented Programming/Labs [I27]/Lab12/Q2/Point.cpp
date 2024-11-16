#include "Point.hpp"

Point :: Point(double Px, double Py, double Pz) : x(Px), y(Py), z(Pz) {}

Point :: ~Point() {
    cout << "Destructor for point " << x << " " << y << " " << z << " called" << endl;
}

void Point :: printShapeDetails() const {
    cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
}

void Point :: printShapeName() const {
    cout << "Shape: Point" << endl;
}

istream & operator >>(istream &i, Point &p) {
    i >> p.x >> p.y >> p.z;
    return i;
}

ostream & operator <<(ostream &o, const Point &p) {
    o << "Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
    return o;
}
