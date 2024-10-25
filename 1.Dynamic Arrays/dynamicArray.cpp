#include <iostream>
using namespace std;

class DynamicArray {

private:
    int *arrayA;   // Pointer to the array
    int capacity;  // Capacity of the array
    int size;      // Current number of elements in the array

public:
    // Constructor
    DynamicArray() {
        capacity = 1;
        arrayA = new int[capacity];
        size = 0;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arrayA;
    }

    // Insertion functions
    void AddElement(int);
    void AddElementAt(int, int); // (index, value)

    // Deletion functions
    void removeElement();
    void removeElementAt(int);   // (index)

    // Grow/Shrink array functions
    void growSize();
    void shrinkSize();

    // Utility functions
    bool isEmpty();
    int getSize();      // Returns the current number of elements
    int getCapacity();  // Returns the capacity of the array
    int search(int);    // Searches for a value and returns its index
    void printArray();
};

void DynamicArray::AddElement(int x) {
    if (size == capacity) {
        growSize();
    }
    arrayA[size] = x;
    size++;
}

void DynamicArray::AddElementAt(int index, int val) {
    if (index < 0 || index > size) {
        cout << "Error: Index out of bounds" << endl;
        return;
    }
    if (size == capacity) {
        growSize();
    }
    for (int i = size - 1; i >= index; i--) {
        arrayA[i + 1] = arrayA[i];
    }
    arrayA[index] = val;
    size++;
}

void DynamicArray::removeElement() {
    if (size == 0) {
        cout << "Error: Array is empty" << endl;
        return;
    }
    arrayA[size - 1] = 0; // Optional: Clear the last element
    size--;

    if (size <= capacity / 2) {
        shrinkSize();
    }
}

void DynamicArray::removeElementAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Error: Index out of bounds" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arrayA[i] = arrayA[i + 1];
    }
    arrayA[size - 1] = 0; // Optional: Clear the last element
    size--;

    if (size <= capacity / 2) {
        shrinkSize();
    }
}

void DynamicArray::growSize() {
    int newCapacity = capacity * 2;
    int *temp = new int[newCapacity];

    for (int i = 0; i < size; i++) {
        temp[i] = arrayA[i];
    }

    delete[] arrayA;
    arrayA = temp;
    capacity = newCapacity;
}

void DynamicArray::shrinkSize() {
    if (size <= capacity / 2) {
        int newCapacity = capacity / 2;
        int *temp = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            temp[i] = arrayA[i];
        }

        delete[] arrayA;
        arrayA = temp;
        capacity = newCapacity;
    }
}

int DynamicArray::search(int key) {
    for (int i = 0; i < size; i++) {
        if (arrayA[i] == key) {
            cout << key << " is located at index: " << i << endl;
            return i;
        }
    }
    cout << key << " not found in the array" << endl;
    return -1; // Return -1 if the key is not found
}

int DynamicArray::getSize() {
    return size;
}

int DynamicArray::getCapacity() {
    return capacity;
}

void DynamicArray::printArray() {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arrayA[i] << " ";
    }
    cout << endl;
    cout << "Number of elements: " << size << endl;
    cout << "Array capacity: " << capacity << endl;
}

bool DynamicArray::isEmpty() {
    return size == 0;
}

int main() {

    DynamicArray DA;

    // Adding elements to the dynamic array
    DA.AddElement(23);
    DA.AddElement(34);
    DA.AddElement(45);
    DA.AddElement(12);
    DA.AddElement(32);
    DA.AddElement(34);

    // Inserting an element at a specific index
    DA.AddElementAt(2, 99);

    // Removing the last element from the array
    DA.removeElement();

    // Searching for an element in the array
    DA.search(45);

    // Printing the array elements
    DA.printArray();

    // Test boundary cases
    DA.removeElementAt(10); // Invalid index
    DA.AddElementAt(10, 77); // Invalid index

    return 0;
}
