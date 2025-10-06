#include <stdio.h>

int recurse(int i) {
    int extra[10];  // Allocate 10 integers (10 * 4 bytes = 40 bytes)

    if(i == 0)
        return 0;
    else
        recurse(i - 1);
}

int main() {
    int i = 8;
    recurse(i);
}
