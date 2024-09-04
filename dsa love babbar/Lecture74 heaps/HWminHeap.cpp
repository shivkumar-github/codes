/*
Implementation of min heap using arrays
*/

#include <iostream>
using namespace std;

class heap
{
public:
    int arr[10000];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertInHeap(int value)
    {
        size++;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] > arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void deletionroot()
    {
        if (size == 0)
        {
            cout << "The heap is empty, no element to delete!" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int smallest = i;
            int l = 2 * smallest;
            int r = 2 * smallest + 1;
            if (arr[l] < arr[smallest] && l <= size)
            {
                smallest = l;
            }
            if (arr[r] < arr[smallest] && r <= size)
            {
                smallest = r;
            }

            // agar smallest change hua hai to swap karo agar nhi to ho gaya kaam
            if (smallest != i)
            {
                swap(arr[smallest], arr[i]);
            }
            else
            {
                return;
            }
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (arr[l] < arr[smallest] && l <= size)
    {
        smallest = l;
    }
    if (arr[r] < arr[smallest] && r <= size)
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}

int main()
{
    // heap h;
    // h.insertInHeap(12);
    // h.insertInHeap(10);
    // h.insertInHeap(9);
    // h.insertInHeap(6);
    // h.insertInHeap(15);
    // h.insertInHeap(17);
    // h.printHeap();

    // h.deletionroot();
    // // h.deletionroot();
    // h.printHeap();

    int arr[7] = {-1, 12, 10, 9, 6, 15, 17};
    // int arr[7] = {-1, 12, 9, 10, 6, 15, 17};
    int size = 6;

    for (int i = size / 2; i >= 1; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}