/*
Coding ninja
https://www.codingninjas.com/studio/problems/ninja-and-sorted-arrays_1214628
Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array.
You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.

For example:

‘ARR1’ = [3 6 9 0 0]
‘ARR2’ = [4 10]
After merging the ‘ARR1’ and ‘ARR2’ in ‘ARR1’.
‘ARR1’ = [3 4 6 9 10]
*/

// approach => pehle compare kar kar ke dalo aur phir bache hue dalo
#include <iostream>
#include <vector>
using namespace std;

void printVec(int vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void ninjaAndSortedArrays(int arr1[], int arr2[], int m, int n, int ans[])
{

    int itans = 0;
    int i1 = 0, i2 = 0;
    while (i1 < m && i2 < n)
    {
        if (arr1[i1] < arr2[i2])
        {
            ans[itans++] = arr1[i1++];

            
        }
        else
        {
            ans[itans++] = arr2[i2++];

   
        }
    }
    while (i1 < n)
    {
        ans[itans++] = arr1[i1++];
        
    }
    while (i2 < m)
    {
        ans[itans++] = arr2[i2++];
        
    }
}

int main()
{
    int Vec1[] = {1, 2, 4, 5, 7};
    int Vec2[] = {6, 10};
    int ans[7] = {0};
    ninjaAndSortedArrays(Vec1, Vec2, 5, 2, ans);
    printVec(ans, 7);
    return 0;
}