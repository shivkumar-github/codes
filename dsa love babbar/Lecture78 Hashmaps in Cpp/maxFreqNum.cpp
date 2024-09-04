/*
maximum occuring character
coding ninjas
https://www.codingninjas.com/studio/problems/maximum-frequency-number_920319
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = INT16_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (count[arr[i]] == maxFreq)
            return arr[i];
    }

    // this is not right as because when two elements have same max frequency then it gives the number which achieves the max frequency first and not the element which occurs in the array first
    // int size = arr.size();
    // unordered_map<int, int> count;
    // int maxFreq = 0;
    // int ans;
    // for (int i = 0; i < size; i++)
    // {
    //     count[arr[i]]++;
    //     if (count[arr[i]] > maxFreq)
    //     {
    //         maxFreq = count[arr[i]];
    //         ans = arr[i];
    //     }
        
    // }
    // return ans;
 
}

int main()
{
    int size;
    // cout << "Enter size of your vector : " << endl;
    // vector<int> arr = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6};
    vector<int> arr = {4, -5, 1};
    // 2 12 2 11 -12 2 -1 2 2 11 12 2 -6
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> arr[i];
    // }
    int ans = maximumFrequency(arr, size);
    cout << ans << endl;
    return 0;
}