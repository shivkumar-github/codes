/*
give all the possible permutation of a given string
 approach 1 (given by  striver) // one with more space complexity
*/

#include<iostream>
#include <vector>
using namespace std;

// class Solution
// {
//         void solve(vector<vector<int>>& ans , vector<int> nums, vector<int> ds, vector<bool>freq){
//                 // base case
//                 if (ds.size()>= nums.size())
//                 {
//                         ans.push_back(nums);
//                         return;
//                 }
//                 for (int i = 0; i < nums.size(); i++)
//                 {
//                         if (!freq[i])
//                         {
//                                 freq[i] = true;
//                                 ds.push_back(nums[i]);
//                                 solve(ans, nums, ds, freq);

//                                 // backtracking
//                                 ds.pop_back();
//                                 freq[i] = false;
//                         }
//                 }
//         }

//         vector<vector<int>> permute(vector<int> nums)
//         {
//                 vector<vector<int>> ans;
//                 vector<bool> freq(nums.size(), false);
//                 vector<int> ds;
//                 solve(ans, nums, ds, freq);
//                 return ans;
//         }
// };

class solution{
        public:

        void solve(vector<vector<int>>& ans, vector<bool>freq,vector<int> ds , vector<int> nums){
                if (ds.size() >= nums.size())
                {
                        ans.push_back(ds);
                        return;
                }
                for (int i = 0; i < nums.size(); i++)
                {
                        if (!freq[i])
                        {
                                freq[i] = true;
                                ds.push_back(nums[i]);
                                solve(ans, freq, ds, nums);
                                // backtracking 
                                ds.pop_back();
                                freq[i] = false;
                        }
                }
        }

        vector<vector<int>> permute(vector<int> nums){
                vector<vector<int>> ans;
                vector<int> ds;
                vector<bool> freq(nums.size(), false);
                solve(ans, freq, ds, nums);
                return ans;
        }
}; // time complexity = > O(n * n!) 
// space complexity = > O(n)

int main()
{
        vector<int> input = {};
        solution s;
        vector<vector<int>> ans = s.permute(input);
        for (int i = 0; i < ans.size(); i++)
        {
                for (int j = 0; j < ans[i].size(); j++)
                {
                        cout << ans[i][j] << " ";
                }
                cout << endl;
        }
        vector<int> ve = {1, 2, 3, 4};
        int len = ve.size();
        cout<< len << endl;
        ve.push_back(2);
        cout<< len  << ve.size()<< endl;
        char arr[10];
        string str;
        cin.get(arr,10);
        return 0;
}