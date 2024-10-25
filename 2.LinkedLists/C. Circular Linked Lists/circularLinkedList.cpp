/* CIRCULAR LINKED LIST PROGRAM 
FUNCTIONS: 
-  Insertion functions (4) 
-  Remove functions (4) 
-  Return Head and Tail node (2, one of each) 
-  Return Head, Tail, Mid, certain Loc val (4, one of each) 
-  Utility function ((1)print func)
*/
#include <iostream> 
using namespace std; 

struct node{
  int data;
  node* next;

  node(int x){
    data = x;
    next = NULL;
  }
}; 

// class circular linked list
class circularLinkedList{
  private:
    node* head;
    int size; 


  public: 
    circularLinkedList(){
      // head pointer points to itself
      // head = new node(0);
      head = nullptr; // its a pointer after all! once there is a node in cll then you can point the head to that node and the newN to itself!
      size = 0;
    }

// distructor for circular linked list
// ~circularLinkedList(){
//   node* temp = head;
//   node* next;
//   while(temp != nullptr){
//     next = temp->next;
//     delete temp;
//     temp = next;
//   }
// }

node *insertAtHead(int x); 
node *insertAtTail(int x);
node *insertAtPosition(int x, int pos);
node *insertMiddle(int x);

void deleteHead(); 
void deleteTail();
void deletePosition(int pos);
void delteMiddle(); 

node *returHead();
node *returnTail();

int returnHeadVal();
int returnTailVal();
int returnPositionVal(int pos);
int returnMiddleVal();

void print();
};

node *circularLinkedList::insertAtHead(int x){ // Time complexity: O(1)
  node *newN = new node(x);
  if(head == nullptr){
    head = newN;
    newN->next = head;
    size++; 
    return head; 
  }
  newN->next = head;
  
  node *temp = head;
  while(temp->next != head){ // looking for the last node next pointer! tail points to head!
    temp = temp->next;
  }
  temp->next = newN;
  head = newN;
  size++;
  return head;
}

node *circularLinkedList::insertAtTail(int x){ // Time complexity: O(n)
  node *newN = new node(x);
  if(head == nullptr){
    head = newN;
    newN->next = head;
    size++;
    return head;  
  }
  node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = newN;
  newN->next = head;
  size++;
  return head;
}

node *circularLinkedList::insertAtPosition(int x, int pos){ // Time complexity: O(n)
  node *newN = new node(x);
  if(head == nullptr){
    head = newN;
    newN->next = head;
    size++;
    return head;
  }

  else if(pos == 0){
    return insertAtHead(x);
  }
  else if(pos >= size){
    return insertAtTail(x);
  } 

  node *temp = head;  
  for(int i = 0; i < pos - 1; i++){
    temp = temp->next;
  }
  newN->next = temp->next;
  temp->next = newN;
  size++;
  return head;
}

node *circularLinkedList::insertMiddle(int x){ // Time complexity: O(n)
  node *newN = new node(x);
  if(head == nullptr){
    head = newN;
    newN->next = head;
    size++;
    return head;
  }
  node *slow = head;
  node *fast = head->next;
  while(fast != head && fast->next != head){
    slow = slow->next;
    fast = fast->next->next;
  }
  newN->next = slow->next;
  slow->next = newN;
  size++;
  return head;
}

void circularLinkedList::deleteHead(){ // Time complexity: O(1)
  if(head == nullptr){
    return;
  }
  node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = head->next;
  head = head->next;
  size--;
  delete temp;
}

void circularLinkedList::deleteTail(){ // Time complexity: O(n)
  if(head == nullptr){
    return;
  }
  node *temp = head;
  while(temp->next->next != head){
    temp = temp->next;
  }
  temp->next = head;
  size--;
  delete temp;
}
void circularLinkedList::deletePosition(int pos){ // Time complexity: O(n)
  if(head == nullptr){
    return;
  }
    else if(pos == 0){
      deleteHead();
    }
    else if(pos >= size){
      deleteTail();
    }
      
    else{
      node *temp = head;
      for(int i = 0; i < pos - 1; i++){
        temp = temp->next;
      }
      node *temp2 = temp->next;
      temp->next = temp2->next;
      size--;
      delete temp2; }
}

void circularLinkedList::delteMiddle(){ // Time complexity: O(n)
  if(head == nullptr){ // using floyds method 
    return;
  }
  node *slow = head;
  node *fast = head;
  while(fast != head && fast->next != head){
    slow = slow->next;
    fast = fast->next->next;
  }
  node *temp = slow->next;
  slow->next = temp->next;
  size--;
  delete temp;
}

void circularLinkedList::print(){ // Time complexity: O(n)
  if(head == nullptr){
    return;
  }
  node *temp = head;
  while(temp->next != head){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << temp->data << endl;
}

node *circularLinkedList::returHead(){ // Time complexity: O(1)
  return head;
}
node *circularLinkedList::returnTail(){ // Time complexity: O(n)
  node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  return temp;
}
int circularLinkedList::returnHeadVal(){ // Time complexity: O(1)
  // cout << head->data << endl;
  return head->data;
}
int circularLinkedList::returnTailVal(){ // Time complexity: O(n)
  node *temp = head;
  while(temp->next != head){
    temp = temp->next;
  }
  return temp->data;
}
int circularLinkedList::returnPositionVal(int pos){ // Time complexity: O(n)
  node *temp = head;
  for(int i = 0; i < pos; i++){
    temp = temp->next;
  }
  return temp->data;
}

int circularLinkedList::returnMiddleVal(){ // Time complexity: O(n)
  node *slow = head;
  node *fast = head;
  while(fast != head && fast->next != head){ 
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}


int main(){

  circularLinkedList cll;
  cll.insertAtHead(1);
  cll.insertAtHead(2);
  cll.insertAtTail(3);
  cll.insertAtTail(4);
  cll.insertAtPosition(5, 2);
  cll.insertMiddle(7);
  cll.print();
  
  
}