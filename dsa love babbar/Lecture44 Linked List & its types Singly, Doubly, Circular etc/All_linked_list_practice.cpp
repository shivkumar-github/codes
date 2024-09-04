// /*
//   singly linkded list
// */

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         next = NULL;
//     }
//     ~Node()
//     {
//         cout << "pointer removed from next node of node containing data : " << this->data << endl;
//         this->next = NULL;
//     }
// };
// void printList(Node *&head)
// {

//     if (head == NULL)
//     {
//         cout << "List is empty " << endl;
//         return;
//     }
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     // when list is empty
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = tail = temp;
//     }

//     // if not empty list
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head;
//         head = temp;
//     }
// }

// void insertAtTail(Node *&head, Node *&tail, int d)
// {
//     // empty list
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         head = tail = temp;
//     }
//     // else if list not empty
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp;
//     }
// }

// void insertAtposition(int position, Node *&head, Node *&tail, int d)
// {
//     if (position == 1)
//     {
//         insertAtHead(head, tail, d);
//         return;
//     }
//     Node *temp = new Node(d);
//     temp = head;
//     int itr = position - 2;
//     while (itr--)
//     {
//         temp = temp->next;
//     }
//     if (temp->next == NULL)
//     {
//         insertAtTail(head, tail, d);
//         return;
//     }
//     else
//     {
//         Node *nodeToInsert = new Node(d);
//         nodeToInsert->next = temp->next;
//         temp->next = nodeToInsert;
//     }
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {
//     Node *previousNode = head;
//     if (position == 1)
//     {
//         head = head->next;
//         delete previousNode;
//         return;
//     }
//     else
//     {
//         int itr = position-2;
//         while (itr--)
//         {
//             previousNode = previousNode->next;
//         }

//         Node *curr = previousNode->next; // the node which is to be deleted
//         previousNode->next = curr->next;
//         delete curr;
//     }
// }

// int main()
// {
//     Node *node1 = new Node(12);
//     Node *head = node1;
//     Node *tail = node1;
//     insertAtHead(head, tail, 32);
//     insertAtHead(head, tail, 76);
//     insertAtTail(head, tail, 17);
//     insertAtTail(head, tail, 7);
//     insertAtposition(1, head, tail, 43);
//     printList(head);
//     deleteNode(1,head,tail);
//     printList(head);
//     return 0;
// }

// /*
//     doubly linked list
// */

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next = NULL;
//     Node *prev = NULL;
//     Node(int data)
//     {
//         this->data = data;
//     }
//     ~Node()
//     {
//         cout<< "node with data " << this->data << " is deleted and all its pointer are removed." << endl;
//         next = NULL;
//         prev = NULL;
//     }
// };

// void printList(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     if (head == NULL)
//     {
//         head = tail = temp;
//         return;
//     }
//     else
//     {
//         // update pointers of temp and head
//         temp->next = head;
//         head->prev = temp;
//         // update head
//         head = temp;
//     }
// }

// void insertAtTail(Node *&head, Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     if (tail == NULL)
//     {
//         tail = head = temp;
//         return;
//     }
//     else
//     {
//         tail->next = temp;
//         temp->prev = tail;
//         tail = temp;
//     }
// }

// void insertAtposition(int position, Node *&head, Node *&tail, int d)
// {
//     // head pe insert
//     if (position == 1)
//     {
//         insertAtHead(head, tail, d);
//         return;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         int itr = position - 2;
//         while (itr--)
//         {
//             temp = temp->next;
//         }
//         // tail pe insert
//         if (temp->next == NULL)
//         {
//             insertAtTail(head, tail, d);
//             return;
//         }
//         // mid
//         else
//         {
//             // creating new node
//             Node *nodeToInsert = new Node(d);
//             // adjusting pointers
//             nodeToInsert->next = temp->next;
//             nodeToInsert->prev = temp;
//             temp->next->prev = nodeToInsert;
//             temp->next = nodeToInsert;
//         }
//     }
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {
//     // node previous to node which is to be deleted
//     Node *previousNode = head;
//     // if head is to be deleted
//     if (position == 1)
//     {
//         head = head->next;
//         delete previousNode;
//     }
//     // mid or tail
//     else
//     {
//         // iterator which will take previous node to actual previous node
//         int itr = position - 2;
//         while (itr--)
//         {
//             previousNode = previousNode->next;
//         }
//         // storing node to be deleted
//         Node *nodeToDelete = previousNode->next;
//         // adjusting pointers
//         previousNode->next = nodeToDelete->next;
//         if (nodeToDelete->next == NULL) // agar tail delete kiya to tail ko update bhi karao
//             tail = previousNode;
//         else // have to add this condition because if node to be deleted = tail then previous-> next = NULL and hence we can not access prev for a null
//             nodeToDelete->next->prev = previousNode;
//         // now delete the node
//         delete nodeToDelete;
//     }
// }

// int main()
// {
//     Node *node1 = new Node(12);
//     Node *head = node1;
//     Node *tail = node1;
//     insertAtHead(head, tail, 23);
//     insertAtHead(head, tail, 90);
//     insertAtTail(head, tail, 34);
//     printList(head);
//     deleteNode(4, head, tail);
//     deleteNode(3,head,tail);
//     deleteNode(1,head,tail);
//     deleteNode(1,head,tail);
//     printList(head);
//     // cout << head->data << endl;
//     // cout << tail->data << endl;
//     return 0;
// }

/* Circular linked list */

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
    }
    ~Node()
    {
        this->next = NULL;
        cout << "Memory has been freed for the node " << this->data << endl;
    }
};

void printList(Node *tail)
{

    Node *temp = tail;

    // if the list is empty
    if (tail == NULL)
    {
        cout << "Your list is empty, kindly check again!" << endl;
        return;
    }

    // if the list is non empty
    // cout<< temp->data << endl;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail); // do while loop because block of code is neccessary to be executed atleast once
    cout << endl;
}

void insertNode(Node *&tail, int element, int data)
{ // for the case when the list is empty and tail = NULL and hence independent of the element
    Node *nodeToInsert = new Node(data);
    Node *previous = tail; // new node iss element ke node ke aage lagani hai

    // if list is empty
    if (tail == NULL)
    {
        tail = nodeToInsert;
        tail->next = tail;
        return;
    }
    // if list is non empty
    while (previous->data != element)
    {
        previous = previous->next;
    }
    nodeToInsert->next = previous->next;
    previous->next = nodeToInsert;
}

void deleteNode(Node *&tail, int d)
{
    // agar list empty hai to
    if (tail == NULL)
    {
        cout << "Your list is empty, please check again!" << endl;
        return;
    }

    // agar empty list nahi hai to
    Node *previousNode = tail; // have to find previous node to remove it's pointer from next node which is to be deleted
    // cout<< nodeToDelete->data << endl;
    while (previousNode->next->data != d)
    {
        previousNode = previousNode->next;
    }
    Node *nodeToDelete = previousNode->next;
    previousNode->next = nodeToDelete->next;

    // agar jo node delete kar rahe hai vo tail hai to tail ko update karna padega
    if (nodeToDelete == tail)
    {
        previousNode = tail;
        
        // if single node in the list is being deleted
        if (tail->next == tail)
        {
            tail = NULL; // have to make tail = NULL if single element is being deleted then while printing it will give error
        }                // tail ko null banana delete ki zimedari hai  na ki print ki
    }

    delete nodeToDelete;
}

int main()
{
    Node *node1 = new Node(5);
    Node *tail = NULL;
    // tail->next = tail; // have to comment it out while taking tail = NULL
    insertNode(tail, 987, 3);
    insertNode(tail, 3, 8);
    insertNode(tail, 8, 11);
    insertNode(tail, 8, 47);
    insertNode(tail, 3, 54);

    deleteNode(tail, 11);
    deleteNode(tail, 54);
    deleteNode(tail, 8);
    deleteNode(tail, 47);
    deleteNode(tail, 3);
    printList(tail);
    return 0;
}


/*
circular Linked using doubly linked list is not written here as it is done by myself as HW list is not written here 
*/