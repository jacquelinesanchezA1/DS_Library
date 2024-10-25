#include <iostream>
using namespace std;

template <typename T>
class queueAsArray {
private:
    T *queue;
    int front, rear, size;

public:
    queueAsArray(int _size);
    ~queueAsArray(); // destructor to free memory
    void enqueue(T x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

// constructor
template <typename T>
queueAsArray<T>::queueAsArray(int _size) {
    size = _size;
    queue = new T[size];
    front = rear = -1; // initialize front and rear
}

// destructor
template <typename T>
queueAsArray<T>::~queueAsArray() {
    delete[] queue;
}

// check if the queue is empty
template <typename T>
bool queueAsArray<T>::isEmpty() {
    return front == -1;
}

// check if the queue is full
template <typename T>
bool queueAsArray<T>::isFull() {
    return (rear + 1) % size == front;
}

// enqueue function
template <typename T>
void queueAsArray<T>::enqueue(T x) {
    if (isFull()) {
        cout << "full! cannot enqueue anymore, reached full capacity!" << endl;
        return;
    }
    if (isEmpty()) {
        front = 0; // set the front to 0 if queue was empty
    }
    rear = (rear + 1) % size; // circular increment
    queue[rear] = x; // add the new element
}

// dequeue function
template <typename T>
void queueAsArray<T>::dequeue() {
    if (isEmpty()) {
        cout << "queue is empty! cannot dequeue." << endl;
        return;
    }
    if (front == rear) { // queue has only one element
        front = rear = -1; // reset to empty state
    } else {
        front = (front + 1) % size; // circular increment
    }
}

// display the queue elements
template <typename T>
void queueAsArray<T>::display() {
    if (isEmpty()) {
        cout << "queue is empty." << endl;
        return;
    }
    cout << "queue elements: ";
    for (int i = front; i != rear; i = (i + 1) % size) {
        cout << queue[i] << " ";
    }
    cout << queue[rear] << endl; // print the rear element
}

int main() {
    queueAsArray<int> intQueue(5); // create a queue of integers
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);
    intQueue.enqueue(50);
    
    intQueue.display();

    intQueue.dequeue();
    intQueue.enqueue(60);
    intQueue.display();

    queueAsArray<string> stringQueue(3); // create a queue of strings
    stringQueue.enqueue("cherry");
    stringQueue.enqueue("tomatos");
    
    stringQueue.display();
    stringQueue.dequeue();
    stringQueue.enqueue("plums");
    stringQueue.display();

    return 0;
}
