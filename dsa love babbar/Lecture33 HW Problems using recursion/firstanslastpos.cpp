/*
lecture13  problem using recursion
*/

#include <iostream>
#include <vector>
using namespace std;

int first_occurance(vector<int> arr, int key, int s, int e)
{
    // base case
    if (s > e)
    {
        return -1;
    }
    int first;
    int mid = s + (e - s) / 2;
    if (arr[mid] < key)
    {
        first = first_occurance(arr, key, mid + 1, e);
    }
    else if (arr[mid] > key)
    {
        first = first_occurance(arr, key, s, mid - 1);
    }
    else if (arr[mid] == key)
    {
        first = mid; // mid answer ho sakta hai
        if (first_occurance(arr, key, s, mid - 1) != -1)
        {
            first = first_occurance(arr, key, s, mid - 1); // agar aur koi element key ke equal aa raha ho to usse first ke equal kardo
        }
    }

    return first;
}

int last_occurance(vector<int> arr, int key, int s, int e)
{
    if (s > e)
    {
        return -1;
    }
    int last;
    int mid = s + (e - s) / 2;
    if (arr[mid] < key)
    {
        last = last_occurance(arr, key, mid + 1, e);
    }
    else if (arr[mid] > key)
    {
        last = last_occurance(arr, key, s, mid - 1);
    }
    else if (arr[mid] == key)
    {
        last = mid;
        if (last_occurance(arr, key, mid + 1, e) != -1)
        {
            last = last_occurance(arr, key, mid + 1, e);
        }
    }
    return last;
}

pair<int, int> first_and_last_pos(vector<int> arr, int key, int s, int e)
{
    pair<int, int> p;
    p.first = first_occurance(arr, key, s, e);
    p.second = last_occurance(arr, key, s, e);
    return p;
}

int main()
{
    vector<int> array = {0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5};
    cout << "First occurance = " << first_occurance(array, 3, 0, 11) << " and last occurance = " << last_occurance(array, 3, 0, 11) << endl;
    cout << "first occurance = " << first_and_last_pos(array, 3, 0, 11).first << " and last occurance = " << first_and_last_pos(array, 3, 0, 11).second << endl;
    return 0;
}