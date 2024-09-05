#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, s = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s += v[i];
	}
	sort(v.begin(), v.end());
	int i,st = 0;
	for (i = n-1; i >= 0;i--){
		st += v[i];
		if(st > s - st)
			break;
	}
	cout << n - i;
	return 0;
}