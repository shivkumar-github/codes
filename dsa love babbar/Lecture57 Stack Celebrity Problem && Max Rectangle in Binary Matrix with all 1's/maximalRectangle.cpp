// https://leetcode.com/problems/maximal-rectangle/

class Solution
{
public:
	int maximumRectangleHisto(vector<int> nums)
	{ // calculating max area for the selected part
		int n = nums.size();
		vector<int> rsm(n, n);
		vector<int> lsm(n, -1);
		stack<int> st;
		int i = n - 1;
		while (i >= 0)
		{
			while (!st.empty() && nums[st.top()] >= nums[i])
			{
				lsm[st.top()] = i;
				st.pop();
			}
			if (!st.empty())
			{
				rsm[i] = st.top();
			}
			st.push(i);
			i--;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int area = (rsm[i] - lsm[i] - 1) * nums[i];
			if (area > ans)
				ans = area;
		}
		return ans;
	}
	int maximalRectangle(vector<vector<char>> &matrix)
	{
		int n = matrix.size();
		int m = matrix[0].size();
		vector<int> oneCount(m, 0); // vector to maintain height of each candle in selected part of matrix

		int ans = 0; // initialise with max area in first row
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < m; j++)
			{ // update the candle height vector first
				int el = matrix[i][j] - '0';
				if (el)
					oneCount[j] += 1; // if 1 then increase height by 1
				else
					oneCount[j] = 0; // if not 1 then reset candle height = 0
			}
			int area = maximumRectangleHisto(oneCount); // find maximum area for each time and if it is greater than ans then store it in ans
			if (area > ans)
				ans = area;
		}
		return ans; // return the answer
	}
}; // TC = O(N*M)
// SC = O(M) // FOR STACK , rsm, lsm