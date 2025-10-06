#include "Circle.hpp"

Circle :: Circle(double Px, double Py, double Pz, double rad) : Point(Px, Py, Pz), radius(rad) {
    calcArea();
}

Circle :: ~Circle() {
    cout << "Destructor for circle at (" << x << ", " << y << ", " << z << ") with radius " << radius << " called" << endl;
}

void Circle :: printShapeDetails() const {
    cout << "Circle at (" << x << ", " << y << ", " << z << ") with radius " << radius << " and area " << area() << endl;
}

void Circle :: printShapeName() const {
    cout << "Shape: Circle" << endl;
}

double Circle :: area() const {
    return 3.14 * radius * radius;
}

void Circle :: calcArea() {
    // Calculate and store area internally if needed
}
