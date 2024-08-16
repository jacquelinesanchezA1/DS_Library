/*  SINGLY LINKED LIST PROGRAM
FUNCTIONS:
-  Insertion functions (4)
-  Remove functions (4)
-  Return Head
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

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class linkedList
{

private:
    node *head;
    int size;

public:
    linkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~linkedList() {
    while (head != nullptr) {
        removeAtHead();
    }
}

    // insertion functions(4)
    node *insertAtHead(int x);
    node *insertAtTail(int x);
    node *insertAtPos(int x, int pos);
    node *insertMiddle(int x);

    // remove functions(4)
    node *removeAtHead();
    node *removeAtTail();
    node *removeAtPos(int pos);
    node *removeMiddle(int x);

    // return head function
    node *returnHead();

    // utility function
    void print();
};

node *linkedList::insertAtHead(int x)
{ // time complexity: O(1)
    node *newN = new node(x);
    if (head == nullptr)
    {
        head = newN;
        size++;
        return head;
    }
    newN->next = head;
    head = newN;
    size++;
    return head;
}

node *linkedList::insertAtTail(int x)
{ // time complexity: O(n)
    node *newN = new node(x);
    if (head == nullptr)
    {
        head = newN;
        size++;
        return head;
    }
    node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newN;
    size++;
    return head;
}

node *linkedList::insertAtPos(int x, int pos)
{ // time complexity: O(n)
    node *newN = new node(x);

    if (head == nullptr)
    {
        if (pos != 0)
        {
            return head;
        }
        else if (pos == 0)
        {
            head = newN;
            size++;
            return head;
        }
        else
        {
            return head; // this is for index that are out of bounds
        }
    } // eof if head is null

    if (pos == 0)
    {
        newN->next = head;
        head = newN;
        size++;
        return head;
    }
    else if (pos == size - 1)
    {
        node *curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newN;
        size++;
        return head;
    }

    else if (pos < size - 1 && pos > 0)
    {
        node *curr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        newN->next = curr->next;
        curr->next = newN;
        size++;
        return head;
    }

    else // this is for index that are out of bounds (pos>size-1 || pos<0)
        return head;
}

node *linkedList::insertMiddle(int x)
{ // time complexity: O(n)

    node *newN = new node(x);

    // when list is empty! edge cases may differ but in my program I make an exception and make the node the head
    if (head == nullptr)
    {
        head = newN;
        size++;
        return head;
    }
    // when the list NOT empty!

    node *slow = head;
    node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    newN->next = slow->next;
    slow->next = newN;
    size++;
    return head;
}

node *linkedList::removeAtHead()
{ // time complexity: O(1)
    if (head == nullptr)
    {
        return head;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
    return head;
}

node *linkedList::removeAtTail()
{// time complexity: O(n)
    // case 1: empty list
    if (head == nullptr)
        return head;
    // case 2: one node list
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        size--;
        return head;
    }
    // case 3: multiple node list
    node *curr = head;
    node *p = nullptr;
    while (curr->next != nullptr)
    {
        p = curr;
        curr = curr->next;
    }
    p->next = nullptr;
    delete curr;
    size--;
    return head;
}

node *linkedList::removeAtPos(int pos)
{ // time complexity: O(n)
    if (head == nullptr)
    {
        return head;
    }
    // case 1: deleting the head
    if (pos == 0)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return head;
    }
    // case 2: deleting the tail
    else if (pos == size - 1)
    {
        node *curr = head;
        node *p = nullptr;
        while (curr != nullptr)
        {
            p = curr;
            curr = curr->next;
        }
        p->next = nullptr;
        delete curr;
        size--;
        return head;
    }
    // case 3: deleting the *somewhere* in the middle
    else if (pos < size - 1 && pos > 0)
    {
        node *curr = head;
        node *p = nullptr;
        for (int i = 0; i < pos; i++)
        {
            p = curr;
            curr = curr->next;
        }
        p->next = curr->next;
        delete curr;
        size--;
        return head;
    }
    // case 4: for invalid entries (negation of the prev `else if` condition)
    else
        return head;
}

node *linkedList::removeMiddle(int x)
{ // time complexity: O(n)
    if (head == nullptr)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    node *p = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    p->next = slow->next;
    delete slow;
    size--;
    return head;
}

void linkedList::print()
{ // time complexity: O(n)
    if (head == nullptr)
    {
        cout << "There is no linked list";
        return;
    }
    node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

node *linkedList::returnHead()
{ // time complexity: O(1)
    return head;
}
int main()
{

    linkedList list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);

    list.insertAtTail(4);
    list.insertAtTail(7);

    // list.insertAtPos(10, 2);
    list.insertAtPos(11, 4);
    list.insertMiddle(777);

    list.print();
}