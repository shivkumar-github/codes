/*

*/

#include <iostream>
using namespace std;

class heap
{
    int arr[1000];
    int size;

public:
    heap()
    {
        arr[0] = -1; // as we are following 1 based index
        size = 0;
    }

    // last mein insert karo then usko heapify karo
    void insertInHeap(int value)
    {
        size++;
        int index = size;
        arr[size] = value;
        int parentIndex = index / 2;
        while (arr[index] > arr[parentIndex] && index > 1)
        {
            swap(arr[parentIndex], arr[index]);
            index = parentIndex;
            parentIndex = index / 2;
        }
    }

    void deletionHeap()
    { // according to standardisation we delete root node
        // algo => root la khali gheun java ani then delete it and then heapify the remaining heap
        if (size == 0)
        {
            cout << "NO node to delete, empty heap!!" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int largest = 1;
        while (largest <= size)
        {

            int leftIndex = 2 * largest;
            int rightIndex = 2 * largest + 1;
            if (arr[leftIndex] > arr[largest] && leftIndex <= size)
            {
                swap(arr[largest], arr[leftIndex]);
                largest = leftIndex;
            }
            else if (arr[rightIndex] > arr[largest] && rightIndex <= size)
            {
                swap(arr[largest], arr[rightIndex]);
                largest = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
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
    // if (i >= n / 2 + 1 && i <= size)
    // {
    //     return;
    // }

    while (i <= size)
    {

        int temp = i;
        int l = 2 * temp;
        int r = 2 * temp + 1;
        if (arr[l] > arr[temp])
        {
            temp = l;
        }
        if (arr[r] > arr[temp])
        {
            temp = r;
        }
        if (temp != i)
        {
            swap(arr[temp], arr[i]);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    heap h;
    h.insertInHeap(50);
    h.insertInHeap(55);
    h.insertInHeap(53);
    h.insertInHeap(52);
    h.insertInHeap(54);
    h.print();

    int arr[7] = {-1, 48, 53, 55, 50, 52, 51};
    int size = 6;
    for (int i = 1; i <= size/2; i++)
    {
        heapify(arr, size, i);
    }

    cout << "Printing the array : " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}