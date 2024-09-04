#include <bits/stdc++.h>
void dbg(auto i)
{
	std::cout << i << std::endl;
}
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insertAtEnd(ListNode *&head, int val)
{
	ListNode *newNode = new ListNode(val);
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
		std::cout << temp->val << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

class Solution
{
public:
	// function to merge two lists
	void merge(ListNode *&h1, ListNode *h2)
	{
		// mistake rather than inserting nodes only in first linked list try to adjust pointers  
		ListNode *dumy = new ListNode(0); // dummy pointer to keep track of new head(newhead will be stored in it's next)
		ListNode *prv = dumy;// initialising prv with dummy to avoid cases when prv = null
		while (h1 && h2) // directly using h1 and h2 as indices
		{
			if (h1->val > h2->val)
			{// take h2 in linked list and move h2 pointer further
				prv->next = h2;
				h2 = h2->next;
			}
			else
			{ // take h1 in linked list and move h1 pointer further
				prv->next = h1;
				h1 = h1->next;
			}
			// update previous
			prv = prv->next;
		}
		 // insert remaining linked lists
		if (!h1)
			prv->next = h2;
		else
			prv->next = h1;
		// adjust h1 to new head (no need to adjust head2 as we are not using it further)
		h1 = dumy->next;
	}
	
	// sort without changing the data 
	ListNode *sortList(ListNode *head)
	{
		if (!head || !head->next)
			return head;
		ListNode *sl = head;
		ListNode *f = head->next;// start from next then only fast and slow exactly divide ll in half in both cases (when size of ll is even and odd)
		while (f && f->next)
		{
			sl = sl->next;
			f = f->next->next;
		}
		ListNode *h1 = head;
		ListNode *h2;
		h2 = sl->next;// head of second part
		sl->next = NULL; // break contact between two parts
		// sort
		h1 = sortList(h1);
		h2 = sortList(h2);
		// merge
		merge(h1, h2);
		return h1;
	}
	// if data changing is allowed (interviewer)
	ListNode *sortList1(ListNode *head){
		ListNode *temp = head;
		vector<int> arr;
		while(temp){
			arr.push_back(temp->val);
			temp = temp->next;
		}
		sort(arr.begin(), arr.end());
		temp = head;
		int ind = 0;
		while(temp){
			temp->val = arr[ind++];
			temp = temp->next;
		}
		return head;
	}
};

int main()
{
	ListNode *head = NULL;
	insertAtEnd(head, 4);
	insertAtEnd(head, 3);
	insertAtEnd(head, 2);
	insertAtEnd(head, 1);
	printList(head);
	Solution s;
	head = s.sortList1(head);
	printList(head);
	return 0;
}