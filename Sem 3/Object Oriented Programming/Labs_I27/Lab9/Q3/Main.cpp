#include "String.hpp"

int main() {
    String s1("hello");
    String s2("world");

    // Copy
    String s3;
    s3.copy(s1);
    cout << "Copied string: " << s3 << endl;

    // Reverse
    cout << "Reversed string: " << s1.reverse() << endl;

    // Comparison
    if (s1.compare(s2) == 0)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;

    // Substring
    String sub = s1.substring(1, 3);
    cout << "Substring: " << sub << endl;

    // Palindrome check
    String s4("malayalam");
    if (s4.isPalindrome())
        cout << s4 << " is a palindrome." << endl;
    else
        cout << s4 << " is not a palindrome." << endl;
    
    String s5("notmalayalam");
    if (s5.isPalindrome())
        cout << s5 << " is a palindrome." << endl;
    else
        cout << s5 << " is not a palindrome." << endl;

    // Concatenation
    String concat = s1.concatenate(s2);
    cout << "Concatenated string: " << concat << endl;

    // Left-pad
    String lpad_str = s1.lpad(10);
    cout << "Left-padded string: " << lpad_str << endl;

    // Right-pad
    String rpad_str = s1.rpad(10);
    cout << "Right-padded string: " << rpad_str << endl;

    return 0;
}
