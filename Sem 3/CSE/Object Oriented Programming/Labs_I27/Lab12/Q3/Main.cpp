#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "Pyramid.hpp"

int main() {
    Shape* shapes[8];
    
    shapes[0] = new Point(1, 2, 3);
    shapes[1] = new Circle(1, 2, 3, 4);
    shapes[2] = new Cylinder(1, 2, 3, 4, 5);
    shapes[3] = new Rectangle(10, 5);
    shapes[4] = new Triangle(8, 4);
    shapes[5] = new Sphere(7);
    shapes[6] = new Cone(5, 12);
    shapes[7] = new Pyramid(10.0, 15.0);

    for (int i = 0; i < 8; ++i) {
        shapes[i] -> printShapeName();
        shapes[i] -> printShapeDetails();

        cout << "Area: " << shapes[i] -> area() << endl;
        cout << "Volume: " << shapes[i] -> volume() << endl << endl;
        
        // Check if shape is 3D to access lateral surface area
        if (ThreeDShape* shape3D = dynamic_cast<ThreeDShape*>(shapes[i]))
            cout << "Lateral Surface Area: " << shape3D -> lateralSurfaceArea() << endl;
        
        cout << endl;
    }

    for (int i = 0; i < 7; ++i)
        delete shapes[i];

    return 0;
}


