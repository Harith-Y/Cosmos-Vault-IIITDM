#include "MyString.hpp"

void displayMenu() {
    cout << "\nMenu Options:" << endl;
    cout << "1. Concatenate two strings" << endl;
    cout << "2. Reverse a string" << endl;
    cout << "3. Compare two strings" << endl;
    cout << "4. Check if a string is a palindrome" << endl;
    cout << "5. Find the largest common subsequence of two strings" << endl;
    cout << "6. Print a string" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool exit = false;
    char str1[100], str2[100];  // Temp variables for user input
    MyString* string1 = nullptr;
    MyString* string2 = nullptr;

    while (!exit) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // Concatenate two strings
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                
                string1 = new MyString(str1);
                string2 = new MyString(str2);
                string1 -> strCat(string2 -> getString());

                // string1->print();
                delete string1;
                delete string2;
                break;

            case 2:  // Reverse a string
                cout << "Enter a string to reverse: ";
                cin >> str1;

                string1 = new MyString(str1);
                string1 -> strRev();

                // string1->print();
                
                delete string1;
                break;

            case 3:  // Compare two strings
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;

                string1 = new MyString(str1);
                string2 = new MyString(str2);
                string1 -> strCmp(string1 -> getString(), string2 -> getString());

                delete string1;
                delete string2;
                break;

            case 4:  // Check if a string is a palindrome
                cout << "Enter a string to check for palindrome: ";
                cin >> str1;

                string1 = new MyString(str1);
                if (string1 -> checkPalindrome(string1 -> getString()))
                    cout << "The string is a palindrome." << endl;
                else
                    cout << "The string is not a palindrome." << endl;
    
                delete string1;
                break;

            case 5:  // Find largest common subsequence
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;

                string1 = new MyString(str1);
                string2 = new MyString(str2);

                {
                    const char* lcs = string1 -> largestCommonSubsequence(string1 -> getString(), string2 -> getString());
                    cout << "Largest Common Subsequence: " << lcs << endl;
                }
                
                delete string1;
                delete string2;
                break;

            case 6:  // Print a string
                cout << "Enter a string: ";
                cin >> str1;

                string1 = new MyString(str1);
                string1 -> print();

                delete string1;
                break;

            case 0:  // Exit
                cout << "Exiting..." << endl;
                exit = true;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
