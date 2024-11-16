#include <iostream>
#include "Circle.hpp"

class Cylinder {
	private: Circle base;
	private: double height;

	public: Cylinder(Circle base = Circle(), double height = 1.0) : base(base), height(height) {}

    public: Circle getBase() const;
    public: double getHeight() const;
    public: double volume() const;
    public: void display() const;
};

