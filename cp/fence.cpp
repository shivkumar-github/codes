#include <bits/stdc++.h>
using namespace std;

int solve(int fn, int p)
{
}

int main()
{
	int fn, p;
	cin >> fn >> p;
	vector<int> arr(fn);
	for (int i = 0; i < fn; i++)
		cin >> arr[i];

	int minind = 0;
	int sum = 0;
	for (int i = 0; i < p; i++)
		sum += arr[i];
	int minsum = sum;
	for (int i = p; i < fn; i++)
	{
		sum += arr[i] - arr[i - p];
		if (sum < minsum)
		{
			minind = i - p + 1;
			minsum = sum;
		}
	}
	cout << minind + 1 << endl;
	return 0;
}