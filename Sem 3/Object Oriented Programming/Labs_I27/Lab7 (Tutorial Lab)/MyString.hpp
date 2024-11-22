#include <iostream>

using namespace std;

class MyString {
    private: char *str;

    public:
        MyString(const char *);
        ~MyString();
        char* getString() const;
        void strCpy(char*, char*);
        void strNCpy(char*, char*, int);
        void strCat (const char* );
        int strLen(const char* );
        void strCmp(const char* , const char*);
        void strNCmp(const char*, const char*, int);
        void strRev();
        bool checkPalindrome(const char*);
        char* largestCommonSubsequence(const char*, const char*);

        void print();
};
