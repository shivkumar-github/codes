/*
learning circular linked list
*/

#include <iostream>
using namespace std;

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
    ~Node()
    {
        int value = this->data;
        this->next = NULL;
        cout << "memory is free for node with data " << value << endl;
    }
};
// in circular linked list we don't need head we need only tail with which we can access both
void insertNode(Node *&tail, int element, int d) // is data ke age nayi node laga do
{
    // assuming that the element is present in the list
    // creating a new node
    Node *newNode = new Node(d);

    // if list is empty
    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    // Non empty list
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // now curr is the node that represent the element
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deleteNode(Node *&tail, int element)
{
    // list empty hai
    if (tail == NULL)
    {
        cout << "The list is empty, please check again ! " << endl;
        return;
    }
    // non empty list
    else
    {
        // single element list
        if (tail->next == tail)
        {
            Node *temp = tail;
            tail = NULL;
            delete temp;
            return;
        }
        // multiple elements are there
        else
        {
            Node *previousNode = tail; // we have to find previous node so that it's pointer which is pointing towards the node which is to be deleted is to be removed
            while (previousNode->next->data != element)
            {
                previousNode = previousNode->next;
            }

            Node *nodeToDelete = previousNode->next;
            // if we want to delete tail
            if (nodeToDelete == tail) // agar tail vale Node ko delete kar rahe ho tail ko update karna padeg
            {
                tail = previousNode; // it doesn't matters which element you point the tail to as this is a circular linked list
            } // alternate solution is present in practice file
            previousNode->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }
}
void printList(Node *tail)
{
    Node *temp = tail;
    // if the list is empty then we can not do temp-> data = NULL-> data which will throw error that's why we have to add special case
    if (tail == NULL)
    {
        cout << "your list is empty !" << endl;
        return;
    }
    // do while loop is used to include cases when list has only single element
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    printList(tail);

    insertNode(tail, 3, 7);
    printList(tail);

    // insertNode(tail, 7, 22);
    // printList(tail);

    // insertNode(tail, 22, 10);
    // printList(tail);

    // insertNode(tail, 7, 14);
    // printList(tail);

    deleteNode(tail, 7);
    printList(tail);

    return 0;
}

// done whole lecture