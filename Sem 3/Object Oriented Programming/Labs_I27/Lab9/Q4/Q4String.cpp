#include "String.hpp"

bool String :: operator == (const String& other) const {
    if (length != other.length) 
        return false;

    for (int i = 0; i < length; i++) {
        if (str[i] != other.str[i])
            return false;
    }
    return true;
}

String& String :: operator += (const String& other) {
    int newLength = length + other.length;
    char* newStr = new char[newLength + 1];
    
    for (int i = 0; i < length; i++)
        newStr[i] = str[i];
    
    for (int i = 0; i < other.length; i++)
        newStr[length + i] = other.str[i];
    
    newStr[newLength] = '\0';
    
    delete[] str;
    str = newStr;
    length = newLength;
    
    return *this;
}

String& String :: operator / (const String &s) const {
    String rev;
    rev.length = s.length;
    rev.str = new char[rev.length + 1];
    
    for (int i = 0; i < length; i++)
        rev.str[i] = s.str[length - i - 1];

    rev.str[length] = '\0';
    
    return rev;
}

//Pre Increment
String& String :: operator++ () {
    for (int i = 0; i < length; i++)
        str[i]++;

    return *this;
}

//Post Increment
String String :: operator++ (int) {
    String temp(*this);
    ++(*this);
    return temp;
}
