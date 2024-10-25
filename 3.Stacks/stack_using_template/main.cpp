/* 
Date: 02/20/24
A stack implementation using Templates */

#include "stackT.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {

// stack of integers
  sarray<int> si; // sarray is an ADT 
  si.push(9);
  si.push(4);
  si.push(1);
  si.push(5);
  int a;
  si.pop(a);
  cout << si.returnTop() << endl;
  // si.~sarray(); // <- distructor

// stack of chars
  sarray<char> sc;
  sc.push('t');
  sc.push('a');
  sc.push('c');
  char b;
  sc.pop(b);
  cout << sc.returnTop() << endl;
  // si.~sarray();

// stack of floats
  sarray<float> sf;
  sf.push(19.3);
  sf.push(2.7);
  sf.push(11.1);
  float c;
  sf.pop(c);
  cout << sf.returnTop() << endl;

// stack of strings
  sarray<string> ss;
  ss.push("hello");
  ss.push("world");
  ss.push("blue");
  string d;
  ss.pop(d);

  cout << ss.returnTop() << endl;
}