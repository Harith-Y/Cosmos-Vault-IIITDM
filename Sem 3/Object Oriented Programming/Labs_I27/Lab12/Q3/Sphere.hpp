#include "3DShape.hpp"

class Sphere : public ThreeDShape {
    protected:
        double radius;

    public:
        Sphere(double r = 0) : radius(r) {}
        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override;
        double volume() const override;
        double lateralSurfaceArea() const override { 
            return area(); 
        }
};



void Sphere :: printShapeDetails() const {
    cout << "Sphere with radius " << radius << endl;
}

void Sphere :: printShapeName() const {
    cout << "Shape: Sphere" << endl;
}

double Sphere :: area() const {
    return 4 * 3.14 * radius * radius;
}

double Sphere :: volume() const {
    return (4.0/3.0) * 3.14 * radius * radius * radius;
}
