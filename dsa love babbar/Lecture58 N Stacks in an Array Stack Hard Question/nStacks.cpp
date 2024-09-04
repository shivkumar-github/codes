/*

*/

#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> arr)
{
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}

// METHOD :  1 using brute force -- no need to look at this approach but in summary In this approach we are initialising half stacks from left side of array and half from right and every time we are doing pop or push we are moveing all elements after that stack hence this takes much time complexity and is not readable at all
class NStack
{
public:
	vector<int> tops;
	vector<int> arr;
	int ltpmx;
	int rtpmn;
	int N;
	int S;
	// Initialize your data structure.
	NStack(int N, int S)
	{
		this->N = N;
		this->S = S;
		// Write your code here.
		this->arr = vector<int>(S);
		this->tops = vector<int>(N);
		ltpmx = -1;
		rtpmn = S;
		for (int i = 0; i < N; i++)
		{
			if (i < N / 2)
			{
				tops[i] = -1;
			}
			else
			{
				tops[i] = S;
			}
		}
	}

	void moveStacksPush(int m, int N, vector<int> &arr, vector<int> &tops, int ltpmx, int rtpmn)
	{
		if (m - 1 < N / 2)
		{
			for (int i = tops[m]; i <= ltpmx; i++)
			{
				arr[i] = arr[i + 1];
			}
			for (int i = m; i < N / 2; i++)
			{
				if (tops[i] != -1)
					tops[i]++;
			}
		}
		else
		{
			for (int i = rtpmn - 1; i < tops[m - 1] - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			for (int i = m; i < tops.size(); i++)
			{
				tops[i]--;
			}
		}
	}
	// Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
	bool push(int x, int m)
	{
		if (rtpmn - ltpmx == 1)
		{
			return false;
		}
		// Write your code here.
		if (m - 1 < N / 2)
		{
			if (tops[m - 1] == -1 && m != 1)
				tops[m - 1] = tops[m - 2];
			moveStacksPush(m, N, arr, tops, ltpmx, rtpmn);
			arr[++tops[m - 1]] = x;
			if (tops[m - 1] > ltpmx)
				ltpmx = tops[m - 1];
		}
		else
		{
			if (tops[m - 1] == arr.size() && m - 2 >= N / 2)
				tops[m - 1] = tops[m - 2];
			moveStacksPush(m, N, arr, tops, ltpmx, rtpmn);
			arr[--tops[m - 1]] = x;
			if (tops[m - 1] < rtpmn)
				rtpmn = tops[m - 1];
		}
		return true;
	}

	void moveStacksPop(int m, int N, vector<int> &arr, vector<int> &tops, int ltpmx, int rtpmn)
	{
		if (m - 1 < N / 2)
		{
			int i;
			for (i = tops[m - 1] + 1; i < ltpmx; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[i] = 0; // arr ltmpx = 0;
			ltpmx--;
			for (int i = m; i < N / 2; i++)
				tops[i]--;
		}
		else
		{
			int i;
			for (int i = tops[m - 1] - 1; i > rtpmn; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[rtpmn] = 0;
			rtpmn++;
			for (int i = m; i < tops.size(); i++)
				tops[i]++;
		}
	}
	// Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
	int pop(int m)
	{
		// Write your code here.
		int ans = -1;
		if (m - 1 < N / 2)
		{
			if (tops[m - 1] != -1 && tops[m - 1] != tops[m - 2])
			{
				ans = arr[tops[m - 1]];
				tops[m - 1]--;
				moveStacksPop(m, N, arr, tops, ltpmx, rtpmn);
				if (ltpmx - tops[m - 1] == 1)
				{
					ltpmx = tops[m - 1];
				}
			}
		}
		else
		{
			if (tops[m - 1] != arr.size() && tops[m - 1] != tops[m - 2])
			{
				ans = arr[tops[m - 1]];
				tops[m - 1]++;
				moveStacksPop(m, N, arr, tops, ltpmx, rtpmn);
				if (tops[m - 1] - rtpmn == 1)
				{
					rtpmn = tops[m - 1];
				}
			}
		}
		return ans;
	}
};

// METHOD : 2 USING A NEXT ARRAY WHICH STORES THE INDEX WHICH IS TO BE PROCESSED AFTER THE INDEX AT WHICH IT IS STORED
// for better understanding just take a example with array size 6 and 3 stacks implemented and insert elements alternately in stack one and two and you will know how this works
// also look at explaination image
// DOUBT: DRU RUN AND WRITE THE METHOD ONCE AGAIN BY YOURSELF

class NStack
{
	int *arr;
	int *top;
	int *next;
	int n, s;
	int freespot;

public:
	// Initialize your data structure.
	NStack(int N, int S)
	{
		// Write your code here.
		n = N;
		s = S;
		arr = new int[s];
		top = new int[n];
		next = new int[s];

		// top initialise
		for (int i = 0; i < n; i++)
		{
			top[i] = -1;
		}

		// next initialise
		for (int i = 0; i < s; i++)
		{
			next[i] = i + 1;
		}
		// update last index value to -1
		next[s - 1] = -1;

		// initialiste freespot
		freespot = 0;
	}

	// Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
	bool push(int x, int m)
	{
		// Write your code here.
		if (freespot == -1)
		{
			return false;
		}

		// find index
		int index = freespot;

		// update freespot
		freespot = next[index];

		// insert element into array
		arr[index] = x;

		// update next
		next[index] = top[m - 1];

		// update top
		top[m - 1] = index;

		return true;
	}

	// Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
	int pop(int m)
	{
		// Write your code here.
		// check
		if (top[m - 1] == -1)
		{
			return -1;
		}

		int index = top[m - 1];

		top[m - 1] = next[index];

		next[index] = freespot;

		freespot = index;

		return arr[index];
	}
};

class NStack
{
	int *arr;
	int *next;
	int *tops;
	int freespot;
	int s;
	int n;

public:
	// Initialize your data structure.
	NStack(int N, int S)
	{
		// Write your code here.
		n = N;
		s = S;
		arr = new int[s];
		next = new int[s];
		tops = new int[n];
		for (int i = 0; i < s; i++)
		{
			next[i] = i + 1;
		}
		// as there is no free space after last index hence set last = -1;
		next[s - 1] = -1;
		for (int i = 0; i < n; i++)
			tops[i] = -1;
		freespot = 0;
	}

	// Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
	bool push(int x, int m)
	{
		// Write your code here.
		if (freespot == -1)
		{
			return false;
		}
		int index = freespot;
		// update the freespot
		freespot = next[index];
		arr[index] = x;
		next[index] = tops[m - 1];
		tops[m - 1]++;
		return true;
	}

	// Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
	int pop(int m)
	{
		// Write your code here.
		if (tops[m - 1] == -1)
			return -1;
		int index = tops[m - 1];
		tops[m - 1] = next[index];
		next[index] = freespot;
		freespot = index;
		return arr[index];
	}
};

int main()
{
	NStack nstack(14, 42);
	/*
	14 42 10
	1 33 13
	1 22 6
	1 19 13
	1 28 8
	2 13
	1 17 3
	1 50 11
	2 3
	2 11
	1 9 13
	*/
	cout << (nstack.push(33, 13) ? "True" : "False") << endl;
	cout << (nstack.push(22, 6) ? "True" : "False") << endl;
	cout << (nstack.push(19, 13) ? "True" : "False") << endl;
	cout << (nstack.push(28, 8) ? "True" : "False") << endl;
	cout << nstack.pop(13) << endl;
	cout << (nstack.push(17, 3) ? "True" : "False") << endl;
	cout << (nstack.push(50, 11) ? "True" : "False") << endl;
	cout << nstack.pop(3) << endl;
	cout << nstack.pop(11) << endl;
	cout << (nstack.push(9, 13) ? "True" : "False") << endl;

	return 0;
}