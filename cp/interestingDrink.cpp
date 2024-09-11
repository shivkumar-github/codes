/*

METHOD: 1 extra time complexity but less space
#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> &arr, int key)
{
	int s = 0;
	int e = arr.size() - 1;
	int mid = s + (e - s) / 2;
	if (key < arr[s])
		return -1;
	int ans = -1;
	while (s <= e)
	{
		// cout << mid;
		mid = s + (e - s) / 2;
		if (arr[mid] <= key)
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}
	sort(prices.begin(), prices.end());
	int T;
	cin >> T;
	int d = T;
	while (d--)
	{
		int coins;
		cin >> coins;
		int ind = binSearch(prices, coins);
		cout << ind + 1 << endl;
	}
	return 0;
}

*/

/*
METHOD: 2 using dp a bit extra space O(1e5)
but q + m time complexity
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> f(1e5 + 1, 0);
	vector<int> pf(1e5 + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		f[v[i]]++;
	}
	for (int i = 1; i <= 1e5; i++)
	{
		pf[i] = pf[i - 1] + f[i];
	}

	int q;
	cin >> q;
	while (q--)
	{
		int coins;
		cin >> coins;
		if(coins <= 1e5)
		cout << pf[coins] << endl;
		else
			cout << n << endl;
	}
	return 0;
}