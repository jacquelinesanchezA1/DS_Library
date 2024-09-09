#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int sum = 0;

    // Loop through the array and calculate the sum
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    // Output the sum
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
