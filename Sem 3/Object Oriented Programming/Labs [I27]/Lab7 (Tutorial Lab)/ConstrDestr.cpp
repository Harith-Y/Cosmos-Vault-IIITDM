#include "MyString.hpp"

MyString :: MyString(const char *s) {
    if (s == nullptr) {
        cerr << "Error: Null pointer passed to MyString constructor." << endl;
        exit(EXIT_FAILURE);
    }

    str = new char[strLen(s) + 1];  
    strCpy(str, const_cast<char*>(s)); 
}

MyString :: ~MyString() {
    delete[] str; 
}

char* MyString :: getString() const {
    return str;
}
