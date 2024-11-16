#include <iostream>

using namespace std;

class Example {
    private:
        int x;
        int y;
        int z;
        void increment();
        
    public:
        Example(int =0, int =0, int =0);
        ~Example() {};

        void print();

        Example operator ++ (int);
        Example& operator ++ (); 
        Example& operator = (const Example&);     
};
