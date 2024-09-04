/*
forming first node
*/

#include <iostream>
using namespace std;

// creating node class
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        this ->next = NULL;
        cout<< "Node deleted and memory is free now . " << endl;
    }
};

void insertAtHead(Node *&head, int d) // why & and * are used together
{
    // new node
    Node *temp = new Node(d); // new node ko dynamically create kiya jo data d ko store karva rahi hai
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL) // NULL is typically used to indicate that a pointer does not point to a valid memory location.
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    Node *temp = head;
    int cnt = 1;
    Node *nodeToInsert = new Node(d);

    // edge case
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    } // --> to update tail at temp (if we are inserting node at last position it is not required but then tail will not be updated and later if we try to insert at tail then it will get inserted after old tail)

    // creating a node for d
    // new node ke next ko jo pehle position pe tha uske location ko store karva liya
    nodeToInsert->next = temp->next;
    // position ke pehle vale node ke next ko new inserted node ke address ke equal kara diya
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    // deleting first node
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else{
    // deleting any middle or last node
    Node *previousNode = head;
    while ((position--) > 2) // position > 2 and then position--
    {
        previousNode = previousNode->next;
    }
    previousNode->next = previousNode->next->next; // temp-> next = current-> next in 
    Node* temp = previousNode->next;
    temp ->next = NULL; //why this line is giving problem and though tail is deleted the value 22 is shown in ouptut
    delete temp;
    }
}

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22); // is position pe insert kar do
    print(head);


    deleteNode(1, head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl; 
    print(head);

    return 0;
}