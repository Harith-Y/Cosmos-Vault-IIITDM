#include <iostream>
#include <cstdlib>

using namespace std;

class IntArray {
    private:
        int* aptr;
        int size;
        
        friend ostream& operator << (ostream&, IntArray&);
        friend istream& operator >> (istream&, IntArray&);

    public:
        IntArray();
        IntArray(int );
        IntArray(IntArray&) ;
        ~IntArray();

        const IntArray& operator = (const IntArray& );
        bool operator == (const IntArray &) const;
        bool operator != (const IntArray &) const;

        int& operator [] (int);
        const int& operator [] (int) const;
};
