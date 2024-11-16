#include "IntArray.hpp"

IntArray :: IntArray (int sz) {
    size = sz;
    aptr = new int[size];
    
    for (int i = 0; i < size; i++)
        aptr[i] = 0;
}

IntArray :: IntArray() {
    size = 5;
    aptr = new int[size];

    for (int i = 0; i < size; i++)
        aptr[i] = 0;
}

IntArray :: IntArray(IntArray &source) {
    size = source.size;
    aptr = new int[size];

    for (int i = 0; i < size; i++)
        aptr[i] = source.aptr[i];
}

IntArray :: ~IntArray() {
    delete [] aptr;
}