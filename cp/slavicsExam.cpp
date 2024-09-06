#include <bits/stdc++.h>
using namespace std;

void solve(string& s, string& t)
{
	int titr = 0, sitr = 0;
	while (titr < t.size())
	{
		while (sitr < s.size() && t[titr] != s[sitr] && s[sitr] != '?')
			sitr++;
		if (sitr < s.size())
			s[sitr++] = t[titr++];
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	sitr = 0;
	// print the string
	while (sitr < s.size())
	{
		if (s[sitr] == '?')
			cout << 'a';
		else
			cout << s[sitr];
		sitr++;
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s = "ayy?x", t = "a";
		cin >> s >> t;
		solve(s, t);
	}
	return 0;
}