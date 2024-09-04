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
#include<vector>
class Solution {
public:
    // bool is(vector<int> ans){
    //     int s = 0;
    //     int e = ans.size()-1;
    //     while(s <= e){
    //         if(ans[s++]!=ans[e--])
    //             return false;
    //     }
    //     return true;
    // }
    // bool isPalindrome(ListNode* head) {
    //     vector<int> arr;
    //     ListNode* t = head;
    //     while(t){
    //         arr.push_back(t->val);
    //         t = t->next;
    //     }
    //     return is(arr);
    // }
    // // space copmlexity = O(n)
    // // time complexity = O(n)
    
    // approach 2 find middle reverse and then compare 
    
    void reverse(ListNode*& head){
        if(!head || !head->next) 
            return;
        ListNode* prv = NULL;
        ListNode* cr = head;
        ListNode* n = head->next;
        while(cr){
            cr->next = prv;
            prv = cr;
            cr = n;
            if(n)
                n = n->next;
        }
        head = prv;
    }
    
     bool isPalindrome(ListNode* head) {
         // adding edge case
         if(!head || !head->next)
             return head;
         ListNode* s = head;
         ListNode* f = head->next;
         while(f->next && f->next ->next){
             s = s->next;
             f = f->next->next;
         }
         // divide in half
         ListNode* head2;
         if(!f->next){// even
            head2 = s ->next;             
         }
         else{ // odd
             head2 = s->next ->next;// skip one middle node
         }
         // for correct reversal operation nullify the next pointer of slow (end of first list)
         s->next = NULL;
         reverse(head);
         while(head && head2){
             if(head->val != head2->val){
                 return false;
             }
             head = head->next;
             head2 = head2 ->next;
         }
         return true;
     }// sc = O(1)
	//  tc = O(N)
};