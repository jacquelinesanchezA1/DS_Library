#include <iostream> 
#include "sll.h"
using namespace std; 

/* You should try it with templates! Make it more interesting! 
*/

node *reverseList(node *head){

    if(head == nullptr){
        return head; 
    }

    node *n = nullptr; // n - next
    node *p = nullptr; // p - prev
    node *curr = head; // current

    while(curr != nullptr){
        n = curr->next;  // n is curr->next node 
        curr->next = p; // curr->next points to the new "p" pointer
        p = curr;      // p, curr is assigned to curr
        curr = n;     // update the new curr, which curr is now n(the node after "old" curr!)
    }

    return p;  // updated head / new head
}

int main(){

    linkedList list; 
    list.insertAtHead(5); 
    list.insertAtHead(4); 
    list.insertAtHead(3); 
    list.insertAtHead(2); 
    list.insertAtHead(1);

    node *listHead = list.returnHead();// list's head
    list.print(reverseList(listHead)); 

    list.printList(); 

}