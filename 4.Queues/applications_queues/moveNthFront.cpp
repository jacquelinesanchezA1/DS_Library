#include <iostream>
#include <queue>
using namespace std;

void moveNthFront(queue<int> &q, int n)
{
    int size = q.size();
    if (n <= 0 || n > size)
    {
        return;
    }

    // step 1: Move n-1 elements to the rear ( (n = 5, move 4 elements) ||  (n = 3, move 2 elements) etc)
    for (int i = 1; i < n - 1; i++)
    {
        int frontElement = q.front();// so you can insert it 
        q.pop();
        q.push(frontElement); // so you dont lose it, push to the back
    }

    // step 2: Move the nth element to the front
    int nthMinusOneElement = q.front();
    q.pop();
    q.push(nthMinusOneElement); // the last element before nth element! 
}

int main()
{

    queue<int> q;
    q.push(5);
    q.push(11);
    q.push(34);
    q.push(67);
    q.push(43);

    cout << "Before moving: " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    q.push(5);
    q.push(11);
    q.push(34);
    q.push(67);
    q.push(43);

    moveNthFront(q, 4);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}