
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int T;
// 	cin >> T;
// 	while (T--)
// 	{
// 		int n, k;
// 		cin >> n >> k;
// 		if (n%2 != k%2)
// 		{
// 			cout << "NO" << endl;
// 			continue;
// 		}
// 		if (k == 1 && n % 2)
// 		{
// 			cout << "YES" << endl;
// 			continue;
// 		}
// 		int prv = 1, cr = n - 1, itr = k - 2;
// 		int npts = 2;
// 		bool flag = true;
// 		while (itr--)
// 		{
// 			cr = cr - prv - 2;
// 			prv = prv + 2;
// 			if (cr <= 0)
// 			{
// 				flag = false;
// 				break;
// 			}
// 		}
// 		cout << ((flag) ? "YES" : "NO") << endl;
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long int n, k;
		cin >> n >> k;
		cout << ((k * k <= n && n % 2 == k % 2)?"YES":"NO") << endl;
	}
	return 0;
}
