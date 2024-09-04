/*
https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node*& head) {
        // code here
        // just remove the loop without losing any nodes
        unordered_map<Node*, bool> visited;
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            // if a node has next pointer to head (the tail is pointing to head) then remove the loop and return 
            if(temp->next == head){
                temp->next = NULL;
                return;
            }
            // if node not visited before then mark it true
            if(visited[temp] == 0) {visited[temp] = true;}
            // else it is the node to which tail's next pointer is connected, remove the loop and return
            else{
                prev->next = NULL;
                return;
            }
			// update temp and prev after each iteration
            prev = temp;
            temp = temp->next;
        }
    }
    // approach 2 using floyds algo
      void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        Node* fast = head;
        Node* slow = head;
        bool isLoop = false;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                isLoop = true;
                break;
            }
        }
        // first check if loop exists or not
        if(!isLoop)
            return;
        slow = head;
        // if yes then find the node at which loop starts
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        // then start prev from start point and then countinue till you find prev node
        Node* prev = slow;
        while(prev->next != slow)
            prev = prev ->next;
        prev -> next = NULL;
    }// we can directly find previous node while finding the point of loop but in case where slow and fast meet at the point of loop that code won't work 
    // alternate approach (rather than first moving slow to the starting node of the loop and the counting till slow, we will put the pointer in the process of finding the node for loop)


    void removeLoop(Node* head) {
        Node* prev = NULL;
        Node* fast = head;
        Node* slow = head;
        bool isLoop = false;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
            if(fast == slow){
                isLoop = true;
                break;
            }
        }
        if(!isLoop)
            return;
        // special case in this approach when the fast and slow meet at head then the normal algo will not enter while loop
        if(slow == head){
            prev->next = NULL;
            return;
        }
        slow = head;
        // initiating prev with fast and storing previous pointer so as to access it later to remove the loop
        prev = fast;
        while(slow != fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev -> next = NULL;
    } // DOUBT: what are the other two ways
};
int main(){

return 0;
}