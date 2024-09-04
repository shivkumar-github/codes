#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int ans = 0;
	while (T--)
	{
		int b1, b2, b3;
		cin >> b1 >> b2 >> b3;
		b1 += (b2 + b3);
		if(b1 >= 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}