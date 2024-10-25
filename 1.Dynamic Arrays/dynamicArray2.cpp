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

    // Copy constructor
    DynamicArray(const DynamicArray &other) {
        size = other.size;
        capacity = other.capacity;
        arrayA = new int[capacity];
        for (int i = 0; i < size; i++) {
            arrayA[i] = other.arrayA[i];
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] arrayA;
    }

    // Overloaded Assignment Operator
    DynamicArray& operator=(const DynamicArray &other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        // Free the existing memory
        delete[] arrayA;

        // Copy the size and capacity from the other array
        size = other.size;
        capacity = other.capacity;

        // Allocate new memory and copy the elements
        arrayA = new int[capacity];
        for (int i = 0; i < size; i++) {
            arrayA[i] = other.arrayA[i];
        }

        return *this;
    }

    // Overloaded Subscript Operator
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds" << endl;
            exit(1); // Exit the program on invalid index access
        }
        return arrayA[index];
    }

    // Overloaded Stream Insertion Operator
    friend ostream& operator<<(ostream &out, const DynamicArray &arr) {
        out << "Array elements: ";
        for (int i = 0; i < arr.size; i++) {
            out << arr.arrayA[i] << " ";
        }
        out << endl;
        out << "Number of elements: " << arr.size << endl;
        out << "Array capacity: " << arr.capacity << endl;
        return out;
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

    // Using the overloaded [] operator to access elements
    cout << "Element at index 2: " << DA[2] << endl;

    // Using the overloaded << operator to print the array
    cout << DA;

    // Creating a new DynamicArray and using the assignment operator
    DynamicArray DA2;
    DA2 = DA; // Uses the overloaded = operator

    // Printing the new array
    cout << "Copied array:" << endl;
    cout << DA2;

    return 0;
}
