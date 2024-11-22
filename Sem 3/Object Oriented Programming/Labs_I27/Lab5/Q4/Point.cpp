#include "Point.hpp"

double Point :: getX() const { 
	return x; 
}

double Point :: getY() const { 
	return y; 
}

void Point :: display() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}
