
#include <bits/stdc++.h>
using namespace std;
int main()
{
	// int n, a1, a2;
	// cin >> n;
	// int n1 = n;
	// unordered_map<int, int> mp1, mp2;
	// while (n1--)
	// {
	// 	int t;
	// 	cin >> t;
	// 	mp1[t]++;
	// }
	// n1 = n - 1;
	// while (n1--)
	// {
	// 	int t;
	// 	cin >> t;
	// 	mp2[t]++;
	// }
	// for (auto it : mp1)
	// {
	// 	if (it.second != mp2[it.first])
	// 	{
	// 		a1 = it.first;
	// 		mp1[a1] = mp2[a1];
	// 	}
	// }
	// n1 = n - 2;
	// while (n1--)
	// {
	// 	int t;
	// 	cin >> t;
	// 	mp1[t]++;
	// }
	// for (auto it : mp1)
	// {
	// 	if (it.second != 2 * mp2[it.first]) // as inserting again will double the frequency for non removed elements
	// 		a2 = it.first;
	// }
	// cout << a1 << endl
	// 	 << a2 << endl;
	// if sum of first array is s1 and second s2 and third s3 then the answer will be s2-s1 and s3-s2 with O(N) tc and constant space
	int n, n1, s1 = 0, s2 = 0, s3 = 0;
	cin >> n;
	n1 = n;
	while(n1--){
		int t;
		cin >> t;
		s1 += t;
	}
	n1 = n - 1;
	while(n1--){
		int t;
		cin >> t;
		s2 += t;
	}
	n1 = n - 2;
	while(n1--){
		int t;
		cin >> t;
		s3 += t;
	}
	cout << s1 - s2 << endl
		 << s2 - s3 << endl;
	return 0;
}