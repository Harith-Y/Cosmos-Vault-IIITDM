#include "IntArray.hpp"

int main() {
    // Create an IntArray with a specified size
    IntArray array1(5);

    // Display the default values
    cout << "Default values of array1: " << array1 << endl;

    // Assign values to the array using the subscript operator
    for (int i = 0; i < 5; i++)
        array1[i] = (i + 1) * 10;

    // Display the modified array
    cout << "Modified array1: " << array1 << endl;

    // Use the copy constructor
    IntArray array2(array1);
    cout << "Copied array2 (using copy constructor): " << array2 << endl;

    // Compare the arrays using the equality operator
    if (array1 == array2)
        cout << "array1 is equal to array2." << endl;
    else
        cout << "array1 is not equal to array2." << endl;

    // Create another array and use the assignment operator
    IntArray array3(3);
    cout << "Initial values of array3: " << array3 << endl;
    array3 = array1;
    cout << "array3 after assignment from array1: " << array3 << endl;

    // Test inequality operator
    if (array1 != array3)
        cout << "array1 is not equal to array3." << endl;
    else
        cout << "array1 is equal to array3." << endl;

    // Take input from the user
    cout << "Enter 5 integers for array1: ";
    cin >> array1;
    cout << "Updated array1: " << array1 << endl;

    return 0;
}
