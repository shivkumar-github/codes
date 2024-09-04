// https://leetcode.com/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> visited;
        ListNode* temp = head;
        while(temp){
            // if not visited then "[]" automatically initialises it with 0 value
            // if value is 0 then it is not visited then change it's value to true
            if(!visited[temp])   visited[temp] = true;
            else // visited before i.e. it is our answer
                return temp;
            temp = temp-> next;
        }
        // if temp becomes null the loop breaks then no cycle is present
            return NULL;
    }

    // approach 2 by floyds method
     ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;        
        ListNode* slow = head;
        bool isLoop = false;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                isLoop = true;
                break;
            }
        }
        if(isLoop){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        else// no cycle is present
            return NULL;
        return NULL;
    }
};