#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.hpp"

class Circle : public Point {
    protected:
        double radius;

    public:
        Circle(double = 0, double = 0, double = 0, double = 0);
        ~Circle();

        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override;
        double volume() const override { return 0; } // Circles have no volume

        friend ostream & operator <<(ostream &, const Circle &);
        friend istream & operator >>(istream &, Circle &);

    private:
        void calcArea();
};

#endif