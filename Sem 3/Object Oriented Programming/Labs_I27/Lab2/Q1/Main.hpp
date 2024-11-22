#include <iostream>

using namespace std;

class Example {
    private:
        int data;

    public:
        void initalize(int val);
        void increment();
};

void Example :: initalize(int val) {
    if (val >= 0)
        data = val;
    else
        cout << "Invalid Value" << endl;
}
