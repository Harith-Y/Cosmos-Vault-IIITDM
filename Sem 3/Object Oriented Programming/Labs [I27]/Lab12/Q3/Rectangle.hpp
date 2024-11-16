#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "2DShape.hpp"

class Rectangle : public virtual TwoDShape {
    protected:
        double length, width;

    public:
        Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
        virtual void printShapeDetails() const override;
        virtual void printShapeName() const override;
        virtual double area() const override;
        virtual ~Rectangle() = default;
};



void Rectangle :: printShapeDetails() const {
    cout << "Rectangle with length " << length << " and width " << width << endl;
}

void Rectangle :: printShapeName() const {
    cout << "Shape: Rectangle" << endl;
}

double Rectangle :: area() const {
    return length * width;
}

#endif