#include <iostream>

using namespace std;

class MyString {
    private: char *str;

    public: MyString(const char *);
    public: ~MyString();
    public: char* getString() const;
    public: void strCpy(char*, char*);
    public: void strNCpy(char*, char*, int);
    public: void strCat (const char* str2);
    public: int strLen(const char* str);
    public: void strCmp(const char* str1, const char*);
    public: void strNCmp(const char*, const char*, int);
    public: void strRev();
    public: bool checkPalindrome(const char*);
    public: char* largestCommonSubsequence(const char*, const char*);

    public: void print();
};
