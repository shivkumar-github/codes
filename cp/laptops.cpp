/*

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}
	vector<pair<int, int>> mp;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		mp.push_back({t, prices[i]});
	}
	sort(mp.begin(), mp.end(), greater<pair<int, int>>());
	for (int i = 0; i < n-1;i++){
		if(mp[i].second < mp[i+1].second){
			cout << "Happy Alex" << endl;
			return 0;
		}
	}
	cout << "Poor Alex";
	return 0;
}