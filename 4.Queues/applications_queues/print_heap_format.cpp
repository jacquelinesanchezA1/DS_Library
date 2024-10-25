#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printHeap(int arr[]) {

    int n = arr.size();
    if (n == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    queue<int> q;
    q.push(0);  // start from the root

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            int index = q.front();
            q.pop();
            cout << arr[index] << " ";

            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < n) {
                q.push(leftChild);
            }
            if (rightChild < n) {
                q.push(rightChild);
            }
        }

        cout << endl; // move to the next line for the next level
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Printing array in heap manner:" << endl;
    printHeap(arr);
    return 0;
}