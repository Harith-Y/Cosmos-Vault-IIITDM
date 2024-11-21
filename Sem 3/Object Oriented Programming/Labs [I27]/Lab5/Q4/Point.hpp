#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Point {
	private: 
        double x, y;

	public: 
        Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
        ~Point() {}

        double getX() const;
        double getY() const;
        void display() const;
};
