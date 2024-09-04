/*

*/

#include <iostream>
using namespace std;

class node
{
        int data;
        node *next;
        node()
        {
                this->data = -1;
        }
        node(int data)
        {
                this->data = data;
                this->next = NULL;
        }
};

void addAtBeg(node *&head, int data)
{
        if (head == NULL)
        {
                head->data = data;
                return;
        }
        else
        {
                node *newNode = new node(data);
                newNode->next = head;
                head = newNode;
        }
}

void addAtEnd(node *&head, int data)
{
        node *newNode = new node(data);
        if (head == NULL)
        {
                head->data = data;
        }
        else
        {
                node *temp = head;
                while (temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = newNode;
        }
}

void searchModify(node *&head, int data)
{
        node *temp = head;
        while (temp->data != data && temp != NULL)
        {
                temp = temp->next;
        }
        int newData;
        cout << "Enter the modified value: " << endl;
        cin >> newData;
        temp->data = newData;
}

void deleteNode(node *&head, int data)
{
        if (head == NULL)
        {
                cout << "empty list!" << endl;
        }

        node *temp = head;
        if (head->data == data)
        {
                head = head->next;
                delete temp;
        }
        while (temp != NULL)
        {
                if (temp->next->data == data)
                {
                        node *nodeToDelete = temp->next;
                        temp->next = nodeToDelete->next;
                        delete nodeToDelete;
                }
                temp = temp->next;
        }
}

int searchList(node* head , int data){
        node *temp = head;
        int pos = 0;
        while (temp!=NULL)
        {
                if (temp->data == data)
                {
                        return pos;
                }
                temp = temp->next;
        }
        return -1;//important
}

int main()
{
        node *head = NULL;
        AddAtBeggining(head, 4);
        printList(head);
        AddAtBeggining(head, 6);
        printList(head);
        AddAtEnd(head, 79);
        printList(head);
        AddAtBeggining(head, 89);
        AddAtEnd(head, 118);
        printList(head);
        searchAndModify(head, 118);
        printList(head);
        cout << searchInList(head, 79) << endl;
        deleteNode(head, 79);
        cout << searchInList(head, 79) << endl;
        // in exam give menu driven options to the user w

        return 0;
}