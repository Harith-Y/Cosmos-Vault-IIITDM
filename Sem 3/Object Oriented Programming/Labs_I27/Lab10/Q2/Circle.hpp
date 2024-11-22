#include "Point.hpp"

class Circle : protected Point {
    protected:
        double radius;
        double area;

        void calcArea();

        friend ostream& operator << (ostream&, const Circle&);
        friend istream& operator >> (istream&, Circle&);
    
    public:
        Circle(double = 0, double = 0, double = 0, double = 0);
        ~Circle();

};
