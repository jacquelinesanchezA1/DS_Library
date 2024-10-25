#include <iostream>
#include <string>
using namespace std;

template <class T> class sarray {
private:
  int size;
  int top;
  T *elt;

public:
  sarray(int = 10);
  ~sarray();

  void push(T val);
  void pop(T &a);
  T returnTop();

  // T returnTop();

  // sarray(int s);
};