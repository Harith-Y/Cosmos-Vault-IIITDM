#include <iostream>
#include "Cylinder.hpp"

using namespace std;

int main() {
    Point p(1.0, 2.0);
    Circle c(p, 3.0);
    Cylinder cy(c, 5.0);

    cout << "Displaying Point:" << endl;
    p.display();

    cout << "Displaying Circle:" << endl;
    c.display();
    cout << "Area of Circle: " << c.area() << endl;

    cout << "Displaying Cylinder:" << endl;
    cy.display();
    cout << "Volume of Cylinder: " << cy.volume() << endl;

    return 0;
}

