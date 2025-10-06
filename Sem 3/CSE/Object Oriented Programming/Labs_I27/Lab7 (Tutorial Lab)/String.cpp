#include "MyString.hpp"

int MyString :: strLen(const char* s) {
    int size = 0;

    while (s[size]!= '\0')
        size++;

    return size;
}

void MyString :: strCpy(char* dest, char* src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}

void MyString :: strCmp(const char *s1, const char *s2) {
    int i = 0;
    for (; (s1[i] != '\0') && (s2[i] != '\0'); i++) {
        if (s1[i]!= s2[i]) {
            cout << "Strings are not equal." << endl;
            return;
        }
    }

    if ((s1[i] == '\0') && (s2[i] == '\0'))
        cout << "Strings are equal." << endl;

    else
        cout << "Strings are not equal." << endl;
}

void MyString :: strCat(const char* s2) {
    int len1 = strLen(str);
    int len2 = strLen(s2);

    char *temp = new char[len1 + len2 + 1];
    
    strCpy(temp, str);
    
    for (int i = 0; i <= len2; i++)
        temp[len1 + i] = s2[i];

    delete[] str;
    str = temp;

    cout << "Concatenated string: " << str << endl;
}


void MyString :: strNCmp(const char *s1, const char *s2, int n) {
    for (int i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i]!= s2[i]) {
            cout << "Strings are not equal." << endl;
            return;
        }
    }

    cout << "Strings are equal." << endl;
}

void MyString :: strNCpy(char* src, char* dest, int n) {
    for (int i = 0; i < n && src[i] != '\0'; i++)   
        dest[i] = src[i];

    *dest = '\0';
}


void MyString :: strRev(){
    int len = strLen(str);

    char *temp = new char[len + 1];

    for(int i = 0; i < len; i++)
        temp[i] = str[len - i - 1];

    temp[len] = '\0';   

    delete[] str;
    str = new char[len + 1];
    strCpy(str, temp);

    cout << "Reversed string: " << str << endl;

    delete[] temp;
}


bool MyString :: checkPalindrome(const char *s) {
    int length = strLen(s);

    for (int i = 0; i < length / 2; i++)
        if (s[i]!= s[length - 1 - i])
            return false;

    return true;
}

void MyString :: print() {
    cout << str << endl;
}
