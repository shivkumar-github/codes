/*
Majority element 
we wil be given an array and we have to see which element is occuring more than n/2 times(not equal) ->> n is size of array
only one element can have occurance more than n/2 times as if one element occures more than n/2 times other elements can not occur more than n/2 times
*/

/* Brute force solution - count the number of  occurance of each element one by one and if occurance goes > n/2 times ->> but not optimal solution */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

// a better algorithm but takes space complexity O(n) in worst case
// int majorityElement(vector<int> v){
//     map<int,int> mpp;

//     // time complexity O(n)
//     for (int i = 0; i < v.size(); i++)
//     {
//         mpp[v[i]]++;
//     }
//     for (auto itr : mpp)
//     {
//         if(itr.second > v.size()/2){
//             return itr.first;
//         }
//     }
//     return -1;
// }

// now the optimal solution
// moore's algorithm
/* perform moore voting algorithm find the candidate element and then we will check if it has occured more than n/2 times if yes then it is the ans and if not then no element has occured more than n/2 times (no element except candidate can occur more than n/2 times ->> just like elections)*/
// also as majority element occures more than n/2 time after traversing whole array it will have cnt more than 0
int majorityElement(vector<int> v){
    int cnt = 0;
    int candEl; // candidate element 
    for (int i = 0; i < v.size(); i++)
    {
        if(cnt == 0){
            cnt++;
            candEl = v[i];
        }
        else if(v[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    // for the case where no majority element exists
    int cnt1 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == candEl)
        {
            cnt1++;
        }
        
    }
    if(cnt1 > v.size()/2)
    return candEl;
    return -1;
}
// this algorithm takes constant space hence space complexity O(1)  and time complexity O(n) (worst case big of O)


int main(){

return 0;
}