/*

*/

#include <iostream>
using namespace std;

void dbg(auto i)
{
	cout << i << endl;
}

class node
{
public:
	int val;
	node *next;
	node(int val)
	{
		this->val = val;
		this->next = NULL;
	}
	node()
	{
		this->next = NULL;
	}
	node(int val, node *&next)
	{
		this->val = val;
		this->next = next;
	}
};

void insertatend(node *&head, int val)
{
	if (head == nullptr)
	{
		head = new node(val);
		return;
	}
	node *t = head;
	while (t->next)
	{
		t = t->next;
	}
	t->next = new node(val);
}

void printList(node *head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// by updating data of nodes
void sort012(node *&head)
{
	// count them first
	node *temp = head;
	int cnt[3] = {0, 0, 0};
	while (temp)
	{
		cnt[temp->val]++;
		temp = temp->next;
	}
	// update the values accordingly
	int ind = 0;
	int crcnt = cnt[ind];
	temp = head;
	while (ind <= 2)
	{
		temp->val = ind;
		temp = temp->next;
		cnt[ind]--;
		if (cnt[ind] == 0)
		{
			ind++;
		}
	}
	cout << endl;
} // space complexity = O(1)
// space complexity = O(n)

// update the pointers inside the node
//  the approach uses  three pointers zero , one , two each to store nodes with respective value in linked list
//  first we store all values in respective linked list and then attach all three ll's
void sort012_ap2(node *&head)
{
	if (!head)
	{
		return;
	}
	node *z = new node(0); // three nodes for three linked list
	node *o = new node(0);
	node *t = new node(0);
	node *z1 = z; // temparory nodes to iterate over lls
	node *o1 = o;
	node *t1 = t;
	node *cr = head;
	while (cr)
	{
		if (cr->val == 0)
		{
			z1->next = cr;
			z1 = z1->next;
		}
		else if (cr->val == 1)
		{
			o1->next = cr;
			o1 = o1->next;
		}
		else
		{
			t1->next = cr;
			t1 = t1->next;
		}
		cr = cr->next;
	}
	z1->next = (o->next) ? (o->next) : (t->next);// for cases when there is no one
	o1->next = t->next;
	t1->next = NULL; // making next pointer of last node equal to null
	// adjusting head pointer
	head = z->next;
	// joining the three lists
}
// time complexity = O(n) 
// space complextity = O(1)

int main()
{
	node *head = NULL;
	int n;
	// cin >> n;
	// while (n--)
	// {
	// 	int temp;
	// 	cin >> temp;
	// 	insertatend(head, temp);
	// }
	/*
5
1 1 2 1 0

	*/
	insertatend(head, 1);
	insertatend(head, 1);
	insertatend(head, 2);
	insertatend(head, 1);
	insertatend(head, 0);
	// sort012(head);
	sort012_ap2(head);
	printList(head);
	return 0;
}