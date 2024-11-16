#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "2DShape.hpp"

class Triangle : public virtual TwoDShape {
    protected:
        double base, height;

    public:
        Triangle(double b = 0, double h = 0) : base(b), height(h) {}
        virtual void printShapeDetails() const override;
        void printShapeName() const override;
        virtual double area() const override;
        virtual ~Triangle() = default;
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

#endif