// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// here the number are given in reversed order than leetcode

class Solution {
  public:
     void reverse(Node*& head){
        if(!head || !head->next) // handling edge cases
            return ;
        Node* pv = NULL;// pointing previous node
        Node* c =  head; // pointing current node
        Node* n ; 
        while(c){ // updating pointers
            n = c->next;
            c->next = pv;
            pv = c ;
            c = n;
        }
        // new head will be pv as c is NULL;
        head = pv;
    }
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
         Node* l1 = num1;
        Node* l2 = num2;
        
        if(!l1 || !l2)
            return l1?l1:l2; // return ll which is not null
        reverse(l1);
        reverse(l2);
        // nodes to traverse and check which linked list is smaller
        Node* t1 = l1;
        Node* t2 = l2;
        while(t1 && t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        // storign smaller and bigger ll
        Node* sm;
        Node* bg;
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
        Node* newhead = sm;
        // store the prev of newll to add extra nodes to our answer ll
        Node* p = NULL;
        int sum = 0;
        int cry = 0;
        while(sm && bg){
            sum = sm->data + bg->data + cry;
            cry = sum/10;
            sum %= 10;
            // store in smaller ll to avoid extra memory usage
            sm->data = sum;
            // maintaining prev
            p = sm;
            sm = sm ->next;
            bg = bg -> next;
        }
        // when 
        while(bg){
            sum = bg->data + cry;
            bg = bg->next;
            cry = sum/10;
            sum %= 10;
            Node* newNode = new Node(sum);
            p -> next = newNode;
            p = p->next;
        }// all addition is performed
        // if cry is remaining
        if(cry){
            Node* nN = new Node(cry);
            p->next = nN;
        }
        reverse(newhead);
        return newhead;
    }
};
