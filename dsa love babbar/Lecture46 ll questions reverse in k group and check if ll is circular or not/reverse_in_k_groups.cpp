// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.

 */

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertAtBeginning(ListNode *&head, int value)
{
	ListNode *newNode = new ListNode(value);
	newNode->next = head;
	head = newNode;
}
void insertAtEnd(ListNode *&head, int value)
{
	ListNode *newNode = new ListNode(value);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	ListNode *temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
void printList(ListNode *head)
{
	ListNode *temp = head;
	while (temp != nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

class Solution
{
public:
	// recursive function which will solve the reversal
	ListNode *solve(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode *smHead = solve(head->next);
		head->next->next = head;
		head->next = NULL;
		return smHead;
	}

	// function which will accept data from main function and perform neccessary operation after reversal
	void reverse(ListNode *&head, ListNode *&start, int k)
	{
		int cnt = k;
		ListNode *temp = start;
		start = solve(start);
		if (temp == head)
		{
			head = start;
		}
	}

	// actual function
	// ListNode *reverseKGroup(ListNode *head, int k)
	// {
	// 	// to store the previous node of part which is going to be reversed
	// 	ListNode *prev = NULL;
	// 	ListNode *temp = head;
	// 	// to store the start of the part which is going to be reversed
	// 	ListNode *start = head;
	// 	int coutn = 0;
	// 	while (temp)
	// 	{
	// 		start = temp;
	// 		// if(coutn == 1){
	// 		// 	cout << "start" << start->val << endl;
	// 		// 	cout << "prev" << prev->val << endl;
	// 		// 	cout << "temp" << temp->val << endl;
	// 		// }
	// 		// count to check if the part has k nodes or not
	// 		int cnt = k;
	// 		// if(coutn==1)
	// 		// cout << temp->val;
	// 		while (temp && cnt-- > 1)
	// 		{
	// 			temp = temp->next;
	// 		}

	// 		// if the part has lesser nodes then terminate the loop without reversing
	// 		if (temp == NULL)
	// 			break;

	// 		// agar k nodes hai to reverse kardo
	// 		if (cnt == 0)
	// 		{
	// 			// storing next node to point it again after reversal of the part
	// 			ListNode *storeNxt = temp->next;

	// 			// freeing the next pointer of last node of the part for easy reversal
	// 			temp->next = NULL;

	// 			// storing the start for further operations
	// 			ListNode *tempstart = start;

	// 			// reversing the list and again storing it's first to our start
	// 			reverse(head, start, k);
	// 			// pointing the next(next pointer of last node in the part after revesrsal/which was starting node before reversal) to next node to the part which was reversed
	// 			tempstart->next = storeNxt;

	// 			// connecting the next pointer of previous node to start node of new reversed list
	// 			if (prev)
	// 			{
	// 				prev->next = start;
	// 			}
	// 			// adjusting prev for next iteration to tempstart which is last node of reversed part i.e. previous node for upcomming part
	// 			prev = tempstart;
	// 			temp = prev->next;
	// 			// updating temp for further iteration
	// 			coutn++;
	// 		}
	// 	}	// ListNode *reverseKGroup(ListNode *head, int k)
	// 	// returning head
	// 	return head;
	// }
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		// base case
		if (head == NULL)
		{
			return NULL;
		}
		ListNode *temp = head;
		int count = 1;
		// checking if there are k nodes or not
		while (temp->next)
		{
			temp = temp->next;
			count++;
		}
		// if lesser than k nodes are present then return the list as it is
		if (count < k)
			return head;
		// else reverse
		ListNode *prev = NULL;
		ListNode *curr = head;
		ListNode *tempnext = NULL;
		count = 0;
		// reversing first k nodes
		while (curr && count < k)
		{
			tempnext = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tempnext;
			count++;
		}
		// rest will be solved by recursion
		if (tempnext)
			head->next = reverseKGroup(tempnext, k);

		// return head of the reversed linked list
		return prev;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
	Solution s;
	head = s.reverseKGroup(head, 3);
	printList(head);
	return 0;
}
