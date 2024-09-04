// https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void dbg(auto i) { cout << i << endl; }

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertAtEnd(ListNode *&head, int value)
{
	ListNode *newNode = new ListNode(value);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	ListNode *current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newNode;
}
void printList(ListNode *head)
{
	ListNode *current = head;
	while (current != nullptr)
	{
		cout << current->val << " ";
		current = current->next;
	}
	cout << std::endl;
}
class Solution
{
public:
	class Solution
{
public:
	// if data changing is not allowed
	// BEST SOLUTION :
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		if (!list1 || !list2)
			return list1 ? list1 : list2;
		ListNode *dmy = new ListNode(0);
		dmy->next = list1;// setting 1st linked as main and then inserting the nodes of second list according to increasing order
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
		if(!list1 && list2){
			p->next = list2;
		}
		list1 = dmy->next;
		dmy->next = NULL;
		delete dmy;
		return list1;
	}
};

	// if data changing is  allowed (using vector and linked list)
	ListNode *mergeTwoLists1(ListNode *list1, ListNode *list2)
	{
		if (!list1 || !list2)
			return (list1 ? list1 : list2);
		vector<int> arr;
		ListNode *t = list1;
		while (t)
		{
			arr.push_back(t->val);
			t = t->next;
		}
		t = list2;
		while (t)
		{
			arr.push_back(t->val);
			t = t->next;
		}
		sort(arr.begin(), arr.end());
		t = list1;
		ListNode *prv;
		int ind = 0;
		while (t)
		{
			t->val = arr[ind++];
			prv = t;
			t = t->next;
		}
		prv->next = list2;
		t = list2;

		while (t)
		{
			t->val = arr[ind++];
			t = t->next;
		}
		ListNode *head = list1;
		return head;
	}

	// by babbar
		ListNode *solve(ListNode *list1, ListNode *list2)
	{
		ListNode *c1 = list1;
		ListNode *n1 = c1->next;
		ListNode *c2 = list2;
		ListNode *n2 = c2->next;
		if (n1 == NULL)
		{
			c1->next = list2;
			return list1;
		}
		while (n1 != NULL && c2 != NULL)
		{
			if ((c2->val >= c1->val) && (c2->val <= n1->val))
			{ // if val of c2 is between c1 and n1 then place c2 there
				c1->next = c2;
				n2 = c2->next;
				c2->next = n1;
				// update pointers
				c1 = c2; // as now c2 is next to c1
				c2 = n2;
			}
			else
			{
				// move c1 and n1 further
				c1 = n1;
				n1 = n1->next;
                if(!n1) // for cases when element list2 is greater than all in list1 hence n1 = null but not c2 = null
                    c1->next = c2; // attach remaining linked list2 to linked list1
			}
		}
		return list1;
	}
	ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2)
	{
		if (!list1 || !list2)
			return (list1 ? list1 : list2);
		if (list1->val <= list2->val)
		{
			return solve(list1, list2);
		}
		else
		{
			return solve(list2, list1);
		}
	}
};
int main()
{
	ListNode *head1 = NULL, *head2 = NULL;
	// insertAtEnd(head1, 5);
	insertAtEnd(head1, 2);
	// insertAtEnd(head1, 4);
	insertAtEnd(head2, 1);
	// insertAtEnd(head2, 2);
	// insertAtEnd(head2, 4);
	Solution s;
	ListNode *ans = s.mergeTwoLists2(head1, head2);
	printList(ans);
	return 0;
}