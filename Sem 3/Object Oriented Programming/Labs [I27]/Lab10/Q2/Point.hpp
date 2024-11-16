#include <iostream>
using namespace std;

class Point {
    protected:
        double x;
        double y;
        double z;
        friend ostream & operator <<(ostream &, const Point &);
        friend istream & operator >>(istream &, Point &);

    public:
        Point(double = 0, double = 0, double = 0);
        ~Point();
};
