#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	// vector<pair<int, int>> mp;
	// for (int i = 0; i < n; i++)
	// {
	// 	int price, quality;
	// 	cin >> price >> quality;
	// 	mp.push_back({price, quality});
	// }
	// sort(mp.begin(), mp.end(), greater<pair<int, int>>());
	// for (int i = 0; i < n-1;i++){
	// 	if(mp[i].second < mp[i+1].second && mp[i].first != mp[i].second){
	// 		cout << "Happy Alex" << endl;
	// 		return 0;
	// 	}
	// }
	// cout << "Poor Alex";
	// also as the price and quality are distinct therefore if for any laptop if quality is lesser than the price then automatically there will be such pair of laptops
	// i.e. for poor alex all the laptops should have quality exactly eqaul to their price else there will be some pair of laptops satisfying given condition
	bool f = false;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a != b)
		{
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";
	return 0;
}