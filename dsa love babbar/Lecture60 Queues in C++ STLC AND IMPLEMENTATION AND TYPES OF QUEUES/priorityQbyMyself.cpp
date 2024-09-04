/*
learning priority queue from gfg
*/

#include <iostream>
using namespace std;

class item
{
public:
        int value;
        int priority;
}

class queue
{
public:
        item *arr;
        int size = -1;
        // array to store the element of priority queue
        item pr[100000];

        void enQueue(int val, int priority)
        {
                // increase the size
                size++;

                // insert the element
                pr[size].value = val;
                pr[size].priority = priority;
        }

        // function to check the top element
        int peek()
        {
                int HighestPriority = INT16_MIN;
                int ind = -1;
                for (int i = 0; i <= size; i++)
                {
                        if (HighestPriority == pr[i].priority && ind != -1 && pr[ind].value < pr[i].value)
                        {
                                ind = i;
                        }
                        else if (HighestPriority < pr[i].value)
                        {
                                HighestPriority = pr[i].priority;
                                ind = i;
                        }
                }
                return ind;
        }
        void deQueue()
        {
                // finding position of element with highest priority
                int ind = peek();

                // shift the whole
                for (int i = ind; i < size; i++)
                {
                        pr[i] = pr[i + 1];
                }
                size--;
        }
};

int main()
{
        // Function Call to insert elements
        // as per the priority
        enqueue(10, 2);
        enqueue(14, 4);
        enqueue(16, 4);
        enqueue(12, 3);

        // Stores the top element
        // at the moment
        int ind = peek();

        cout << pr[ind].value << endl;

        // Dequeue the top element
        dequeue();

        // Check the top element
        ind = peek();
        cout << pr[ind].value << endl;

        // Dequeue the top element
        dequeue();

        // Check the top element
        ind = peek();
        cout << pr[ind].value << endl;

        return 0;
}

#include <iostream>
using namespace std;

// Node
struct Node {
    int value;
    int priority;
    Node* next;
};

class PriorityQueue {
public:
    Node* head;

    PriorityQueue() {
        head = NULL;
    }

    void enQueue(int val, int priority) {
        Node* newNode = new Node();
        newNode->value = val;
        newNode->priority = priority;
        newNode->next = NULL;

        if (head == NULL || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deQueue() {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int peek() {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->value;
    }
};

int main() {
    PriorityQueue pq;

    pq.enQueue(10, 2);
    pq.enQueue(14, 4);
    pq.enQueue(16, 4);
    pq.enQueue(12, 3);

    cout << pq.peek() << endl;
    pq.deQueue();

    cout << pq.peek() << endl;
    pq.deQueue();

    cout << pq.peek() << endl;

    return 0;
}