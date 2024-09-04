/*
https://leetcode.com/problems/middle-of-the-linked-list/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    //     ListNode* middleNode(ListNode* head) {
    //         int cnt = 0;
    //         ListNode* temp = head;
    //         while(temp){
    //             temp = temp->next;
    //             cnt++;
    //         }
    //         if(cnt%2)
    //             cnt +=1;
    //         else
    //             cnt+=2;
    //         int nodenum = cnt / 2;
    //         temp = head;
    //         while(nodenum>1){
    //             temp = temp->next;
    //             nodenum--;
    //         }
    //         return temp;
    //     }

    // approach 2 :
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *faster = head->next;
        ListNode *slower = head;
        while (faster)
        {
            faster = faster->next;
            if (faster)
                faster = faster->next;
            slower = slower->next;
        }
        return slower;
    }
};

int main()
{

    return 0;
}