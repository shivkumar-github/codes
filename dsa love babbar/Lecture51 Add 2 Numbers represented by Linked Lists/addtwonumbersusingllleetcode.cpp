// https://leetcode.com/problems/add-two-numbers/
#include <iostream>
using namespace std;

class Solution {
public:
    // function to reverse linked list (usefull when numbers are given reversed )
    void reverse(ListNode*& head){
        if(!head || !head->next) // handling edge cases
            return ;
        ListNode* pv = NULL;// pointing previous node
        ListNode* c =  head; // pointing current node
        ListNode* n ; 
        while(c){ // updating pointers
            n = c->next;
            c->next = pv;
            pv = c ;
            c = n;
        }
        // new head will be pv as c is NULL;
        head = pv;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)
            return l1?l1:l2; // return ll which is not null
        
        // nodes to traverse and check which linked list is smaller
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1 && t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        // storing smaller and bigger ll
        ListNode* sm;
        ListNode* bg;
        // assign value of head of smaller linked list ( we need smaller linked list to store result as working of our algo)
        if(!t1){ // t1 is smaller
            sm = l1;
            bg = l2;
        }
        else{ // t2 is smaller
            sm = l2;
            bg = l1;
        }
        // storing new head 
        ListNode* newhead = sm;
        // store the prev of newll to add extra nodes to our answer ll
        ListNode* p = NULL;
        int sum = 0;
        int cry = 0;
        while(sm && bg){
            sum = sm->val + bg->val + cry;
            cry = sum/10;
            sum %= 10;
            // store in smaller ll to avoid extra memory usage
            sm->val = sum;
            // maintaining prev
            p = sm;
            sm = sm ->next;
            bg = bg -> next;
        }
        // when 
        while(bg){
            sum = bg->val + cry;
            bg = bg->next;
            cry = sum/10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            p -> next = newNode;
            p = p->next;
        }// all addition is performed
        // if cry is remaining
        if(cry){
            ListNode* nN = new ListNode(cry);
            p->next = nN;
        }
        return newhead;
    } // space complexity O(m-n)
	// time complexity O(m+n)

};