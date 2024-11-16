#include "header.hpp"

Example :: Example(int a, int b, int c) : x(a), y(b), z(c) {}

void Example :: print() {
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
}

void Example :: increment() {
    x++;
    y++;
    z++;
}

Example Example :: operator ++ (int) {
    Example temp = *this;
    increment();
    return temp;
}

Example& Example :: operator ++ () {
    increment();
    return *this;
}

Example& Example :: operator = (const Example& obj){
    x = obj.x;
    y = obj.y;
    z = obj.z;
    return *this;
}