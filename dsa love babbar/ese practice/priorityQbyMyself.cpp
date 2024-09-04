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