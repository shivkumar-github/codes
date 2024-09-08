#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size;
		cin >> size;
		stack<int> st;
		int cost = 0;
		for (int i = 0; i < size; i++)
		{
			char c;
			cin >> c;
			if (c == '(')
				st.push(i);
			else if (c == ')' || (c == '_' && !st.empty()))
			{
				cost += (i - st.top());
				st.pop();
			}
			else
					st.push(i);
		}
		cout << cost << endl;
	}
	return 0;
}
