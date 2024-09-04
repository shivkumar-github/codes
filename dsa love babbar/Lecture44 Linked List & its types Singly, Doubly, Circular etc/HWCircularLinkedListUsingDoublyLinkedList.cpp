/*
    Implement circular linked list using doubly linked list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    ~Node()
    {
        prev = NULL;
        next = NULL;
        cout << "Memory cleared for the node with data " << this->data << endl;
    }
};

void printList(Node *tail)
{
    // for empty list
    if (tail == NULL)
    {
        cout << "Your list is empty, please check again!" << endl;
        return;
    }

    // list is not empty
    else
    {
        Node *temp = tail;
        do // do while loop so that at least executed once
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail); // jabtak ghum ke vapas na aa jayein
    }
    cout << endl;
}

void insertNode(Node *&tail, int element, int data)
{
    // creating a node to insert
    Node *nodeToInsert = new Node(data);
    // storing node after which the new node will be inserted as it will be helpfull while adjusting the pointers
    Node *previousNode = tail;

    // if list is empty --> tail ko adjust karna padega
    if (tail == NULL)
    {
        tail = nodeToInsert;
        // tails ke pointers adjust karo
        tail->next = tail;
        tail->prev = tail;
        return;
    }
    else
    {
        // finding the previous node
        while (previousNode->data != element)
        {
            previousNode = previousNode->next;
        }
        // modifying pointers of nodeToInsert and previousNode
        nodeToInsert->next = previousNode->next;
        nodeToInsert->next->prev = nodeToInsert;
        previousNode->next = nodeToInsert;
        nodeToInsert->prev = previousNode;
    }
}

void deletNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "No node to delete! Kindly check your list again!" << endl;
        return;
    }

    Node *previousNode = tail;
    Node *nodeToDelete;

    // finding previous node
    while (previousNode->next->data != element)
    {
        previousNode = previousNode->next;
    }
    // next node of previous node is the node to be deleted
    nodeToDelete = previousNode->next;
    // adjusting two pointers and the pointers of node to be deleted will be nullified by the constructor we have written which will be called when we use delete keyword
    previousNode->next = nodeToDelete->next;
    nodeToDelete->next->prev = previousNode;

    // if the tail node is being deleted we have to move tail (Doesnt matters on which node we move)
    if (nodeToDelete == tail)
    {
        // isme bhi do possibilities hai
        // sirf tail node hi bachi hai
        if (tail->next == tail && tail->prev == tail)
        {
            tail = NULL;
        }

        // aur bhi nodes hai
        else
        {
            tail = previousNode;
        }
    }
    delete nodeToDelete;
}

int main()
{
    Node *node1 = new Node(7);
    Node *tail = node1;
    tail->next = tail; // have to write this statement while initialising tail with non null value be otherwise tail-> next will remain null
    insertNode(tail, 7, 8);
    insertNode(tail, 8, 23);
    insertNode(tail, 8, 12);
    insertNode(tail, 23, 80);
    printList(tail);
    deletNode(tail,7);
    printList(tail);
    return 0;
}