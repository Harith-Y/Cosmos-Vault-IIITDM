#include "string.hpp"

String :: String() : str(nullptr), length(0) {}

String :: String(const char* s) {
    length = calculateLength(s);
    str = new char[length + 1];
    for (int i = 0; i < length; i++)
        str[i] = s[i];

    str[length] = '\0';
}

String :: String(const String& other) {
    length = other.length;
    str = new char[length + 1];
    for (int i = 0; i < length; i++)
        str[i] = other.str[i];

    str[length] = '\0';
}

String :: ~String() {
    delete[] str;
}
