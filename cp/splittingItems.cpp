#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end(), greater<int>());
		int ca = 0, cb = 0, prev = -1;
		for (int i = 0; i < n; i++)
		{
			if (!(i % 2)) ca += v[i];
			else
			{
				int mn = min(k, prev - v[i]);
				cb += (v[i] + mn);
				k -= mn;
			}
			prev = v[i];
		}
		cout << ca - cb << endl;
	}
	return 0;
}