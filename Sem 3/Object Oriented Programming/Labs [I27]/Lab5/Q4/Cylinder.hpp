#include "Circle.hpp"

class Cylinder {
	private: 
        Circle base;
	    double height;

    public:
        Cylinder(Circle base = Circle(), double height = 1.0) : base(base), height(height) {}

        Circle getBase() const;
        double getHeight() const;
        double volume() const;
        void display() const;
};
