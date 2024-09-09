#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		int cnt = 0;
		string up, down;
		cin >> up;
		cin >> down;
		if (n < 3)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i <= n - 3; i++)
		{
			char c1 = up[i], c2 = up[i + 1], c3 = up[i + 2], c4 = down[i], c5 = down[i + 1], c6 = down[i + 2];
			if (((c1 == '.' && c2 == '.' && c3 == '.') && (c4 == 'x' && c5 == '.' && c6 == 'x')) || ((c1 == 'x' && c2 == '.' && c3 == 'x') && (c4 == '.' && c5 == '.' && c6 == '.')))
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}