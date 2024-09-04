/*
https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149

Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array
*/

#include <iostream>
#include <vector>
using namespace std;

void input_array(vector<int> &arr)
{
    int size;
    cout << "Enter the size of second array : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int input;
        cout << "Enter element no. " << i << ":";
        cin >> input;
        arr.push_back(input);
    }
}

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int count = 0;
    vector<int> intersect_arr;
    for (int i = 0; i < n; i++)
    {
        // finding if there is any match of element in first array in second array
        bool anymatch = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                bool anymatch_in_intersect_arr = 0;
                for (int k = 0; k < intersect_arr.size(); k++)
                {
                    if (intersect_arr[k] == arr1[i])
                    {
                        anymatch_in_intersect_arr = 1;
                    }
                }
                if (anymatch_in_intersect_arr == 0)
                {
                    intersect_arr.push_back(arr1[i]);
                }
            }
        }
    }
    return intersect_arr;
}

int main()
{
    int t;
    cin >> t ;
for (int i = 0; i < t; i++)
{
    vector<int> array1;
    vector<int> array2;
    input_array(array1);
    input_array(array2);

    for (int i = 0; i < (findArrayIntersection(array1, array1.size(), array2, array2.size())).size(); i++)
    {
        cout << (findArrayIntersection(array1, array1.size(), array2, array2.size()))[i] << " ";
    }
    cout << endl;
}


    return 0;
}