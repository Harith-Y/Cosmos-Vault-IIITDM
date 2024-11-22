#include <iostream>

using namespace std;

class Example {
    private:
        int x;
        int y;
        int z;
        void increment();
        
    public:
        Example(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
        ~Example() {}

        void print();

        Example operator ++ (int);
        Example & operator ++ (); 
        Example & operator = (const Example&);     
};
