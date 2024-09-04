#include <bits/stdc++.h>
using namespace std;

// METHOD : 1 o(N2) gives tle
class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		int ans = 0;
		// brute force
		for (int i = 0; i < n; i++)
		{
			int curr = heights[i];
			// finding right smaller
			int ritr = i + 1;
			while (ritr <= n - 1 && heights[ritr] >= curr)
				ritr++;

			ritr = ritr - 1;
			// finding left smaller
			int litr = i - 1;
			while (litr >= 0 && heights[litr] >= curr)
				litr--;
			litr = litr + 1;
			// calculating area and storing the max
			int area = (ritr - litr + 1) * curr;
			if (area > ans)
				ans = area;
		}
		return ans;
	}
};
// brute force solution O(n2) time complexity but this won't work as this gives tle

// METHOD : 2 OPTIMAL BUT A BIT LONG ( 2 PASSES)
class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		int ans = 0;
		vector<int> rsm(n, n);
		vector<int> lsm(n, -1); // to store indices of right smaller and left smaller
		stack<int> st;
		// first find right smaller
		for (int i = n - 1; i >= 0; i--)
		{
			int cr = heights[i];
			while (!st.empty() && heights[st.top()] >= cr)
				st.pop();

			if (!st.empty())
				rsm[i] = st.top();
			// no need to push edge values (-1, and n ) as we are defining vector with that
			st.push(i);
		}
		// empty the stack before next operation
		while (!st.empty())
			st.pop();
		// similarly for left smaller
		for (int i = 0; i < n; i++)
		{
			int cr = heights[i];
			while (!st.empty() && heights[st.top()] >= cr)
				st.pop();

			if (!st.empty())
				lsm[i] = st.top();
			st.push(i);
		}
		for (int i = 0; i < n; i++)
		{
			int area = (rsm[i] - lsm[i] - 1) * heights[i];
			if (area > ans)
				ans = area;
		}
		return ans;
	}
};

// METHOD : 3 most optimal and short

class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int n = heights.size();
		int ans = 0;
		vector<int> rsm(n, n);
		vector<int> lsm(n, -1); // to store indices of right smaller and left smaller
		stack<int> st;
		// first find right smaller
		for (int i = n - 1; i >= 0; i--)
		{
			int cr = heights[i];
			while (!st.empty() && heights[st.top()] >= cr)
			{ // it is important to keep equal to sign here for cases when all elements are equal DOUBT: WHY THE FUCK EQUAL TO SIGN WE NEED OR DON'T
				lsm[st.top()] = i;
				st.pop();
			}
			if (!st.empty())
			{
				rsm[i] = st.top();
			}
			st.push(i);
		}
		for (int i = 0; i < n; i++)
		{
			int area = (rsm[i] - lsm[i] - 1) * heights[i];
			if (area > ans)
			{
				ans = area;
			}
		}
		return ans;
	}
};



int main()
{
	return 0;
}