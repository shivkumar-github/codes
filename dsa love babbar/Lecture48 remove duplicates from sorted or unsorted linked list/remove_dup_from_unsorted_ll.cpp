/*
https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
    public:
    // approach 1 using map
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_map<int, int>mp;
        Node* temp = head;
        Node* prev = NULL;
        while(temp){
            // 1st case when the element is repeated
            // if mp[temp] != 0 then the node is repeating
            if(mp[temp->data] != 0) {
                // cout << temp->data << endl;
                if(temp == head){
                    head = head->next;
                }
                else{
                    prev->next = temp->next;
                }
                temp = temp->next;
            }
            else{
                mp[temp->data]++;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
	// approach 2 by sorting first and then removing 
};
// Function to insert a new node at the end of the linked list

int main() {
    Node* head = nullptr;
    // Insert nodes at the end
    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // printList(head);
	Solution s;
    head = s.removeDuplicates(head);
    cout << "hello" << endl;
    printList(head);
    return 0;
}