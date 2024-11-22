#include "String.hpp"

ostream & operator << (ostream& o, const String& s) {
    if (s.str != nullptr)
        o << s.str;

    return o;
}

istream & operator >> (istream& in, String& s) {
    char temp[1000];
    in >> temp;
    s.length = s.calculateLength(temp);
    s.str = new char[s.length + 1];
    for (int i = 0; i < s.length; i++)
        s.str[i] = temp[i];

    s.str[s.length] = '\0';
    return in;
}
