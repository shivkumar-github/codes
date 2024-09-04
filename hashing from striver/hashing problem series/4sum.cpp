#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int returnIndBin(vector<int> nums, int elts, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2; // => equivalent to (n+1)/2 /* We must not use (s+e)/2 directly as sum(s+e) may exceed the limit of integers  when s and e are laarger but when we use the whole condition then there are no chances of the exceeding limit value of integer*/
            if (nums[mid] == elts)
            {
                return mid;
            }
            else if (nums[mid] < elts)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int tsum = nums[i] + nums[j] + nums[k];
                    int toFind = target - tsum;
                    int index = returnIndBin(nums, toFind, k + 1, n - 1);
                    if (index != -1)
                    {
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        temp[3] = nums[index];
                        bool isAlready = false;
                        for (int itr = 0; itr < ans.size(); itr++)
                        {
                            if (temp == ans[itr])
                            {
                                isAlready = true;
                            }
                        }
                        if (!isAlready)
                            ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};// sorted = -2 -1 0 0 1 2
    int target = 0;
    Solution s;
    vector<vector<int>> ans = s.fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int k = 0; k < ans[i].size(); k++)
        {
            cout << ans[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
