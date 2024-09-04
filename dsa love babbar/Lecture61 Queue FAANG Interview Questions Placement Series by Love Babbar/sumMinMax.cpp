/*
https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
	int minMaxSum(vector<int> arr, int k)
	{
		int ans = 0;
		int mini = 0;
		int maxi = 0;
		queue<int> q;
		for (int i = 0; i < k; i++)
		{
			if (arr[mini] > arr[i])
				mini = i;
			if (arr[maxi] < arr[i])
				maxi = i;
		}
		ans += (arr[mini] + arr[maxi]);
		for (int i = k; i < arr.size(); i++)
		{
			if (arr[i] >= arr[maxi])
			{
				maxi = i;
			}
			else if (maxi == i - k)
			{
				maxi = i - k + 1;
				for (int j = i - k + 2; j <= i; j++)
				{
					if (arr[j] >= arr[maxi])
					{
						maxi = j;
					}
				}
			}

			if (arr[i] <= arr[mini])
				mini = i;
			else if (mini == i - k)
			{
				mini = i - k + 1;
				for (int j = i - k + 2; j <= i; j++)
				{
					if (arr[mini] < arr[j]){
						mini = j;
					}
				}
			}
			ans += (arr[mini] + arr[maxi]);
		}
		return ans;
	}// time complexity is O(n*k) as in worst case for every iteration we have to check for all elements to reset the max and min
};

class Solution
{
public:
	int minMaxSum(vector<int> arr, int k)
	{
		int n = arr.size();
		deque<int> min, max;
		int i = 0, j = 0, sum = 0;
		while (j < n)
		{
			while (!min.empty() && min.back() > arr[j])
			{
				min.pop_back();
			}
			while (!max.empty() && max.back() < arr[j])
			{
				max.pop_back();
			}
			min.push_back(arr[j]);
			max.push_back(arr[j]);
			if (j - i + 1 == k)
			{
				int mini = min.front();
				if (mini == arr[i])
					min.pop_front();
				int maxi = max.front();
				if (maxi == arr[i])
					max.pop_front();
				sum += (mini + maxi);
				i++;
			}
			j++;
		}
		return sum;
	} // time complexity O(N) and space complexity O(k)
};

int main()
{
	vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
	Solution s;
	Solution1 s1;
	cout << s1.minMaxSum(arr,4) << endl;
	cout << s.minMaxSum(arr, 4) << endl;
	return 0;
}