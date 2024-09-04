/*
https://www.codingninjas.com/studio/problems/allocate-books_1090540
Coding Ninjas
*/

#include <iostream>
#include <vector>
using namespace std;

// ye function check karega ki kya hai value possible answer ho sakti hai
bool isPossible(vector<int> &arr, int students, int mid)
{
    int studentCount = 1;
    int possiblemaxPages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (possiblemaxPages + arr[i] <= mid)
            possiblemaxPages += arr[i];

        else
        {
            studentCount++;
            if (studentCount > students || arr[i] > mid) // if we do not include this condition then the pages of book (arr[i] when arr[i] > mid) the pages, arr[i] will never be alloted and  we will get wrong output when n = m
                return false;
            
            possiblemaxPages = arr[i]; // It is neccesary to add this as if we don't include this condition student count won't exceed
            // here allocation to first student is done and we have started allocation to second student
        }
    }
    return true;
}

// is function mein actual binary sorting hogi
int findPages(vector<int> &arr, int n, int m)
{
    if (m > n) return -1; // for the case when students are greater than books
    int ans = -1;
    int start = 0;
    int end = 0;
    for (int i = 0; i < arr.size(); i++) end += arr[i];

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // binary sorting ki condition depend karegi ki max value nikalni hai ya min
        // here min value is asked so start and end will be updated accordingly
        if (isPossible(arr, m, mid) == 1) // agar mid possible solution hai to aur min ke liye check karenge => left wale part mein jaynge
        {
            ans = mid;
            end = mid - 1;
        }
        else start = mid + 1;  // agar mid possible solution nahi hai to right vale part mein chale jao
    }
    return ans;
}

int main()
{
    vector<int> array = {1, 17, 14, 9, 15, 9, 14};
    int numberOfStudents = 7;
    cout << findPages(array, array.size(), numberOfStudents) << endl;
    return 0;
}