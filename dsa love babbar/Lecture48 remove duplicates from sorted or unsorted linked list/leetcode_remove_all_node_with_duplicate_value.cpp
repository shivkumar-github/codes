// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = curr->next;
        // setting the value to INT_MIN
        int deleteval = INT_MIN;
        while(curr && nxt){
            // if both nodes have same value or the node has a duplicated value
                if(curr->val == nxt->val || curr->val == deleteval){
                    if(prev!= NULL) // for the other than curr = head cases
                        prev->next = nxt;
                    else // when curr is head
                        head = nxt;
                    // storing value to check further
                    deleteval = curr->val;
                    // updating the values (keeping prev at same pos if node is deleted)
                    curr = curr->next;
                    nxt = nxt->next;
            }
            else{
                // updation for non duplicate cases
                prev = curr;
                curr = nxt;
                nxt = nxt ->next;
            }
        }
        // for the case when curr is last node but needs to be deleted
        if(!nxt && curr->val == deleteval){
            // if prev is still null that means head also needs to be deleted(value of head is also duplicated)
            if(!prev)
                head = NULL;
            // else delete curr
            else
            prev->next = NULL;
        }
        return head;
    }
};