#ifndef THREEDSHAPE_HPP
#define THREEDSHAPE_HPP

#include "Shape.hpp"

class ThreeDShape : public virtual Shape {
    public:
        virtual double lateralSurfaceArea() const = 0;
};

#endif