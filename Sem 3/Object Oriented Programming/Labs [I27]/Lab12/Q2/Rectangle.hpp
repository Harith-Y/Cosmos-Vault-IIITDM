#include "2DShape.hpp"

class Rectangle : public TwoDShape {
    protected:
        double length, width;

    public:
        Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override;
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
