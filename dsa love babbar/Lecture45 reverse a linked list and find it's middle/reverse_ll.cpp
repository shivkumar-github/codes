// https://leetcode.com/problems/reverse-linked-list/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *tempnxt = NULL;
        head->next = NULL; // why it is error when this line included
        while (curr != NULL)
        {
            tempnxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempnxt;
        }
        return prev;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// recursive solution 1
class Solution
{
public:
    void solve(ListNode *&head, ListNode *curr, ListNode *prev)
    {

        // base case
        // if curr is NULL then the previous is last node which will be our new head
        if (curr == NULL)
        {
            head = prev;
            return;
        }

        // first reverse the further list
        solve(head, curr->next, curr);
        // then point the next pointer of curr to prev
        curr->next = prev;
    }

    ListNode *reverseList(ListNode *head)
    {
        solve(head, head, NULL);
        return head;
    }
};
// recursive solution 2
class Solution
{
public:
    ListNode *solve(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        { // if list is empty or contains only one node then return head
            return head;
        }

        ListNode *smallHead = solve(head->next); // head of reversed of remaining linked list will be the head of reversed whole linked list
        head->next->next = head;                 // pointing the next pointer of next node to this current head
        head->next == NULL;                      // It is neccessary to point next pointer of current node(head) or while backtracking it will change the previous node of curr node in reversed linked list
        // for example in image provided in notes if we don't point next of node4 to null then while solving case of node3 the node5 (head->next->next for node3) will be equated to node3(i.e. head) hence will cause the problem
        // to understand better dry run the code using recursion tree and see what happens when you dont write this statement
        return smallHead;
    }
    ListNode *reverseList(ListNode *head)
    {
        head = solve(head);
        return head;
    }
};

int main()
{
    return 0;
}