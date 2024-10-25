#include <iostream>
using namespace std;

class queueAsArray {

private:
    int *queue;
    int front, rear, size;

public:
    queueAsArray(int _size);
    ~queueAsArray(); 
    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void print();
};

// constructor
queueAsArray::queueAsArray(int _size) {
    size = _size;
    queue = new int[size];
    front = rear = -1; // initialize front and rear
}

// destructor
queueAsArray::~queueAsArray() {
    delete[] queue;
}

// check if the queue is empty
bool queueAsArray::isEmpty() {
    return front == -1;
}

// check if the queue is full
bool queueAsArray::isFull() {
    return (rear + 1) % size == front;
}

// enqueue function
void queueAsArray::enqueue(int x) {
    if (isFull()) {
        cout << "Full! Cannot enqueue anymore, reached full capacity!" << endl;
        return;
    }
    if (isEmpty()) {
        front = 0; // set the front to 0 if queue was empty
    }
    rear = (rear + 1) % size; // circularly increment
    queue[rear] = x; // add the new element
}

// dequeue function
void queueAsArray::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return;
    }
    if (front == rear) { // queue has only one element
        front = rear = -1; // reset to empty state
    } else {
        front = (front + 1) % size; // circular increment
    }
}


void queueAsArray::print() {
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
    queueAsArray q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.print();

    q.dequeue();
    q.enqueue(60);
    q.print();

    return 0;
}
