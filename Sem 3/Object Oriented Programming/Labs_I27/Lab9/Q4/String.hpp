#include <iostream>

using namespace std;

class String {
    private:
        char* str;
        int length;

        int calculateLength(const char*);

    public:
        String() : str(nullptr), length(0) {}
        String(const char*);
        String(const String&);
        ~String();

        void copy(const String&);

        String reverse() const;

        int compare(const String&) const;

        String substring(int, int) const;

        bool isPalindrome() const;

        String concatenate(const String&) const;

        String lpad(int) const;
        String rpad(int) const;

        friend ostream& operator << (ostream&, const String&);
        friend istream& operator >> (istream&, String&);


        bool operator == (const String&) const;
        String& operator += (const String&); 
        String& operator / (const String&) const;
        String& operator ++ ();  
        String operator ++ (int);
};
