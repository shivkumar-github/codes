// leetcode : https://leetcode.com/problems/next-greater-element-i/


class Solution
{
public:
	// METHOD : 2 : using a map time complexity = O(m) (I didn't find a better solution without map, map is used in somehow way for this question)
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> ans(nums1.size(), -1); // initialising all with -1
		stack<int> st;					   // stack to store elements of whose we need to find nearest greater
		map<int, int> mp;				   //  mp to store indices of element in nums1 (we can use find() but will increase time complexity)
		for (int i = 0; i < nums1.size(); i++)
		{ // storing indices
			mp.insert({nums1[i], i});
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			if (st.empty() || st.top() > nums2[i])
			{ // if stack is empty or curr element is not greater then push it in stack
				st.push(nums2[i]);
			}
			else
			{
				while (!st.empty() && st.top() < nums2[i])
				{									   // unless the el inside stack is lesser the nums2[i] is answer for that
					if (mp.find(st.top()) != mp.end()) // if that stack el exist in first nums then store it's result
						ans[mp[st.top()]] = nums2[i];
					st.pop(); // pop the elements
				}
				st.push(nums2[i]); // we have to find greater for this element also
			}
		}
		return ans;
	} // time complexity
};

// METHOD : 3 O(m*n) time complexity  and space complexity = O(n) for stack
class Solution
{
public:
	int ind(vector<int> arr, int key)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == key)
			{
				return i;
			}
		}
		return -1;
	}
	// METHOD : 1 : \
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> ans(nums1.size(), -1);
		stack<int> st;
		for (int i = 0; i < nums2.size(); i++)
		{
			if (st.empty() || st.top() > nums2[i])
			{
				st.push(nums2[i]);
			}
			else
			{
				while (!st.empty() && st.top() < nums2[i])
				{
					int index = ind(nums1, st.top()); // finding indices in nums1 by traversal
					if (index != -1)
						ans[index] = nums2[i];
					st.pop();
				}
				st.push(nums2[i]);
			}
		}
		return ans;
	}
};

