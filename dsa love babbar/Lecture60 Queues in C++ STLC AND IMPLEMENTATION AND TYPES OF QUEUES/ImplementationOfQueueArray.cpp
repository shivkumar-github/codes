/*
Implementing the queues(LIFO) using arrays
coding ninjas platform
https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908
*/

#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int qrear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[this->size]; // we can also use VLA (variable size array) by declaring arr = new int; but only modern compilers can handle vlas
        qfront = 0;
        qrear = 0;
    }
~Queue(){
    delete arr;
}
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (qfront == qrear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (qrear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue()
    {
        if (qfront == qrear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            for (int i = 0; i < qrear -1; i++)
            {
                arr[i] = arr[i+1];
            }
            qrear--;
            return ans;
        }
    }


    int front()
    {
        if (qfront == qrear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    void printQ()
    {
        for (int i = qfront; i < qrear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1(2);
    q1.enqueue(10);
    q1.enqueue(2);
    q1.dequeue();
    q1.enqueue(5);
    q1.printQ();


    return 0;
}