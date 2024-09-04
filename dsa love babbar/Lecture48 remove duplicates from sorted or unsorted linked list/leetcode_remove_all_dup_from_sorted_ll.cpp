// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = curr->next;
		// deleting the first of duplicates
        // while(curr && nxt){
        //     if(curr->val == nxt->val){                
        //         curr->next = nxt->next;
        //         nxt = nxt->next;
        //     }
        //     else{
        //     curr = nxt;
        //     nxt = nxt->next;
        //     } 
        // }

		// or deleting the second of duplicates
		while(curr && nxt){
            if(curr->val == nxt->val){                
                if(prev){
                    prev->next = nxt;
                }
                if(head == curr)
                    head = nxt;
                curr->next = NULL;
            }
            if(curr->val != nxt->val)
                prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        return head;
    }
};