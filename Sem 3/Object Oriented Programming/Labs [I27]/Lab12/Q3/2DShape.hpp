#ifndef TWODSHAPE_HPP
#define TWODSHAPE_HPP

#include "Shape.hpp"

class TwoDShape : public virtual Shape {
    public:
        double volume() const override { 
            return 0; 
        }
};

#endif