#include "Circle.hpp"

class Cylinder : protected Circle {
    protected:
        double height;
        double TSA;
        double CSA;
        double FSA;
        double volume;

        void calcCSA();
        void calcTSA();
        void calcFSA();
        void calcVolume();

        friend ostream& operator << (ostream& , const Cylinder& );
        friend istream& operator >> (istream& , Cylinder& );

    public:
        Cylinder(double = 0, double = 0, double = 0, double = 0, double = 0);
        ~Cylinder();
};
