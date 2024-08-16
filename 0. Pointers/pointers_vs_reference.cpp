#include <iostream> 
using namespace std; 


int main() {
    int a = 10;
    int b = 20;

    // Pointer
    int *ptra = &a; // ptra points to the address of a
    *ptra = 15; // changes the value of a to 15

    // Reference
    int &ref = a; // ref is an alias for a
    ref = 25; // changes the value of a to 25

    cout << "a = " << a << endl; // Outputs: a = 25
    cout << "b = " << b << endl; // Outputs: b = 20
    cout << "*ptra = " << *ptra << endl; // Outputs: *ptra = 25
    cout << "ref = " << ref << endl; // Outputs: ref = 25

    return 0;
}
