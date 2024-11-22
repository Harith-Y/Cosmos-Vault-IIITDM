#include "2DShape.hpp"

class Triangle : public TwoDShape {
    protected:
        double base, height;

    public:
        Triangle(double b = 0, double h = 0) : base(b), height(h) {}
        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override;
};



void Triangle :: printShapeDetails() const {
    cout << "Triangle with base " << base << " and height " << height << endl;
}

void Triangle :: printShapeName() const {
    cout << "Shape: Triangle" << endl;
}

double Triangle :: area() const {
    return 0.5 * base * height;
}
