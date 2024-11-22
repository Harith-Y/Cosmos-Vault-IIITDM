#include "Header.hpp"

int main() {
    Example obj1(1, 2, 3);
    Example obj2(4, 5, 6);
    Example obj3;

    cout << "obj1: ";
    obj1.print();
    cout << "obj2: ";
    obj2.print();
    cout << "obj3: ";
    obj3.print();

    obj3 = obj1++;
    cout << "obj3 after obj3 = obj1++: ";
    obj3.print();
    cout << "obj1 after obj1++: ";
    obj1.print();

    obj3 = ++obj1;
    cout << "obj3 after obj3 = ++obj1: ";
    obj3.print();
    cout << "obj1 after ++obj1: ";
    obj1.print();

    obj3 = ++obj2;
    cout << "obj3 after obj3 = ++obj2: ";
    obj3.print();
    cout << "obj2 after ++obj2: ";
    obj2.print();

    return 0;
}
