#include "Circle.hpp"

double Circle :: getRadius() const { 
	return radius; 
}

Point Circle :: getCenter() const { 
	return center; 
}

double Circle :: area() const {
    return M_PI * radius * radius;
}

void Circle :: display() const {
    cout << "Circle centered at ";
    center.display();
    cout << "with radius " << radius << endl;
}
