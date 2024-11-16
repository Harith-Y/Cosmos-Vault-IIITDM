#include <iostream>

using namespace std;

template <class TestDataType>
void swap(TestDataType *a, TestDataType *b) {
    TestDataType temp = *a;
    *a = *b;
    *b = temp;
}

template <class TestDataType>
void sort(TestDataType arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl << endl;
}

int main() {
	int choice = 0;
	while ((cout << "1. Integer Array" << endl
			 	 << "2. Float Array" << endl
				 << "3. Character Array" << endl
				 << "4. Exit" << endl
				 << "Enter a valid input: ") && (cin >> choice) && (choice != 4)) {
	
		if (choice == 1) {
			int size;
			cout << "Enter Size of array: ";
			cin >> size;
			
			int* intarr = new int[size];
            cout << "Enter " << size << " integers: ";
            for (int i = 0; i < size; i++)
                cin >> intarr[i];
            
            sort(intarr, size);
            delete[] intarr;
		}
		
		else if (choice == 2) {
			int size;
			cout << "Enter Size of array: ";
			cin >> size;
			
			float* floatarr = new float[size];
            cout << "Enter " << size << " floats: ";
            for (int i = 0; i < size; i++)
                cin >> floatarr[i];
            
            sort(floatarr, size);
            delete[] floatarr;
		}
		
		else if (choice == 3) {
			int size;
			cout << "Enter Size of array: ";
			cin >> size;
			
			char* chararr = new char[size];
            cout << "Enter " << size << " characters: ";
            for (int i = 0; i < size; i++)
                cin >> chararr[i];
            
            sort(chararr, size);
            delete[] chararr;
		}
		
		else
			cout << "Please enter a valid input!" << endl << endl;
	}
	
	cout << "Exiting..." << endl;
    return 0;
}
