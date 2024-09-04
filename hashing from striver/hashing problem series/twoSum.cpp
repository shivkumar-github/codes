/*

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
                unordered_map<int, int>umpp;
                for (int i = 0; i < nums.size(); i++)
                {
                        int checkFor = nums[i];
                        vector<int> ans(2);
                        for (auto j : umpp)
                        {
                                if (target - checkFor == j.second)
                                {
                                        ans[0] = checkFor;
                                        ans[1] = j.second;
                                        return ans;
                                }
                        }
                        umpp.insert({i, checkFor});
                }
        }
};

int main()
{

        vector<int> nums = {2, 7, 11, 15};
        Solution s;
        vector<int> ans = s.twoSum(nums, 9);
        for (int i = 0; i < ans.size(); i++)
        {
                cout<< ans[i] << " ";
        }
        cout << endl;
        return 0;
}