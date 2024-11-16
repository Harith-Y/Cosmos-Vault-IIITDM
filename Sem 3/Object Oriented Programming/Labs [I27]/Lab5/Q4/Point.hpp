#include <iostream>
#include <cmath>

class Point {
	private: double x, y;

	public: Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    public: double getX() const;
    public: double getY() const;
    public : void display() const;
};

