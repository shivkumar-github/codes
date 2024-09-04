/*
    Insertion Sort :-
        It is just like placing cards (having numbers on them) in our hand in increasing order

    =>  Insertion sort is an adaptive algorithm i.e. it takes advantage of properties of input data to increase the performance.
        For example Insertion sort (an adaptive algorithm) performs better in case of partially sorted arrays

    =>  Insertion Sort is an stable algorithm.
    =>  Relative order of equal elements remain same after sorting
    =>  For ex. array = {2,10,3,4,5(a),5(b)} => {2,3,4,5(a),5(b),10}
        As while inserting 5(b) ...5(b)<10 but is not greater than 5(a) therefore it will be placed after 5(a)

    => Time Complexity => 1 + 2 + 3 + .... + (n-1) = O(n^2)
        Best Case => O(n-1) = O(n)
        Worst Case => O(n^2)
    => Space Complexity => O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void InsertionSort(vector<int> &array)
{
    for (int i = 1; i < array.size(); i++)
    {
        int temp = array[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (array[j] > temp)
            {
                // shift the part of array before the element till it's position and then place the element stored in temp at the position
                array[j + 1] = array[j];
            }
            else
            {          // ruk jao
                break; // yaha pe break ho raha hai yani j-- (updation nahi hogi)
            }
        }
        array[j + 1] = temp;
    }
}

int main()
{
    vector<int> array = {10, 1, 7, 4, 8, 2, 11};
    InsertionSort(array);
    printArray(array);

    return 0;
}