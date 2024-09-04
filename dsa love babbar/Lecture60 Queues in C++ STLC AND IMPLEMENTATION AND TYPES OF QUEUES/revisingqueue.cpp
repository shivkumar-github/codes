#include <bits/stdc++.h>
using namespace std;

// // class queue
// // {
// // public:
// // 	int *arr;
// // 	int size;
// // 	int front, rear;
// // 	queue(int size)
// // 	{
// // 		this->size = size;
// // 		arr = new int[size];
// // 		this->front = 0;
// // 		this->rear = 0;
// // 	}
// // 	void enqueue(int data)
// // 	{
// // 		if (rear == size)
// // 		{
// // 			cout << "Queue is full!" << endl;
// // 			return;
// // 		}
// // 		arr[rear++] = data;
// // 	}
// // 	int dequeue()
// // 	{
// // 		if (front == rear)
// // 			return -1;
// // 		int ans = arr[front];
// // 		for (int i = 0; i < rear - 1; i++)
// // 		{
// // 			arr[i] = arr[i + 1];
// // 		}
// // 		rear--;
// // 		return ans;
// // 	}
// // };

// // int main()
// // {

// // 	return 0;
// // }

// // class queue
// // {
// // 	stack<int> s1;
// // 	stack<int> s2;
// // 	void enqueue(int val)
// // 	{
// // 		s1.push(val);
// // 	}
// // 	int dequeue()
// // 	{
// // 		if (s1.empty() && s2.empty())
// // 		{
// // 			return -1;
// // 		}
// // 		else
// // 		{
// // 			if (s2.empty())
// // 			{
// // 				while (!s1.empty())
// // 				{
// // 					s2.push(s1.top());
// // 					s1.pop();
// // 				}
// // 			}
// // 			int val = s2.top();
// // 			s2.pop();
// // 			return val;
// // 		}
// // 	}
// // };

class Queue
{
public:
	int qfront, qrear, size, *arr;

	Queue(int size)
	{
		qrear = qfront = -1;
		this->size = size;
		arr = new int[size];
	}
	~Queue()
	{
		delete arr;
	}
	void enQueue(int data)
	{
		if ((qrear + 1) % size == qfront || (qfront == 0 && qrear == size-1))
		{
			cout << "Queue is full, can not insert element!" << endl;
			return;
		}
		else if (qfront == -1 )
		{
			qfront = qrear = 0;
			arr[qrear] = data;
		}
		else if (qrear == size - 1 && qfront != 0)
		{
			qrear = 0;
			arr[qrear] = data;
		}
		else
		{
			arr[++qrear] = data;
		}
	}
	int deQueue()
	{
		if (qfront == -1)
		{
			cout << "Queue is empty!" << endl;
			return INT16_MIN;
		}
		int data = arr[qfront];
		if (qfront == qrear)
			qrear = qfront = -1;
		else if (qfront == size - 1)
			qfront = 0;
		else
			qfront++;
		return data;
	}
	void displayQueue()
	{

		if (qfront == -1)
		{
			cout << "Queue is empty!" << endl;
			return;
		}
		else
		{
			cout << "Elements in the queue are : ";
			if (qrear >= qfront)
			{
				for (int i = qfront; i <= qrear; i++)
					cout << arr[i] << " ";
				cout << endl;
			}
			else
			{
				for (int i = qfront; i < size; i++)
					cout << arr[i] << " ";
				for (int i = 0; i <= qrear; i++)
					cout << arr[i] << " ";
				cout << endl;
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
	cout << "Deleted value : " << q.deQueue() << endl;
	cout << "Deleted value : " << q.deQueue() << endl;

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}

// // priority queue
// class item
// {
// public:
// 	int value;
// 	int priority;
// 	item(int value, int priority)
// 	{
// 		this->priority = priority;
// 		this->value = value;
// 	}
// };

// class Queue
// {
// 	int size;
// 	item items[100000];
// 	Queue(int size)
// 	{
// 		size = -1;
// 	}
// 	void enQueue(int value, int priority)
// 	{
// 		items++size].value = value;
// 		items[size].priority = priority;
// 	}
// 	int peek() // return the index of item with highest priority
// 	{
// 		if (size == -1)
// 		{
// 			return INT16_MIN;
// 		}
// 		else
// 		{
// 			int hPrty = 0;
// 			int ind = 0;
// 			for (int i = 1; i <= size; i++)
// 			{
// 				if (hPrty == items[i].priority && items[i].value > items[ind].value)
// 				{
// 					ind = i;
// 					hPrty = items[i].priority;
// 				}
// 				else if (hPrty < items[i].priority)
// 				{
// 					ind = i;
// 					hPrty = items[i].priority;
// 				}
// 			}
// 			return items[ind].value;
// 		}
// 	}
// 	int deQueue()
// 	{
// 		if (size == -1)
// 		{
// 			return INT16_MIN;
// 		}
// 		else
// 		{
// 			int ind = peek();
// 			int ans = items[ind].value;
// 			for (int i = ind; i < size; i++)
// 			{
// 				items[ind] = item[ind + 1];
// 			}
// 			size--;
// 			return ans;
// 		}
// 	}
// };