#include <iostream>
#include "Main.hpp"

using namespace std;

ExampleClass :: ExampleClass(int val) {
    data = val;
    cout << "Constructor called for object " << data << endl;
}

ExampleClass :: ~ExampleClass() {
    cout << "Destructor called for object " << data << endl;
}
