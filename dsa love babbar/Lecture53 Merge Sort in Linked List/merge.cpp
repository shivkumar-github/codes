/*
leetcode https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include <iostream>
using namespace std;

struct ListNode
{
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addAtEnd(ListNode *&head, int val)
{
	ListNode *nNode = new Node(val);
	if (!head)
	{
		head = nNode;
	}
	ListNode temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = nNode;
}

void printList(ListNode *head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

class Solution
{
public:
	// if data changing is not allowed
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		if (!list1 || !list2)
			return list1 ? list1 : list2;
		ListNode *dmy = new ListNode(0);
		dmy->next = list1;
		ListNode *p = dmy;
		while (list1 && list2)
		{
			if (list2->val < list1->val)
			{
				ListNode *n2 = list2->next;
				p->next = list2;
				list2->next = list1;
				list2 = n2;
				p = p->next;
			}
			else
			{
				list1 = list1->next;
				p = p->next;
			}
		}
		if (!list1 && list2)
		{
			p->next = list2;
		}
		list1 = dmy->next;
		dmy->next = NULL;
		delete dmy;
		return list1;
	}
};
