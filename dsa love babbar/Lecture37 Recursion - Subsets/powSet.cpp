/*
https://leetcode.com/problems/subsets/
78. Subsets
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>>& ans, int index, vector<int> forward){// don't put &forward here(otherwise while going from exclusive to inclusive at same level the forward from exclusive is forwarded to exclusive)
    if (index >= nums.size())
    {
        ans.push_back(forward);
        return;
    }

    // exclude ->> sirf index ko aage badhana hai
    solve(nums,ans, index+1,forward); // can not do ++index as we also need to use it in inclusive

    // include ->> index element ko forward mein push karke, index aage badhado
    int element = nums[index];
    forward.push_back(element);
    solve(nums,ans, index+1,forward);
}

// if n elements in the set then 2^n elements in the power set
vector<vector<int>> returnPowSet(vector<int>& numbers){
    vector<vector<int>> ans; // to store the main ans
    vector<int> forward; // vector to be forwarder
    int index = 0; // index of element to be included or excluded
    // humein forward vector aur index bhi forward karna hai to naya function banate hai jo actual kam karega
    solve(numbers,ans, index,forward);
    return ans;
}// image = https://drive.google.com/file/d/1WSS_ogKKLS-uu8dWESy-5Xo6ARwrZ8QQ/view?usp=drivesdk 


int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = returnPowSet(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}