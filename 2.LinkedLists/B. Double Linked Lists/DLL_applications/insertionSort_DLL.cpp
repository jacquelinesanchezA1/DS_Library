#include <iostream>
#include <sstream>
using namespace std;

struct node {
  int data;
  node *next;
  node *prev;

  node(int x) {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};

class doublyLinkedList {

private:
  node *head;
  node *tail;
  int size;

public:
  doublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  node *insertionSort(node *head);

  void createList(int);

  void printList(node *head);
  bool isEmpty();

  node *returnHead();
  node *returnTail();
};

bool doublyLinkedList::isEmpty() {
  if (head == nullptr) {
    return true;
  }
  return false;
}

node *doublyLinkedList::returnHead() { return head; }

node *doublyLinkedList::returnTail() { return tail; }

void doublyLinkedList::createList(int x) {

  node *newN = new node(x);

  if (isEmpty()) {
    head = newN;
    size++;
    return;
  }

  node *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = newN;
  newN->prev = tail;
  tail = newN;
  size++;
  return;
}

node *doublyLinkedList::insertionSort(node *head) {
  if (head == nullptr) {
    return head;
  }

  node *sortedList = nullptr; // pointer to the sorted portion
  node *unsortedList = head;  // pointer to the unsorted portion

  while (unsortedList != nullptr) {
    // store the next node to be processed in the unsorted list
    node *nextUnsorted = unsortedList->next;

    // traverse the sorted list to find the correct position to insert the
    // current node
    node *currentSorted = sortedList;
    node *prevSorted = nullptr;

    while (currentSorted != nullptr &&
           currentSorted->data < unsortedList->data) {
      prevSorted = currentSorted;
      currentSorted = currentSorted->next;
    }

    // update pointers to include the unsorted node into the sorted portion
    if (prevSorted == nullptr) {
      // insert at the beginning of the sorted list
      unsortedList->next = sortedList;
      sortedList = unsortedList;
    } else {
      // insert in the middle or at the end of the sorted list
      prevSorted->next = unsortedList;
      unsortedList->next = currentSorted;
    }

    // move to the next node in the unsorted list
    unsortedList = nextUnsorted;

    // print the entire linked list with both sorted and unsorted portions
    node *temp = sortedList;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    if (unsortedList != nullptr) {
      temp = unsortedList;
      while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
      }
    }
    cout << endl;
  }

  return sortedList;
}

void doublyLinkedList::printList(node *head) {
  if (isEmpty()) {
    return;
  }

  cout << "[";
  while (head != nullptr) {
    cout << head->data;
    if (head->next != nullptr) {
      cout << ",";
    }
    head = head->next;
  }
  cout << "]" << endl;
  return;
}

int main() {
  doublyLinkedList list;

  // Create a sample list
  list.createList(5);
  list.createList(2);
  list.createList(7);
  list.createList(3);
  list.createList(9);
  list.createList(1);
  list.createList(4);

  cout << "Original List: ";
  list.printList(list.returnHead());

  cout << "\nInsertion Sort Steps:\n";
  node *sortedList = list.insertionSort(list.returnHead());

  cout << "\nSorted List: ";
  list.printList(sortedList);

  return 0;
}