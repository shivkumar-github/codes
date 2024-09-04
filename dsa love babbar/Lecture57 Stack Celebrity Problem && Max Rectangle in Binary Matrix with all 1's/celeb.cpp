#include <iostream>
#include <stack>
using namespace std;

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// DOUBT: WHY STACK IS NEEDED TO BE USED

// METHOD : 1 brute force TC = O(n2)
class Solution
{
public:
	bool checkceleb(vector<vector<int>> mat, int i)
	{
		for (int j = 0; j < mat.size(); j++)
		{
			if (j == i)
				continue;
			if (!mat[j][i])
			{
				return false;
			}
		}
		return true;
	}
	// Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int>> &mat)
	{
		// code here
		int n = mat.size();
		for (int i = 0; i < n; i++)
		{
			int isceleb = true;
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j])
				{
					isceleb = false;
					break;
				}
			}
			if (isceleb)
			{
				if (checkceleb(mat, i))
				{
					return i;
				}
			}
		}
		return -1;
	}
};

// METHOD : 2 Without using stack taking two elements and trying eliminate by seeing if they know each other TC O(n) SC = O(1)

class Solution
{
public:
	// function to verify the candidate
	bool isAns(vector<vector<int>> mat, int candidate)
	{
		// check if everyone knows that person
		for (int i = 0; i < mat.size(); i++)
		{
			if (i == candidate) // according to given condition
				continue;
			if (!mat[i][candidate])
				return false;
		}
		// check if that element knows no one
		for (int i = 0; i < mat.size(); i++)
		{
			if (mat[candidate][i])
				return false;
		}
		return true;
	}

	// Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int>> &mat)
	{
		// code here
		int n = mat.size();
		int top = 0;
		int down = n - 1;
		while (top < down)
		{
			if (mat[top][down]) // top knows down hence top is not celeb
				top++;

			else if (mat[down][top]) // down knows top hence he is not celeb
				down--;

			else
			{ // both don't know each other hence both can't be celebrity
				top++;
				down--;
			}
		}
		if (top > down) // no celebrity
			return -1;

		else								   // top = down
			return isAns(mat, top) ? top : -1; // check if candidate is out answer or not
	}
};

// METHOD :  3  Using stack and same approach as previous method in this stack method you can also push all the elements first and then do the process of taking two elements out and push element only if it satisfies the codition same as stated and at last the remaining element will be potential candidate
class Solution
{
public:
	// function to verify the candidate
	bool isAns(vector<vector<int>> mat, int candidate)
	{
		// check if everyone knows that person
		for (int i = 0; i < mat.size(); i++)
		{
			if (i == candidate) // according to given condition no one knows himself
				continue;
			if (!mat[i][candidate])
				return false;
		}
		// check if that element knows no one
		for (int i = 0; i < mat.size(); i++)
		{
			if (mat[candidate][i])
				return false;
		}
		return true;
	}

	// Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int>> &mat)
	{
		// code here

		int n = mat.size();
		if (n < 2)
			return 0;
		stack<int> st;
		st.push(0);
		st.push(1);
		int indtopush = 2;
		while (st.size() > 1)
		{
			int E1 = st.top(); // popping two elements from the stack
			st.pop();
			int E2 = st.top();
			st.pop();
			int NEW1 = E1;
			int NEW2 = E2; // storing next element that needs to be pushed ( if we stored them in E1 and E2 then while checking it will give segmentation fault when E1 is >n)
			if (mat[E1][E2])
			{ // if someone knows another person then he is not celebrity hence push next element indicated by indtopush
				NEW1 = indtopush++;
			}
			else if (mat[E2][E1])
			{
				NEW2 = indtopush++;
			}
			else
			{ // if both don't know each other then both can not be celeb
				NEW1 = indtopush++;
				NEW2 = indtopush++;
			}
			if (NEW1 < n) // if they are in size of mat push them into mat
				st.push(NEW1);
			if (NEW2 < n)
				st.push(NEW2);
		}
		// we have to check if stack is empty or not before doing pop
		return (!st.empty() && isAns(mat, st.top())) ? st.top() : -1; // check if our candidate answer is right
	}
};



// METHOD :  4 SAME AS THREE JUST BIT SHORT AS WE FIRST PUSH ELEMENTS INSIDE THE STACK

class Solution {
  public:
    // function to verify the candidate
    bool isAns(vector<vector<int>> mat, int candidate){
        // check if everyone knows that person
        for(int i = 0;i<mat.size();i++){
            if(i==candidate) // according to given condition no one knows himself
                continue;
            if(!mat[i][candidate])
                return false;
        }
        // check if that element knows no one
        for(int i = 0;i<mat.size();i++){
            if(mat[candidate][i])
                return false;
        }
        return true;
    }

    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        // code here
        
        int n = mat.size();
        if(n<2)
            return 0;
        stack<int> st;
        for(int i = 0;i<n;i++)
            st.push(i);
            
        while(st.size()>1){
            int E1 = st.top(); // popping two elements from the stack
            st.pop();
            int E2 = st.top();
            st.pop();
            if(mat[E2][E1] && !mat[E1][E2]){ // if someone knows another person then he is not celebrity hence push next element indicated by indtopush
                st.push(E1);
            }
            else if(mat[E1][E2] && !mat[E2][E1]){
                st.push(E2);
            }
        }
        // we have to check if stack is empty or not before doing pop
        return (!st.empty() && isAns(mat, st.top()))?st.top():-1; // check if our candidate answer is right
    }
};