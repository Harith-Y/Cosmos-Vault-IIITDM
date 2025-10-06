#include "IntArray.hpp"

const IntArray& IntArray :: operator = (const IntArray &right) {
    if (&right != this) {
        if (size != right.size) {
            delete [] aptr;
            size = right.size;
            aptr = new int[size];
        }

        for (int i = 0; i < size; i++)
            aptr[i] = right.aptr[i];
    }

    return *this;
}
