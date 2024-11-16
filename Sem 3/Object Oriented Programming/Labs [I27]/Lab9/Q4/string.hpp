#include <iostream>

using namespace std;

class String {
    private: char* str;
    private: int length;

    private: int calculateLength(const char*);


    public: String();
    public: String(const char*);
    public: String(const String&);
    public: ~String();

    public: void copy(const String&);

    public: String reverse() const;

    public: int compare(const String&) const;

    public: String substring(int, int) const;

    public: bool isPalindrome() const;

    public: String concatenate(const String&) const;

    public: String lpad(int) const;
    public: String rpad(int) const;

    public: friend ostream& operator << (ostream&, const String&);
    public: friend istream& operator >> (istream&, String&);


    public: bool operator==(const String&) const;
    public: String& operator+=(const String&); 
    public: String operator/(int) const;
    public: String& operator++();  
    public: String operator++(int);
};
