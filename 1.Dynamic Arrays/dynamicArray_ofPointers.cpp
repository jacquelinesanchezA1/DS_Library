#include <iostream>
using namespace std;

class DynamicArrayOfPointers {
private:
    int **arrayA;   // Pointer to an array of pointers to int
    int capacity;   // Capacity of the array
    int size;       // Current number of elements in the array

public:
    // Constructor
    DynamicArrayOfPointers() {
        capacity = 1;
        arrayA = new int*[capacity];
        size = 0;
    }

    // Destructor
    ~DynamicArrayOfPointers() {
        for (int i = 0; i < size; i++) {
            delete arrayA[i];  // O(1) - Free each allocated int
        }
        delete[] arrayA;  // O(1) - Free the array of pointers
    }

    // Function to add an element (pointer) to the array
    void AddElement(int value) {
        if (size == capacity) {
            growSize();  // O(n) - Time complexity for growing the array
        }
        arrayA[size] = new int(value);  // O(1) - Allocate memory and assign value
        size++;  // O(1)
    }

    // Function to grow the size of the array when needed
    void growSize() {
        int newCapacity = capacity * 2;
        int **temp = new int*[newCapacity];

        // O(n) - Copying elements to the new array
        for (int i = 0; i < size; i++) {
            temp[i] = arrayA[i];
        }

        delete[] arrayA;  // O(1) - Free the old array of pointers
        arrayA = temp;  // O(1) - Assign the new array
        capacity = newCapacity;  // O(1)
    }

    // Function to access elements (pointers) using the subscript operator
    int* operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds" << endl;
            exit(1);  // O(1) - Exit the program on invalid index access
        }
        return arrayA[index];  // O(1) - Accessing the pointer at index
    }

    // Function to print all elements (dereferenced)
    void printElements() {
        // O(n) - Iterating over the array to print elements
        for (int i = 0; i < size; i++) {
            cout << "Element at index " << i << ": " << *arrayA[i] << endl;
        }
    }

    // Function to get the size of the array
    int getSize() { 
        return size;  // O(1)
    }

    // Function to get the capacity of the array
    int getCapacity() { 
        return capacity;  // O(1)
    }
};

int main() {
    // Create a dynamic array of pointers
    DynamicArrayOfPointers DA;

    // Add elements to the dynamic array
    DA.AddElement(10);  // O(1)
    DA.AddElement(20);  // O(1)
    DA.AddElement(30);  // O(1)
    DA.AddElement(40);  // O(1)

    // Print the elements using the print function
    DA.printElements();  // O(n)

    // Accessing and modifying elements through the subscript operator
    *DA[1] = 25;  // O(1) - Modify the value at index 1

    // Print the elements again to see the change
    cout << "After modifying the value at index 1:" << endl;
    DA.printElements();  // O(n)

    return 0;
}
