#include <bits/stdc++.h>
using namespace std;

int main()
{
	string in;
	int T;
	cin >> in;
	cin >> T;
	vector<int> storage(in.size() + 1);
	storage[0] = -1;
	storage[1] = 0;
	for (int i = 0; i < in.size() - 1; i++)
	{
		storage[i + 2] = storage[i + 1] + ((in[i] == in[i + 1]) ? 1 : 0);
	}
	while (T--)
	{
		int l, r, cnt = 0;
		cin >> l >> r;
		cout << storage[r] - storage[l] << endl;
	}
}