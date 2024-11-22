#include "Cylinder.hpp"

Cylinder :: Cylinder(double Px, double Py, double Pz, double rad, double ht) : Circle(Px, Py, Pz, rad) {
    height = ht;
    calcCSA();
    calcFSA();
    calcTSA();
    calcVolume();
}

Cylinder :: ~Cylinder() {
    cout << "Destructor for Cylinder: " << x << " " << y << " " << z << " " << radius << " " << height << " " << "called" << endl;
}


istream & operator >>(istream &i, Cylinder &c) {
    i >> c.x >> c.y >> c.z >> c.radius >> c.height;
    c.calcArea();
    c.calcCSA();
    c.calcFSA();
    c.calcTSA();
    c.calcVolume();
    return i;
}

ostream & operator <<(ostream &o, const Cylinder &c) {
    o << "Cylinder's base centered at " << c.x << " " << c.y << " " << c.z << " " << "with radius" << " " << c.radius << " " << "and height" << " " << c.height << endl;
    o << "The FSA, CSA and TSA are: " << c.FSA << " " << c.CSA << " " << c.TSA << " " << "and its volume is: " << c.volume << endl;
    return o;
}


void Cylinder :: calcFSA() {
    FSA = area * 2;
}

void Cylinder :: calcCSA() {
    double pi = 3.14;
    CSA = 2 * pi * radius * height;
}

void Cylinder :: calcTSA() {
    TSA = CSA + FSA;
}

void Cylinder :: calcVolume() {
    volume = area * height;
}
