#include "Header.hpp"

void Example :: print() {
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
}

void Example :: increment() {
    x++;
    y++;
    z++;
}


// Post increment
Example Example :: operator ++ (int) {
    Example temp = *this;
    increment();
    return temp;
}

// Pre increment
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
