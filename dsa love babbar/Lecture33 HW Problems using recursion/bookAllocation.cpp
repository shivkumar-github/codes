/*
book allocation coding Ninjas
https://www.codingninjas.com/studio/problems/allocate-books_1090540
*/
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int mid, vector<int> pages, int m)
{
    int stdCnt = 1;
    int maxPages = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        if (maxPages + pages[i] <= mid)
            maxPages += pages[i];

        else
        {
            stdCnt++;
            if (stdCnt > m || pages[i] > mid)
                return false;
            maxPages = pages[i];
        }
    }
    return true;
}

int findPages(vector<int> pages, int m, int s, int e)
{
    if (s > e)
        return -1;
    if (m > pages.size())
        return -1;
    int ans = -1; // the answer must be initialised as -1 as we have put in condition if(possible != -1) which is needed in cases when vomid bhi possible solution nahi hai aur uske baad ke bhi, so no value will be assigned to answer and the value with which it is initialised will be returned
    int mid = s + (e - s) / 2;
    if (isPossible(mid, pages, m))
    {
        ans = mid;
        int possible = findPages(pages, m, s, mid - 1);
        if (possible != -1)
            ans = possible;
    }
    else
    {
        int possible = findPages(pages, m, mid + 1, e);
        if (possible != -1)
            ans = possible;
    }
    return ans;
}

int sumOfPages(vector<int> pages)
{
    int sum = 0;
    for (int i = 0; i < pages.size(); i++)
        sum += pages[i];
    return sum;
}

int main()
{
    vector<int> pages = {12, 34, 67, 90};
    // ans = 113
    int students = 2;
    int sum = sumOfPages(pages);
    cout << findPages(pages, students, 0, sum) << endl;

    return 0;
}