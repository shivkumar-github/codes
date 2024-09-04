//
void checkLoop(ListNode *head, bool &checkLoop, ListNode *&ans)
{
	checkLoop = false;
	// pointers to implement the algorithm
	ListNode *fast = head;
	ListNode *slow = head;

	// checking if both are null
	while (fast && fast->next)
	{
		// updating the pointers
		fast = fast->next->next;
		slow = slow->next;
		// The distance decreases by one because fast is gaining on slow.
		// If d was k initially, after one move d becomes k - 1.
		// When the fast pointer is d steps behind the slow pointer, it will meet the slow pointer in exactly d steps.
		// hence the loop is always detected at the first time when fast is ovetaking the slow
		// it is neccessary to update the fast and slow both before checking the condition otherwise it will not detect loop in the first time fast overtakes slow

		// checking if they are at same position
		if (slow == fast)
		{
			checkLoop = true;
			break;
		}
	}
	// if loop is present find the node from which loops starts
	if (checkLoop)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		// store the answer in ans var
		ans = slow;
		return;
	}
	// else loop is not present then return NULL
	else
	{
		ans = NULL;
	}
}