/*

*/

#include <iostream>
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
};
using namespace std;
int main()
{
	node *ptr = new node(3);
	ptr = ptr->next;
	if ((1>2) || ptr->next != nullptr)
		cout << "hello" << endl;
	return 0;
}