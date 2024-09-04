// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include <iostream>
using namespace std;
void dbg(auto i) { cout << i << endl; }
struct Node
{
	int data;
	struct Node *next;
	struct Node *bottom;

	Node(int x)
	{
		data = x;
		next = NULL;
		bottom = NULL;
	}
};

void insertAtEnd(Node *&head, int val)
{
	Node *nNode = new Node(val);
	if (!head)
	{
		head = nNode;
		return;
	}
	Node *t = head;
	while (t->next)
	{
		t = t->next;
	}
	t->next = nNode;
}

void insertAtBottom(Node *&head, int baseval, int val)
{
	Node *nNode = new Node(val);
	if (!head)
	{
		head = nNode;
		return;
	}
	Node *t = head;
	while (t->data != baseval)
	{
		t = t->next;
	}
	while (t->bottom)
	{
		t = t->bottom;
	}
	t->bottom = nNode;
}

void printList1(Node *root)
{
	while (root)
	{
		std::cout << root->data << " ";
		root = root->next;
	}
	std::cout << std::endl;
}
void printList(Node *root)
{
	while (root)
	{
		std::cout << root->data << " ";
		root = root->bottom;
	}
	std::cout << std::endl;
}
// class Solution
// {
// public:
// 	// in this approach we are  firstly making linked list
// 	void merge(Node *&head)
// 	{
// 		Node *p = head;
// 		Node *l1 = head->next;
// 		Node *l2 = head->bottom;
// 		head->bottom = NULL;
// 		int cnt = 0;
// 		while (l1 && l2)
// 		{
// 			if (cnt == 0)
// 				printList1(head);
// 			if (l2->data < l1->data)
// 			{
// 				p->next = l2;
// 				Node *n2 = l2->bottom;
// 				l2->bottom = NULL;
// 				l2->next = l1;
// 				l2 = n2;
// 				p = p->next;
// 			}
// 			else
// 			{
// 				p = p->next;
// 				l1 = l1->next;
// 			}
// 			cnt++;
// 		}
// 		if (!l1)
// 		{
// 			p->next = l2;
// 		}
// 	}
//
// 	Node *flatten(Node *root)
// 	{
// 		// Your code here
// 		Node *cr = root;
// 		Node *ncr = cr->next;
// 		while (cr)
// 		{
// 			merge(cr);
// 			cr = ncr;
// 		}
// 		cr = root;
// 		while (cr)
// 		{
// 			cr->bottom = cr->next;
// 			cr = cr->next;
// 		}
// 		return root;
// 	}
// };
// class Solution
// {
// public:
// // in this approach we are tyring to form a ll directly with bottom pointers but
// 	// this approach looses the bottom pointers of next nodes so it can't be applied
// 	void merge(Node *&head)
// 	{
// 		Node *p = head;
// 		Node *l1 = head->next;
// 		Node *l2 = head->bottom;
// 		int cnt = 0;
// 		while (l1 != NULL & l2 != NULL)
// 		{
// 			l2 = p->bottom;
// 			p->bottom = p->next;
// 			if (l2->data < l1->data)
// 			{
// 				p->bottom = l2;
// 				Node *b2 = l2->bottom;
// 				l2->bottom = l1;
// 				l2 = b2;
// 				p = p->bottom;
// 			}
// 			else
// 			{
// 				p = p->bottom;
// 				l1 = l1->next;
// 			}
// 			cnt++;
// 		}
// 		if (!l1)
// 		{
// 			p->next = l2;
// 		}
// 	}
//
// 	Node *flatten(Node *root)
// 	{
// 		// Your code here
// 		Node *cr = root;
// 		while (cr)
// 		{
// 			merge(cr);
// 			cr = cr->next;
// 		}
// 	}
// };
int cnt = 0;
class Solution
{
public:
	// It is nothing but merging liked list 1st is the main and second ll is the sub linked list
	Node *merge(Node *list1, Node *list2)
	{
		if (!list1)
			return list2;
		if (!list2)
			return list1;
		Node *dmy = new Node(0);
		dmy->bottom = list1;
		Node *p = dmy;
		while (list1 && list2)
		{

			if (list1->data > list2->data)
			{
				p->bottom = list2;
				Node *b2 = list2->bottom;
				list2->bottom = list1;
				p = p->bottom;
				list2 = b2;
			}
			else
			{
				p = p->bottom;
				list1 = list1->bottom;
			}
		}
		if (!list1 && list2)
		{
			p->bottom = list2;
		}
		list1 = dmy->bottom;
		delete dmy;
		return list1;
	}

	// recursion
	Node *flatten(Node *root)
	{
		// base case
		if (!root->next)
		{
			root->next = root->bottom;
			return root;
		}
		// Your code here
		Node *b = root->bottom;
		root->next = flatten(root->next);
		root = merge(root, root->next);
		// root->bottom = flatten(root->next); // we should not do this as the main linked list is not sorted so we have to keep the root and its sublist intact and merge it with root->next
		// root->bottom = merge(root->bottom, b);
		return root;
	}
};

int main()
{
	Node *head = NULL;

	// Creating the linked list as shown in the example
	insertAtEnd(head, 5);
	insertAtEnd(head, 10);
	insertAtEnd(head, 19);
	insertAtEnd(head, 28);

	insertAtBottom(head, 5, 7);
	insertAtBottom(head, 5, 8);
	insertAtBottom(head, 5, 30);

	insertAtBottom(head, 10, 20);

	insertAtBottom(head, 19, 22);
	insertAtBottom(head, 19, 50);

	insertAtBottom(head, 28, 35);
	insertAtBottom(head, 28, 40);
	insertAtBottom(head, 28, 45);
	Solution s;
	head = s.flatten(head);
	printList(head);

	return 0;
}