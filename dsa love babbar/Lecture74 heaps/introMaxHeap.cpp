/*
What is heap?
    heap is a complete binary tree that comes with heap order property
        ->> max heap or min heap
        1. max heap ->> the value of parent node is always greater than the value of child node
        2. min heap ->> the value of parent node is always smaller than the value of child node
    CBT = complete binary tree => every level is completely filled except the last one

    pehle left mein dalenge fir  right mein
    for more clarity see examples of complete binary tree on internet

    |************* raltion between indices *************|
        ->> node index = i => left child index = 2*i and right index = 2*i + 1
        ->> node index = i i => parent node index = int(i/2)
        ->> coordinates of leaf nodes = n/2 + 1 to n where n is total elements in heap
    |************how to declare heaps using priority queus of stl**********|
    by providing additional two arguments we can declare a min heap or max heap using priority queue
    priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue <int, vector<int>, greater<int> > pq; // here we are declaring the pq with int data type and is implemented using vector with greater int which returns true if first element is greater than the second 
*/

#include <iostream>
using namespace std;

/*
Implementing the heap using array and then
   Insrtion in inside heap
       ->> MAX heap:
       1. the logic which we are going to implement needs the heap to be filled inside array from index = 1 and not 0
       2. we will insert the new element at the last position of array
       3. take it to it's correct position
           I. compare it with parent node and if it does not satify the property of max heap then exchange the parent node with child node(i.e. node inserted and it's parent node) until the property of heap is satisfied

*/

class heap
{
    int arr[1000];
    int size; // to know the total size of the array

public:
    heap()
    {
        arr[0] = -1; // as we are following 1 based indexing
        size = 0;
    }

    // last mein new element insert karo then usko heapify karo
    void insert(int data)
    {
        size++;
        int index = size; // index for new value inserted so that we can compare it with the parent node and swap the nodes accordingly
        arr[index] = data;

        while (index > 1) // else in index = 1 parent index = 0 so we will compare it with 0 th element which is not correct
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return; // element inserted and the property of is being followed
            }
        }
        // shorter code for insertion is written in practice version
    } // time compmlexity of insertion O(log n) ->> time complexity number of comparisons in the worst case = Log(n) with base 2 where n is no of elements in the heap
      // and the number of levels in the heap are one more than the log(n) to the base 2 ->> try by drawing a tree

    void deleteroot()
    {
        // neche wale ko uper leke aao aur niche wali node ko delete kardo aur bache hue ko heapify karo
        if (size == 0)
        {
            cout << "Nothing to delete kindly check again!" << endl;
            return;
        }

        // step 1 :  put last element into first index
        arr[1] = arr[size];

        // step 2 : delete last element
        // make the last one inaccessible by decreamenting the size
        size--;

        // step 3 : restore the heap property
        // take the root node to it's correct position
        int i = 1;
        int min = i;
        while (i * 2 <= size) // checking if the child node exists
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[i] < arr[leftIndex])
            {
                // swap(arr[i], arr[leftIndex]);
                min = leftIndex;
            }
            if (rightIndex <= size && arr[i] < arr[rightIndex]) // no problem in using else if beacuse if initially the right child is greater than parent and the left child also then only it will be parent
            {
                // swap(arr[i], arr[rightIndex]);
                min = rightIndex;
            }

            if (min != i)
            {
                swap(arr[min], arr[i]);
            }
            else
            {
                return;
            }
        }
        // babbar's code is a bit wrong
    } // time complexity => O(log n) ->> number of comparisons in the worst case
    // why we are always deleteing root node and not any another node in the middle ->> It is the standard deleteroot operation ->> (GFG)

    // elements are printed levelwise as while mapping the nodes in the tree we have given indecises levelwise and hences they are inserted in array levelwise
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

/*
heapify algorithm
    1. In CBT leaf nodes lie between (n/2 + 1) to n th index and leaf nodes are already heap nodes so no need to procces them
       so we have to process n/2 to 1
    2. We will take each node individually and then heapify each node representing an index
*/
void heapify(int arr[], int size, int i) // complexity log n -> how
{
    // ek node ko uski sahi jagah pe leke jana heapify ka kaam hai
    // us index pe jo node hai usse pura niche tak heap mein convert kar dega
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // take care ki left aur right size se bada na ho jayein else we will try to access element beyond the array
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

int main()
{
    heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    // h.deleteroot();
    // h.deleteroot();
    // h.deleteroot();
    // h.deleteroot();
    // h.deleteroot();
    // h.deleteroot();
    h.insert(60);
    h.insert(55);
    h.insert(57);
    h.insert(53);
    h.deleteroot();
    h.print();

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    int arr[7] = {-1, 48, 53, 55, 50, 52, 51};
    int size = 6;
    for (int i = size / 2; i > 0; i--) // why in this order  and not i = 1 to i = n/2 because algorithm works in that way  and how complexity = O(n)
    {
        heapify(arr, size, i);
    }

    cout << "printing the array now ..." << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// cleaning and social work when out of the room
