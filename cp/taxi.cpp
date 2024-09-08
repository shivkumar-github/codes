#include <bits/stdc++.h>
using namespace std;
int main()
{
	// METHOD: 1: Using 0 based array and bit complex logic
	// vector<int> g(4, 0);
	// int n;
	// int taxis = 0;
	// cin >> n;
	// for (int i = 0; i < n; i++)
	// {
	// 	int t;
	// 	cin >> t;
	// 	g[t - 1]++;
	// }

	// combining 1 and 3s
	// int onesTothrees = min(g[0], g[2]);
	// taxis += onesTothrees;
	// g[0] -= onesTothrees;
	// g[2] -= onesTothrees;
	// // combine 2s and 2s
	// taxis += (g[1] / 2);
	// g[1] = g[1] % 2;
	// // combine 1s with twos
	// int onesToTwos = g[1]%2;
	// g[1] -= (onesToTwos);
	// g[0] -= min(2,g[0])*onesToTwos;
	// taxis += onesToTwos;
	// // combine 1s with ones
	// taxis += (g[0] / 4);
	// g[0] = bool(g[0] % 4); // all remaining ones will be converted in one group
	// // adding all remaining groups
	// taxis += (g[0] + g[1] + g[2] + g[3]);
	// cout << taxis << endl;

	int n;
	cin >> n;
	int arr[5] = {0};
	for (int i = 0; i < n;i++){
		int t;
		cin >> t;
		arr[t]++;
	}
	// inserting 3s and 4s
	int taxi = arr[4] + arr[3];
	arr[1] = arr[1] - arr[3];
	if(arr[1] < 0)
		arr[1] = 0;
	taxi += arr[2] / 2;
	if(arr[2]%2){
		// we still have 1 2 remaining
		taxi++;
		arr[1] -= 2;
		if(arr[1] < 0)
			arr[1] = 0;
	}
	// if still ones are remaining
	taxi += (arr[1] / 4 + bool(arr[1] % 4));
	cout << taxi << endl;
	return 0;
}
