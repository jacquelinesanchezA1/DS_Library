#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream> 
using namespace std; 

struct node{

    int value; 
    node *next; 

    node(int x){
        value = x; 
        next = nullptr; 
    }
}; 

class linkedList{

    private: 
        node *head;

    public: 
        linkedList(){
            head = nullptr;  
        }

        bool isEmpty(){
            return head == nullptr; 
            // if(head == nullptr){return true; }
        }

        int getSize(){
            node *curr = head; 
            int size = 0; 
            while(curr != nullptr){
                size++; 
                curr = curr->next; 
            }
            return size; 
        }

        void insertAtHead(int v){

            // first step 
            node *newNode = new node(v);

            newNode->next = head; 
            head = newNode; 
            return; 
        }

        void insertAtTail(int v){

            // first create a new node 
            node *newNode = new node(v); 

            if(isEmpty()){
                head = newNode; 
                return; 
            }

            node *curr = head; // NEVER use "head" to traverse a linked list
            while(curr->next != nullptr){
                curr = curr->next; 
            }
            curr->next = newNode; 
            return; 
        }


        void printList(){
            if(isEmpty()){
                return; 
            }

            node *curr = head; 
            while(curr != nullptr){
                cout<<curr->value<<" "; 
                curr = curr->next; 
            } 
            cout<<endl; 
        }

        node *returnHead(){
            return head; 
        }


        void print(node *head){
            if(head == nullptr){
                return; 
            }
            node *curr = head; 
            while(curr != nullptr){
                cout<<curr->value<<" "; 
                curr = curr->next; 
            }
            cout<<endl;
        }


};

#endif