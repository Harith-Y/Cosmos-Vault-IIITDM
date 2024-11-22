#include "Circle.hpp"

class Cylinder : public Circle {
    protected:
        double height;
        double cylinderVolume;

    public:
        Cylinder(double = 0, double = 0, double = 0, double = 0, double = 0);
        ~Cylinder();

        // Declare these functions as const to match the definitions
        void printShapeDetails() const override;
        void printShapeName() const override;
        double area() const override;
        double volume() const override;

        friend ostream& operator << (ostream& , const Cylinder& );
        friend istream& operator >> (istream& , Cylinder& );

    private:
        void calcCSA();
        void calcTSA();
        void calcVolume();
};
