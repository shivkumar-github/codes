#include <bits/stdc++.h>
using namespace std;
class NQueue{
public:
    int* arr, *next, *front, *rear;
    int size, k, freespot; // k is the number of queues
    // Initialize your data structure.
    NQueue(int size, int k){
        // Write your code here.
        this->size= size;
        this->k = k;
        rear = new int [k];
        front = new int[k];
        for(int i = 0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        arr = new int[size];
        next = new int[size];
        for(int i = 0;i<size;i++){
            next[i] = i+1;
        }
        freespot = 0;
        next[size-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // check for overflow
        // cout << "freespot is : " << freespot << endl;
        if(freespot == -1)  return false; // no empty space is present

        // find first free index
        int index = freespot;
        // cout << " index is " << index << endl;
        // update freespot
        freespot = next[index];

        // check if it is the first element of queue
        if (front[m - 1] == -1) {
            front[m-1] = index;
        }
        else {
            // else link new element to the prev element
            next[rear[m - 1]] = index;
        }

        // update next // DOUBT: WHY THIS STATEMENT IS WRITTEN to show that this is the last element of the queue hence no further element is present(also the next will be updated if new element is inserted in that queue by statement next[rear[m-1]])
        next[index] = -1;

        // update rear
        rear[m-1] = index;

        // push element
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // check if underflow
        if(front[m-1] == -1) return -1;

        // find the index from which we have to pop
        int index = front[m-1];

        // update front
        front[m-1] = next[index];

        // as freespot always represents the free index in array it should be now pointed to the current element which is going to be popped , but how we will link this index to the old freespot index ; by storing it in next[index] = freespot
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    ~NQueue(){
        delete[] arr;
        delete [] next;
        delete [] rear;
        delete [] front;
    }
};


int main() {
    int k = 2;    // Number of queues
    int size = 5; // Size of the array
    NQueue nq(size, k);

    // Enqueue operations
	cout << nq.enqueue(2, 1) << endl; // Enqueue 2 into queue 1
	cout << nq.enqueue(3, 2) << endl; // Enqueue 3 into queue 2
	cout << nq.enqueue(4, 1) << endl; // Enqueue 4 into queue 1

    // Dequeue operations
    cout << nq.dequeue(2) << endl; // Should output 3 (from queue 2)
    cout << nq.dequeue(1) << endl; // Should output 2 (from queue 1)

    return 0;
}
