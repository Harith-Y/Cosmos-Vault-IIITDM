#include "IntArray.hpp"

const int & IntArray :: operator [] (int sscript) const {
    if ((sscript >= 0) && (sscript < size))
        return aptr[sscript];
    else
        abort();
}

int & IntArray :: operator [] (int sscript) {
    if ((sscript >= 0) && (sscript < size))
        return aptr[sscript];
    else
        abort();
}
