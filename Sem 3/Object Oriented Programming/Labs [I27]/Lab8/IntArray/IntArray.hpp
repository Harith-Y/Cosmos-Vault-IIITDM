#include <iostream>
#include <cstdlib>
using namespace std;

class IntArray
{
    private: int* aptr;
    private: int size;
        
    private: friend ostream & operator << (ostream &o, IntArray &a);
    private: friend istream & operator >> (istream &o, IntArray &a);

    
    public: IntArray();
    public: IntArray(int);
    public: IntArray(IntArray &);
    public: ~IntArray();

    public: const IntArray & operator = (const IntArray &);
    public: bool operator == (const IntArray &) const;
    public: bool operator != (const IntArray &) const;

    public: int & operator [] (int);
    public: const int & operator [] (int) const;

};