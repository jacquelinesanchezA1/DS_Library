#include "sarray.h"
#include <iostream>
#include <string>
using namespace std;

// sarray constructor 
template <class T>  // <- when using templates always initialize this line for every function within your working class
sarray<T>::sarray(int s) { // <- sarray will be declared of 'T' type (T can be any data type!)
  size = s;               
  top = -1;
  elt = new T[size]; // this is a pointer to the stack in memory, it will be of 'T' data type
}

// sarray distructor
template <class T> 
sarray<T>::~sarray() { delete[] elt; } // <- this takes care of deallocating memory

// sarray push function 
template <class T> 
void sarray<T>::push(T v) {   // <- this will push element of T type into the stack 
  if (top == size - 1)       
    return;
  top++;
  elt[top] = v;
}

// sarray pop function 
template <class T> 
void sarray<T>::pop(T &retv) { // <- this will pop an element exclusively from the top of T type
  if (top == -1)
    return;
  retv = elt[top];
  top--;
}

// sarray return the top function 
template <class T> T sarray<T>::returnTop() { return elt[top]; } // <- will return the top element of the stack, of data type T