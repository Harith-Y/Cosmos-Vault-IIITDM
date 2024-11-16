#include "Cylinder.hpp"

using namespace std;

Circle Cylinder :: getBase() const { 
	return base; 
}

double Cylinder :: getHeight() const { 
	return height; 
}

double Cylinder :: volume() const {
    return base.area() * height;
}

void Cylinder :: display() const {
    cout << "Cylinder with ";
    base.display();
    cout << "and height " << height << endl;
}

