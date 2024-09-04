#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free;
        this->next = NULL;

        cout << " memory is free for node with data " << value << endl;
    }
};

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int d) // why do we use & written at bottom of code
{
    // empty list
    if (head == NULL) // jab head null hai tab tail bhi null hi hoga kyunki list hi exist nahi karti
    {
        Node *temp = new Node(d);
        head = tail = temp;
    }

    // non empty list
    else
    {
        // new node create
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    // empty list->> head = NULL and tell = NULL if (tail == NULL)
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = tail = temp;
    }

    // non empty list
    else
    {
        // new node create
        Node *temp = new Node(d);
        tail->next = temp;
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

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head,Node*&tail)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        if (head == tail)
        {
            tail=NULL;
        }
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    // created a new node
    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    // head pointed to node1
    Node *head = node1; // when making head = tail = NULL --> empty linked list adjust the indices in insertion and deletion operation done after
    Node *tail = node1;
    // print(head);

    // insertAtTail(tail, head, 12);

    // print(head);

    // insertAtTail(tail, head, 15);
    // print(head);

    // insertAtPosition(tail, head, 4, 22); // have to make 3 instead of 4 while inserting in NULL list

    print(head);
    deleteNode(1,head,tail);
    // tail = NULL;
    cout<< tail << endl;
    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;

    // deleteNode(4, head); // have to make 3 instead of 4 while inserting in NULL list

    return 0;
}

/*
In arrays we pass pointer and when we change values stored at that location to which pointer is pointing
but here we don't want to change the value stored but we want to change the pointer itself
*/