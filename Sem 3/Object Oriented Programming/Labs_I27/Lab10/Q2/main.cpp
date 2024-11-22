#include "Cylinder.hpp"

int main() {
    Point P(1, 2, 3);
    cout << P;

    cout << "Enter the point's coordinates: " << endl;
    cin >> P;
    cout << P;

    Circle C(1, 2, 3, 4);
    cout << C;

    cout << "Enter the circle's center and radius: " << endl;
    cin >> C;
    cout << C;

    Cylinder Cyl(1, 2, 3, 4, 5);
    cout << Cyl;

    cout << "Enter the cylinder's center, radius, and height: " << endl;
    cin >> Cyl;
    cout << Cyl;

    return 0;
}
