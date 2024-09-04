// https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor with value initialization
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }

    // Default constructor
    ListNode()
    {
        this->val = 0; // Optional, can initialize to 0 or some other default value
        this->next = nullptr;
    }

    // Constructor with value and next node initialization
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

void addAtEnd(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(ListNode *&head, int value)
{
    ListNode *current = head;
    ListNode *previous = nullptr;

    // If the node to be deleted is the head node
    if (current != nullptr && current->val == value)
    {
        head = current->next;
        delete current;
        return;
    }

    // Search for the node to be deleted
    while (current != nullptr && current->val != value)
    {
        previous = current;
        current = current->next;
    }

    // If the node was not found
    if (current == nullptr)
    {
        return;
    }

    // Node found; unlink it from the list
    previous->next = current->next;
    delete current;
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

class Solution
{
public:
    pair<Node *, Node *> splitList(struct Node *head)
    {
        // code here
        if (!head || !head->next)
            return {head, NULL};
        // for even f->n->n == head -> try dry running on linked list
        // for odd f->n = head;
        Node *fast = head;
        Node *slow = head;
        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // if f->n->n = head then we should move fast 1 step further
        if (fast->next->next == head)
            fast = fast->next;
        // head1 will be head and head2 will be slow->n
        Node *head1 = head;
        Node *head2 = slow->next;
        // making both curcular again
        slow->next = head1;
        fast->next = head2;
        // pair<Node* , Node*> p = {head1, head2};
        return {head1, head2};
    }
};

int main()
{
    ListNode *head = nullptr;

    addAtEnd(head, 1);
    addAtEnd(head, 2);
    addAtEnd(head, 3);
    addAtEnd(head, 4);

    cout << "List after deleting node with value 2: ";
    printList(head);

    return 0;
}
