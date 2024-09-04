class Solution
{
public:
	// function to merge two lists
	void merge(ListNode *&h1, ListNode *&h2)
	{
		ListNode *dumy = new ListNode(0);
		ListNode *prv = dumy;
		while (h1 && h2)
		{
			if (h1->val > h2->val)
			{
				prv->next = h2;
				h2 = h2->next;
			}
			else
			{
				prv->next = h1;
				h1 = h1->next;
			}
			prv = prv->next;
		}
		if (!h1)
			prv->next = h2;
		else
			prv->next = h1;
		h1 = dumy->next;
	}
	ListNode *sortList(ListNode *head)
	{
		if (!head || !head->next)
			return head;
		ListNode *sl = head;
		ListNode *f = head;
		while (f->next && f->next->next)
		{
			sl = sl->next;
			f = f->next->next;
		}
		ListNode *h1 = head;
		ListNode *h2;
		h2 = sl->next;
		sl->next = NULL;
		h1 = sortList(h1);
		h2 = sortList(h2);
		merge(h1, h2);
		return h1;
	}
    // time complexity = O(nlogn)
    // space complexity = O(logn)
    // for recursion stack 
};