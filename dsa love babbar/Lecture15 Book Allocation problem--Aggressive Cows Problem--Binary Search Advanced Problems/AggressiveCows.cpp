/*
https://www.codingninjas.com/studio/problems/aggressive-cows_1082559
Babbar hasn't explained it well ....look another video on youtube

*/
// #include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintArray(vector<int> &stallNo)
{
    for (int i = 0; i < stallNo.size(); i++) cout << stallNo[i] << " ";
    cout << endl;
}

bool isPossibleSol(vector<int> &stallNo, int k, int mid)
{
    int LastCowStall = stallNo[0]; // we must start from the first stall to get maximum number of cows alloted at mid distance if starting from any further index we might loose some cases
    int CowCount = 1;
    for (int i = 0; i < stallNo.size(); i++)
    {
        if (stallNo[i] - LastCowStall >= mid)
        {
            CowCount++;
            if (CowCount == k) return true;
            LastCowStall = stallNo[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stallNo, int k)
{
    int ans = -1;
    sort(stallNo.begin(), stallNo.end());
    int start = 0;
    int end = stallNo[stallNo.size() - 1] - stallNo[0]; // maximum stallNo - minimum stallNo
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSol(stallNo, k, mid)) // => isPossibleSol(stallNo,k,mid) == 1
        {
            ans = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int noOfCows = 4;
    cout << aggressiveCows(stalls, noOfCows) << endl;
    return 0;
}