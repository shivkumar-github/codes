/*
Understanding doubly linked list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;
    Node(int data)
    {
        this->data = data;
    }
    ~Node()
    {
        cout << "node with data " << this->data << " is deleted and all its pointer are removed." << endl;
        next = NULL;
        prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// while inserting, deleting node it is neccessary to manage all pointers correctly
void insertAtHead(Node *&head, Node *&tail, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = tail = temp;
    }
    else
    {
        // creating new node
        Node *temp = new Node(d);
        // update pointers of temp and head
        temp->next = head;
        head->prev = temp;
        // update head
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = tail = temp;
    }
    else
    {
        // creating new node
        Node *temp = new Node(d);
        // update pointers of temp and tail
        temp->prev = tail;
        tail->next = temp;
        // update tail
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // node previous to node which is to be deleted
    Node *previousNode = head;
    // if head is to be deleted
    if (position == 1)
    {
        head = head->next;
        delete previousNode;
    }
    // mid or tail
    else
    {
        // iterator which will take previous node to actual previous node
        int itr = position - 2;
        while (itr--)
        {
            previousNode = previousNode->next;
        }
        // storing node to be deleted
        Node *nodeToDelete = previousNode->next;
        // adjusting pointers
        previousNode->next = nodeToDelete->next;
        if (nodeToDelete->next == NULL) // agar tail delete kiya to tail ko update bhi karao
            tail = previousNode;
        else // have to add this condition because if node to be deleted = tail then previous-> next = NULL and hence we can not access prev for a null
            nodeToDelete->next->prev = previousNode;
        // now delete the node
        delete nodeToDelete;
    }
}

int main()
{
    Node *node1 = new Node(12);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 23);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 34);
    print(head);
    deleteNode(4, head, tail);
    deleteNode(3, head, tail);
    deleteNode(1, head, tail);
    deleteNode(1, head, tail);
    print(head);
    // cout << head->data << endl;
    // cout << tail->data << endl;
    return 0;
}

/*

*/