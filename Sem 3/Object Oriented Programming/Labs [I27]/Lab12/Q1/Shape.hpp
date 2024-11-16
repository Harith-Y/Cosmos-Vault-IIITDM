#include <iostream>
using namespace std;

class Shape {
    public:
        virtual ~Shape() {}

        // Pure virtual functions to enforce implementation in derived classes
        virtual void printShapeDetails() const = 0;
        virtual void printShapeName() const = 0;
        virtual double area() const = 0;
        virtual double volume() const = 0;
};
