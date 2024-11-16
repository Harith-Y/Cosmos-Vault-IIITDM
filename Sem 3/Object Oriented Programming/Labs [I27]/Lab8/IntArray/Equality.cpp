#include "IntArray.hpp"

bool IntArray :: operator == (const IntArray &right) const {
    if (size != right.size)
        return false;

    for (int i = 0; i < size; i++)
        if (aptr[i] != right.aptr[i])
            return true;
    
    return true;
}

bool IntArray :: operator != (const IntArray &right) const {
    return !(*this == right);
}