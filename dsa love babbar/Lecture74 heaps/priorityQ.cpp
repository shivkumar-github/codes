/*
we can implement both max and min heaps using STL

*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << "Using priority queue : " << endl;

    // max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout << "element at top " << pq.top() << endl;
    pq.pop();
    cout << "now element at top " << pq.top() << endl;
    cout << pq.size() << endl;
    cout << pq.empty() << endl; 

    // min heap 
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout << "element at top " << minheap.top() << endl;
    pq.pop();
    cout << "now element at top " << minheap.top() << endl;
    cout << minheap.size() << endl;
    cout << minheap.empty() << endl;
    return 0;
}