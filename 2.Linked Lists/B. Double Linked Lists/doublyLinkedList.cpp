/*  DOUBLY LINKED LIST PROGRAM
FUNCTIONS:
-  Insertion functions (4)
-  Remove functions (4)
-  Return Head and Tail node (2, one of each)
-  Return Head, Tail, Mid, certain Loc val (4, one of each)
-  Search Val, (1)
-  Utility function ((1)print func)

ALWAYS when reusing this code consider the edge cases for the following
functions:
- insert at certain location function (maybe they may allow tail insertion if
the location index is greater than the size of the list) for this program I only
allow node insertions within list size bound!)

*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;

    node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class doublyLinkedList
{
private:
    node *head;
    node *tail;
    int size;

public:
    doublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~doublyLinkedList(); // Destructor declaration
    
    // insertion functions(complete)
    node *insertAtHead(int x);
    node *insertAtTail(int x);
    node *insertAtPos(int x, int pos);
    node *insertMiddle(int);

    // deletion functions(complete)
    node *deleteAtHead();
    node *deleteAtTail();
    node *deleteAtPos(int pos);
    node *deleteMiddle();

    node *returnHead();
    node *returnTail();

    // return node val functions(complete)
    int returnHeadVal();
    int returnTailVal();
    int returnPosVal(int pos);
    int returnMidVal();

    // search value functions(complete)
    bool searchVal(int val);

    // utility functions(complete)
    void print();
    void reversePrint(); 

    // new
    int getSize(); 
    void clear(); 
};

node *doublyLinkedList::returnHead() { return head; }        // time complexity: O(1)
node *doublyLinkedList::returnTail() { return tail; }        // time complexity: O(1)
int doublyLinkedList::returnHeadVal() { return head->data; } // time complexity: O(1)
int doublyLinkedList::returnTailVal() { return tail->data; } // time complexity: O(1) (notice! I have a tail pointer, else if NO tail pointer O(n))
int doublyLinkedList::getSize(){ return size; }

int doublyLinkedList::returnPosVal(int pos)
{ // time complexity: O(n)
    node *temp = head;
    if (head == nullptr)
    {
        if (pos > 0)
        {
            return -1;
        }
    }

    // if there exist a list already!
    if (pos == 0)
    {
        return head->data;
    }

    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int doublyLinkedList::returnMidVal()
{ // time complexity: O(n)
    // node *temp = head;
    if (head == nullptr)
    {
        return -1;
    }
    return returnPosVal(size / 2);
}

bool doublyLinkedList::searchVal(int val)
{ // time complexity: O(n)
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            cout << "Found" << endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

node *doublyLinkedList::insertAtHead(int x)
{ // time complexity: O(1)
    node *newN = new node(x);
    if (head == nullptr)
    {
        head = newN;
        tail = newN;
        size++;
        return head;
    }
    newN->next = head;
    head->prev = newN;
    head = newN;
    size++;
    return head;
}

node *doublyLinkedList::insertAtTail(int x)
{ // time complexity: O(1)
    node *newN = new node(x);
    if (head == nullptr)
    {
        head = newN;
        tail = newN;
        size++;
        return head;
    }
    tail->next = newN;
    newN->prev = tail;
    tail = newN;
    size++;
    return head;
}

// node *doublyLinkedList::insertAtPos(int x, int pos)
// {
//     if (pos < 0 || pos > size)
//     { // Check for invalid indices
//         cout << "Invalid position!" << endl;
//         return head; // Do nothing
//     }

//     node *newN = new node(x);

//     // Insertion when the list is empty
//     if (head == nullptr)
//     {
//         head = newN;
//         tail = newN;
//         size++;
//         return head;
//     }

//     // Insert at the head
//     if (pos == 0)
//     {
//         newN->next = head;
//         head->prev = newN;
//         head = newN;
//         size++;
//         return head;
//     }

//     // Insert at the tail
//     if (pos == size)
//     {
//         return insertAtTail(x);
//     }

//     // Insert at a specific position
//     node *temp = head;
//     for (int i = 0; i < pos - 1; i++)
//     {
//         temp = temp->next;
//     }
//     newN->next = temp->next;
//     newN->prev = temp;
//     if (temp->next != nullptr)
//     {
//         temp->next->prev = newN;
//     }
//     temp->next = newN;
//     size++;

//     return head;
// }
// lets re-use the function we have created already
node* doublyLinkedList::insertAtPos(int x, int pos) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return head; // Do nothing for invalid positions
    }

    if (pos == 0) {
        return insertAtHead(x); // Reuse the insertAtHead function
    }
    
    if (pos == size) {
        return insertAtTail(x); // Reuse the insertAtTail function
    }
    
    node* newN = new node(x);

    // Determine whether to start from head or tail for better performance
    node* temp;
    if (pos <= size / 2) {
        // Traverse from head
        temp = head;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->next;
        }
    } else {
        // Traverse from tail
        temp = tail;
        for (int i = size - 1; i > pos; --i) {
            temp = temp->prev;
        }
    }

    // Insert new node
    newN->next = temp->next;
    newN->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newN;
    }
    temp->next = newN;

    size++;

    return head;
}


node *doublyLinkedList::insertMiddle(int x)
{ // time complexity: O(n)
    node *newN = new node(x);
    if (head == nullptr)
    {
        head = newN;
        tail = newN;
        size++;
        return head;
    }
    else
    {
        node *temp = head;
        int mid = size / 2;
        for (int i = 0; i < mid - 1; i++)
        {
            temp = temp->next;
        }
        // inner links first!
        newN->next = temp->next;
        newN->prev = temp;

        // outer links last!
        temp->next->prev = newN;
        temp->next = newN;

        size++;
        return head;
    }
}

node *doublyLinkedList::deleteAtHead()
{ // time complexity: O(1)
    if (head == nullptr)
    {
        return head;
    }
    else
    {
        node *temp = head; // 1. mark the node to delete

        head = head->next; // 2. update the head
        head->prev = nullptr;

        delete temp; // 3. delete the node (deallocate memory)
        size--;
        return head;
    }
}

node *doublyLinkedList::deleteAtTail()
{ // time complexity: O(1) // IF NO TAIL POINTER == O(N) since you would have to traverse the entire list to find the tail!
    if (head == nullptr)
    {
        return head;
    }
    else
    {
        node *temp = tail; // 1. mark the node to delete

        tail = tail->prev; // 2. update the tail
        tail->next = nullptr;

        delete temp; // 3. delete the node (deallocate memory)
        size--;
        return head;
    }
}

node *doublyLinkedList::deleteAtPos(int pos)
{
    if (pos < 0 || pos >= size)
    { // Check for invalid indices
        cout << "Invalid position!" << endl;
        return head; // Do nothing
    }

    if (head == nullptr)
    {
        return head;
    }

    // Handle deletion at head
    if (pos == 0)
    {
        return deleteAtHead();
    }

    // Handle deletion at tail
    if (pos == size - 1)
    {
        return deleteAtTail();
    }

    // Handle deletion at a specific position
    node *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    node *temp = p->next; // Node to delete
    p->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = p;
    }

    delete temp; // Deallocate memory
    size--;

    return head;
}

node *doublyLinkedList::deleteMiddle()
{ // time complexity: O(n)
    if (head == nullptr)
    {
        return head;
    }

    node *temp = head;
    int mid = size / 2;

    if (size % 2 == 0)
    {
        for (int i = 0; i < mid - 1; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        for (int i = 0; i < mid; i++)
        {
            temp = temp->next;
        }
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    delete temp;
    size--;

    return head;
}

void doublyLinkedList::print()
{ // time complexity: O(n)
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void doublyLinkedList::reversePrint(){
    if(head == nullptr){
        return; 
    }
    node *curr = tail; 
    while(curr != nullptr){
        cout<<curr->data<<" "; 
        curr = curr->prev; 
    }
    cout<<'\n'; 
}

void doublyLinkedList::clear(){
    while(head != nullptr){
        delete deleteAtHead(); 
    }
}

doublyLinkedList::~doublyLinkedList() {
    clear(); // Use clear to deallocate all nodes
}

int main() {
    doublyLinkedList list;

    // Testing insertions
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtPos(5, 2);
    list.insertAtPos(11, 4);
    list.insertMiddle(333);
    list.insertAtPos(4, 4);

    cout << "List before deletions: ";
    list.print();

    // Testing deletions
    list.deleteAtHead();
    list.deleteAtTail();
    cout << "List after head and tail removals: ";
    list.print();

    list.deleteAtPos(2);
    list.deleteMiddle();
    cout << "List after middle and position removals: ";
    list.print();

    // Testing additional functions
    cout << "List in reverse: ";
    list.reversePrint();

    cout << "List size: " << list.getSize() << endl;

    list.clear();
    cout << "List after clearing: ";
    list.print();

    return 0;
}
