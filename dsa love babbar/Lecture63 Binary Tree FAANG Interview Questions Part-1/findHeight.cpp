/*
https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/

#include <bits\stdc++.h>
using namespace std;

class Solution
{ // using recursion O
public:
	int height(struct Node *node)
	{
		if (!node)
			return 0;
		return max(height(node->left), height(node->right)) + 1;
	} // Time complexity - O(N)(N is no of nodes in tree) and space complexity will be the space used by recursion stack at any instant so that will be O(height)
};

class Solution
{
public:
	// Function to find the height of a binary tree.
	int height(struct Node *root)
	{
		// code here
		queue<Node *> q;
		q.push(root);
		q.push(NULL); // using NULL as an indicator for end of one level
		int cnt = 0;
		while (!q.empty())
		{
			Node *temp = q.front();
			q.pop();
			if (temp == NULL) //-> purana level complete traversal ho chuka hai
			{
				cnt++;
				if (!q.empty())
					q.push(NULL);
			}
			else
			{
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
		}
		return cnt;
	} // time complexity O(N) (N is no of nodes in binary tree) space complexity - O(N) as the maximum space will be occupied when all the nodes of last level are in q which will be dependant on (N) in worst case (N+1/2)
};

int main()
{

	return 0;
}