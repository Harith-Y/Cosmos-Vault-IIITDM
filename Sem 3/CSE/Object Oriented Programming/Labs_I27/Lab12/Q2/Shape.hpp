#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

using namespace std;

class Shape {
    public:
        virtual ~Shape() {}

        virtual void printShapeDetails() const = 0;
        virtual void printShapeName() const = 0;
        virtual double area() const = 0;
        virtual double volume() const = 0;
};

#endif
