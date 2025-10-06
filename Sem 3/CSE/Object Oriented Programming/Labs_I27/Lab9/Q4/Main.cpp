#include "String.hpp"

int main() {
    // Create String objects using different constructors
    String s0();
    String s1("hello");
    String s2("world");
    String s3(s1);  // Copy constructor

    // Display the Strings
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3 (copy of s1): " << s3 << endl;

    // Test comparison
    if (s1 == s3)
        cout << "s1 is equal to s3." << endl;
    else
        cout << "s1 is not equal to s3." << endl;
    
    // Test concatenation
    String s4 = s1.concatenate(s2);
    cout << "Concatenation of s1 and s2: " << s4 << endl;

    // Test reverse
    String s5 = s4.reverse();
    cout << "Reverse of concatenated string: " << s5 << endl;

    // Test isPalindrome
    String s6("madam");
    cout << "s6: " << s6 << endl;
    if (s6.isPalindrome())
        cout << "s6 is a palindrome." << endl;
    else
        cout << "s6 is not a palindrome." << endl;
    
    // Test substring
    String s7 = s4.substring(0, 5);
    cout << "Substring of s4 (from 0 to 5): " << s7 << endl;

    // Test padding
    String s8 = s1.lpad(10);
    String s9 = s2.rpad(10);
    cout << "Left-padded s1: " << s8 << endl;
    cout << "Right-padded s2: " << s9 << endl;

    // Test operator overloading
    String s10 = s1;
    s10 += s2;  // Append s2 to s10
    cout << "s10 after appending s2: " << s10 << endl;

    String s11 = s10 / s10;  // Reversing the string
    cout << "Reverse of s10: " << s11 << endl;

    cout << "Pre-incrementing s1..." << endl;
    ++s1;
    cout << "s1 after pre-increment: " << s1 << endl;

    cout << "Post-incrementing s2..." << endl;
    s2++;
    cout << "s2 after post-increment: " << s2 << endl;

    // Input and output testing
    String s12;
    cout << "Enter a string: ";
    cin >> s12;
    cout << "You entered: " << s12 << endl;

    return 0;
}
