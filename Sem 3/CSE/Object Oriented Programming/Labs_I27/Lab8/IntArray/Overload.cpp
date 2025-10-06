#include "IntArray.hpp"

istream& operator >> (istream& o, IntArray& a) {
    for(int i = 0; i < a.size; i++)
        o >> a.aptr[i];

    return o;
}

ostream& operator << (ostream& o, IntArray& a) {
    for(int i = 0; i < a.size; i++)
        o << a.aptr[i] << " ";

    return o;
}
