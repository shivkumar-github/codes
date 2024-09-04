#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
	int *arr;
	int size;
	int capacity;
	Heap(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		arr = new int[capacity];
	}
	void printHeap()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	void insertKey(int val)
	{
		size = size + 1;
		int index = size - 1;
		arr[index] = val;
			int parent = (index - 1) / 2;
		while (index >= 1 && (arr[parent] < arr[index]))
		{
			swap(arr[parent], arr[index]);
			index = parent;
			parent = (index - 1) / 2;
		}
	} // Time Complexity - O(log N) where N is the total elements present in heap
	void deleteKey(int val)
	{
		
	}
};

int main()
{
	Heap h(100);
	h.insertKey(10);
	h.insertKey(6);
	h.insertKey(4);
	h.insertKey(5);
	h.insertKey(11);
	h.printHeap();
	return 0;
}