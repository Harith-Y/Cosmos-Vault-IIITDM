#include <iostream>
#include "Point.hpp"

class Circle {
	private: Point center;
	private: double radius;

	public: Circle(Point center = Point(), double radius = 1.0) : center(center), radius(radius) {}

    public: double getRadius() const;
    public: Point getCenter() const;
    public: double area() const;
	public: void display() const;
};

