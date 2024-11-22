#include "3DShape.hpp"
#include <cmath>

class Cone : public ThreeDShape {
    protected:
        double radius, height;

    public:
        Cone(double r = 0, double h = 0) : radius(r), height(h) {}
        void printShapeDetails() const override;

        void printShapeName() const override;
        double area() const override;
        double volume() const override;
        double lateralSurfaceArea() const override;
};



void Cone :: printShapeDetails() const {
    cout << "Cone with radius " << radius << " and height " << height << endl;
}

void Cone :: printShapeName() const {
    cout << "Shape: Cone" << endl;
}

double Cone :: area() const {
    double slantHeight = sqrt(radius * radius + height * height);
    return 3.14 * radius * (radius + slantHeight);
}

double Cone :: volume() const {
    return (1.0/3.0) * 3.14 * radius * radius * height;
}

double Cone :: lateralSurfaceArea() const {
    double slantHeight = sqrt(radius * radius + height * height);
    return 3.14 * radius * slantHeight;
}
