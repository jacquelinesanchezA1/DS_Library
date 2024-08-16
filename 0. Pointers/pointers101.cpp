#include <iostream>
using namespace std; 

/* What are pointers? 
pointers are used to 'point'/store memory locations(address) of variables

Why use pointers? (SPEEED) 
Throughout these career we are obsessed with SPEED we want programs to run efficiently and FAST

'Its faster to find a location when you are given an address location!'

variables are assigned ram when we call them say 'print var' compiler looks all over RAM to find that specific var,
which takes A LOT of time! (THIS IS SOO SLOOW)

How to access a variables address? 
Glad you ask, 
1. use & operator(direference): This will retrieve your variables address, 
    int &yourVariable; 

2. use * operator(pointer): This will point at the address of your variable,
    int *ptr; 

3. pointer(*ptr) points to yourVariable's address(&yourVariable)
    ptr = &yourVariable


Hope you learn more, happy learning jacqi! 

*/

int main(){

int a = 10; // this is the initial val, int a = 10; 
int *ptra; // this is a pointer that will be pointing to an 'int' address soon
ptra = &a; // pointer is now pointing to 'a's address(&a)

cout<<"These variables print out the original value stored in 'int a = 10' : "<<endl; 
cout<<"int a = "<<a<<" && "<<"*ptra = "<<*ptra<<endl; 

cout<<"\n"; 

cout<<"These variables print out the original value stored in &a = 'a's address"<<endl; 
cout<<"ptra = "<<ptra<<" && "<<"&ptra = "<<&ptra<<endl; 

cout<<"\n"; 

cout<<"This is what is stored in int a = '"<<a<<"'"<<endl;       // this prints out the value stored in int a **
cout<<"This is what is stored in *ptra = '"<<*ptra<<"'"<<endl;   // this prints the address of the variable int a 
cout<<"This is what is stored in ptra = '"<< ptra <<"'"<<endl; // this prints out the value stored in int a **
cout<<"This is what is stored in &a = '"<<&a<<"'"<<endl;        // this print the address of the variable int a


}