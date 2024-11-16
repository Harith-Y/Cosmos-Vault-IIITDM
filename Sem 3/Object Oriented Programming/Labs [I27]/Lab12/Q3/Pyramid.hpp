#include "Triangle.hpp"
#include "Rectangle.hpp"

class Pyramid : public Triangle, public Rectangle {
public:
    void printShapeName() const override {
        cout << "Shape: Pyramid" << endl;
    }

    double area() const override {
        return baseArea;
    }
    
    Pyramid(double baseArea, double height);
    double volume() const override;
    void printShapeDetails() const override;

private:
    double baseArea;
    double height;
};



Pyramid :: Pyramid(double baseArea, double height)
    : baseArea(baseArea), height(height) {}

double Pyramid :: volume() const {
    return (1.0 / 3) * baseArea * height;
}

void Pyramid::printShapeDetails() const {
    cout << "Pyramid Details:" << endl;
    cout << "Base Area: " << baseArea << endl;
    cout << "Height: " << height << endl;
    cout << "Volume: " << volume() << endl;
}
