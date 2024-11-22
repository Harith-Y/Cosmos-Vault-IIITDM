#ifndef POINT_HPP
#define POINT_HPP

#include "Shape.hpp"

class Point : public Shape {
    protected:
        double x, y, z;

    public:
        Point(double = 0, double = 0, double = 0);
        ~Point();

        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override { return 0; } // Points have no area
        double volume() const override { return 0; } // Points have no volume

        friend ostream& operator << (ostream& , const Point& );
        friend istream& operator >> (istream& , Point& );
};

#endif
