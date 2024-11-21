#include "SortPackage.hpp"

void SortPackage :: swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void SortPackage :: sort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl << endl;
}
