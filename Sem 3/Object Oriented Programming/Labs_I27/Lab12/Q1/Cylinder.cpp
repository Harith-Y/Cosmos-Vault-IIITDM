#include "Cylinder.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

Cylinder :: Cylinder(double Px, double Py, double Pz, double rad, double ht) : Circle(Px, Py, Pz, rad), height(ht) {
    calcVolume();
}

Cylinder :: ~Cylinder() {
    cout << "Destructor for cylinder with height " << height << " called" << endl;
}

void Cylinder :: calcVolume() {
    cylinderVolume = Circle :: area() * height;
}

void Cylinder :: printShapeDetails() const {
    cout << "Cylinder with base centered at (" << x << ", " << y << ", " << z << "), radius " << radius
         << ", height " << height << ", area " << area() << ", and volume " << volume() << endl;
}

void Cylinder :: printShapeName() const {
    cout << "Shape: Cylinder" << endl;
}

double Cylinder :: area() const {
    return 2 * Circle :: area() + 2 * M_PI * radius * height; // Total Surface Area
}

double Cylinder :: volume() const {
    return Circle :: area() * height;
}
