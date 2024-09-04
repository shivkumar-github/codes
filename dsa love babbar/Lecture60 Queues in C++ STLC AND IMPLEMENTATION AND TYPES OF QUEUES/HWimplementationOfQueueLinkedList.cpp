/*
Implementing Queue using linked list
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~node()
    {
        this->next = NULL;
        cout << "Memory is cleared for the data " << this->data << endl;
    }
};

class Queue
{
public:
    node *qfront;
    node *qrear;

    // constructor to initialise queue and it's qrear and qfront
    Queue()
    {
        qrear = NULL;
        qfront = NULL;
    }

    // to push elements
    void enqueue(int data)
    {w
        node *temp = new node(data);
        if (qrear != NULL) // queue is not empty
        {
            qrear->next = temp;
        }
        if (qfront == NULL) // queue is empty (i.e. qfront = qrear = NULL)
        {
            qfront = temp;
        }
        qrear = temp; // need to update qrear in both the cases
    }

    // to pop the elements
    int dequeue()
    {
        if (qfront == NULL)
            return -1;

        int ans = qfront->data;      // store the data
        node *nodeToDelete = qfront; // store the node
        qfront = qfront->next;       // update the qfront
        delete nodeToDelete;         // delete the node
        return ans;
    }

    bool isEmpty()
    {
        return qfront == NULL;
    }

    void printQ()
    {
        if (qfront == NULL)
        {
            cout << "The q is empty!" << endl;
            return;
        }

        node *temp = qfront;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(11);
    q1.enqueue(23);
    cout << q1.isEmpty() << endl;
    q1.enqueue(80);
    q1.printQ();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.printQ();
    cout << q1.isEmpty() << endl;

    return 0;
}