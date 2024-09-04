// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// leetcode = https://leetcode.com/problems/valid-parentheses/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	char match(char c)
	{
		if (c == '}')
			return '{';
		else if (c == ')')
			return '(';
		else if (c == ']')
			return '[';
		else
			return ' ';
	}
	bool closing(char c)
	{
		if (c == '}' || c == ')' || c == ']')
			return true;
		else
			return false;
	}
	// Function to check if brackets are balanced or not.
	bool ispar(string x)
	{
		// Your code here
		stack<char> st;
		for (int i = 0; i < x.size(); i++)
		{
			char c = x[i];
			if (closing(c))
			{
				if (st.empty())
					return false;
				if (st.top() == match(c))
					st.pop();
				else
					return false;
			}
			else
				st.push(c);
		}
		return st.empty();
	}
};// space and time complexity both O(n)
int main(){
	stack<int> s;
	return 0;
}