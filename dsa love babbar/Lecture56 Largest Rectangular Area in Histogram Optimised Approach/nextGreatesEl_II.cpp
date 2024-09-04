// // https://leetcode.com/problems/next-greater-element-ii/submissions/\

// approach by me
class Solution
{
public:
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		stack<int> st;
		int maxind = 0;
		// finding maximum element
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] > nums[maxind])
				maxind = i;

		int ansEl = nums[maxind] + 1;
		vector<int> ans(nums.size(), ansEl); // initialising array with the element that is not present in the array

		for (int i = 0; i < nums.size(); i++)
		{
			if ((st.empty() || nums[st.top()] > nums[i]) && nums[i] != nums[maxind] && ans[i] == ansEl) // if stack is empty or top is greater than ith element and it is not maximum and it's greater is not found before then push into stack
				st.push(i);
			else 
			{
				while (!st.empty() && nums[st.top()] < nums[i]) // if stack not empty and i th el is greater for st.top()
				{
					ans[st.top()] = nums[i]; // store in ans and pop from stack
					st.pop();
				}
				if (ans[i] == ansEl && nums[i] != nums[maxind]) //also if this ith el is not max and it's greater is not found before then push it in st
					st.push(i);
			}
			if ((i == nums.size() - 1) && !st.empty()) // if stack is not empty(greater is not found for some el)
				i = -1; // reset index to traverse again (resetting to -1 after completion of iteration it will become ++,0 )
		}
		// for those (max elements) we don't find greater return -1 fo them 
		for (int i = 0; i < ans.size(); i++) // we cant use only 1 if statement for cases when more than 1 maximum elements are present
			if (ans[i] == ansEl)
				ans[i] = -1;

		return ans;
	}
};

// METHOD : 2 : DOUBT: WRITE CODE BY YOURSELF
vector<int> nextGreaterElements(vector<int> &nums)
	{
		stack<int> st;
		
		return ans;
	}