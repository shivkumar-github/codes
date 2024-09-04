/*
binary search implementation
- we apply binary search tree while searching and element in sorted array
-in binary search time complexity O(n) => O(logn)(base 2)
it has following main steps
1. finding the index of the middle term
2. compare
3. if equal return mid
4. if greater than key then search in left part
5. if lessaer than key then choose right part\
6. back to step 1 again
*/

#include <iostream>
#include <vector>
using namespace std;

// using recursion
int binSearch(vector<int> arr, int key, int s, int e)
{
        if (s > e)
        {
                return -1;
        }
        else
        {
                int mid = s + (e - s) / 2;
                if (arr[mid] == key)
                {
                        return mid;
                }
                else if (arr[mid] < key)
                {
                        return binSearch(arr, key, mid + 1, e);
                }
                else
                {
                        return binSearch(arr, key, s, mid - 1);
                }
        }
}

// non recursive
int binSearch1(vector<int> arr, int key)
{
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e)
        {
                int mid = s + (e - s) / 2;
                if (arr[mid] == key)
                {
                        return mid;
                }
                else if (arr[mid] < key)
                {
                        s = mid + 1;
                }
                else
                {
                        e = mid - 1;
                }
        }
        return -1; // when not found
}

int main()
{
        vector<int> odd = {1, 2, 4, 5, 6, 8, 22};
        cout << binSearch(odd, 22, 0, odd.size() - 1);
        cout << binSearch1(odd, 22);
        return 0;
}