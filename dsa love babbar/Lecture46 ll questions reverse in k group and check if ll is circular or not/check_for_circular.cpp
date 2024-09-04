// https://leetcode.com/problems/linked-list-cycle/
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	// bool hasCycle(ListNode *head) {
	//     bool ans = false;
	//     if(head == NULL)
	//         return false;
	//     int val = head->val;
	//     ListNode* temp = head->next;
	//     while(temp){
	//         if(temp->val == val)
	//             ans = true;
	//         temp->val = val;
	//         temp = temp->next;
	//     }
	//     return ans;
	// }
	//     this approach is wrong as if two nodes have same value in a linked list then this approach will fail

	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast && fast->next) // in && if first condition is false then second is not checked and in || if first is true then also second condition is not checked
		{
			fast = fast->next;
			fast = fast->next;
			slow = slow->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}