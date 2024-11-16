#include "Cylinder.hpp"

int main() {
    Shape *shapes[3];

    shapes[0] = new Point(1, 2, 3);
    shapes[1] = new Circle(1, 2, 3, 4);
    shapes[2] = new Cylinder(1, 2, 3, 4, 5);

    for (int i = 0; i < 3; ++i) {
        shapes[i]->printShapeName();
        shapes[i]->printShapeDetails();
        
        cout << "Area: " << shapes[i] -> area() << endl;
        cout << "Volume: " << shapes[i] -> volume() << endl << endl;
    }

    for (int i = 0; i < 3; ++i)
        delete shapes[i];

    return 0;
}
