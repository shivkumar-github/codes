/*
circular queue-> in normal queue we move all the elements forward by 1 position i.e. as 1 person get out of the row we move that row forward
but in circular queue we move the counter towards the row rather than moving whole row
*/

#include <iostream>
#include <queue>
using namespace std;

class Queue
{
public:
        int front, rear, size;
        int *arr;
        Queue(int size)
        {
                this->size = size;
                front = rear = -1;
                arr = new int[this->size];
        }
        ~Queue()
        {
                delete arr;
        }
        void enQueue(int data)
        {
                if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) // first condition is not necessary as it is already covered by second case
                {
                        cout << "Queue is full" << endl;
                        return;
                }

                else if (front == -1) // inserting the first element
                {
                        front = rear = 0;
                        arr[rear] = data;
                }
                else if (rear == size - 1 && front != 0) // counter aage badh chuka hai aab pehle vali counter ki position pe element dal sakte hai
                {
                        rear = 0;
                        arr[rear] = data;
                }

                else
                {
                        rear++;
                        arr[rear] = data;
                }
        }

        int deQueue()
        {
                if (front == -1)
                {
                        cout << "Queue is empty!" << endl;
                        return INT16_MIN;
                }
                int data = arr[front];
                arr[front] = -1;
                if (front == rear)
                {
                        front = rear = -1;
                }
                else if (front == size - 1) // front at last position of
                {
                        front = 0;
                }
                else
                        front++;
        }
        void displayQueue()
        {
                if (front == -1)
                {
                        printf("\nQueue is Empty!");
                        return;
                }
                cout << "Elements in queue are : " << endl;
                if (rear > front)
                {
                        for (int i = front; i < rear + 1; i++)
                        {
                                cout << arr[i] << " ";
                        }
                        cout << endl;
                }
                else
                {
                        for (int i = front; i < size; i++)
                        {
                                cout << arr[i] << " ";
                        }
                        for (int i = 0; i <= rear; i++)
                        {
                                cout << arr[i] << " ";
                        }
                }
        }
};

int main()
{
      Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}