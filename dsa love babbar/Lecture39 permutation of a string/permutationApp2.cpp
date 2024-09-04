/*
give all the possible permutation of a given string
*/

#includeiostream>
#include <vector>
using namespace std;

class Solution
{
        void solve(vector<vector<int>> &ans, vector<int> nums, int index)
        { // here nums is acting like forward in previous questions (to carry )
                // base case
                if (index >= nums.size())
                {
                        ans.push_back(nums);
                        return;
                }
                for (int i = 0; i < nums.size(); i++)
                {
                        swap(nums[index], nums[i]);
                        solve(ans, nums, index + 1);
                        // backtracking by placing the characters at same position again
                        swap(nums[index], nums[i]);
                }
        }

        vector<vector<int>> permute(vector<int> nums)
        {
                int index = 0;
                vector<vector<int>> ans;
                solve(ans, nums, index);
                return ans;
        }
};

class solution{
        public:
        void solve(vector<vector<int>>& ans, vector<int>nums, int index = 0){
                if (index>= nums.size())
                {
                        ans.push_back(nums);
                        return;
                }
                for (int i = index; i <nums.size() ; i++)
                {
                        swap(nums[index], nums[i]);
                        solve(ans, nums, index + 1);
                        swap(nums[index], nums[i]);
                }                
        }
        vector<vector<int>> permute(vector<int> nums){
                vector<vector<int>> ans;
                solve(ans, nums);
                return ans;
        }
};

int
main()
{
        vector<int> input = {};
        Solution s;
        vector<vector<int>> ans = s.permute(input);
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