#include "Point.hpp"

class Circle {
	private: 
		Point center;
		double radius;

	public: 
		Circle(Point center = Point(), double radius = 1.0) : center(center), radius(radius) {}
		~Circle() {}

    	double getRadius() const;
    	Point getCenter() const;
    	double area() const;
		void display() const;
};
