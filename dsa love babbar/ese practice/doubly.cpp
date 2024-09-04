/*

*/

#include <iostream>
using namespace std;

class node
{
public:
        int data;
        node *next;
        node *prev;
        node()
        {
                data = -1;
                next = prev = NULL;
        }
        node(int data)
        {
                this->data = data;
                this->next = this->prev = NULL;
        }
        ~node()
        {
                this->data = -1;
                this->next = this->prev = NULL;
        }
};

void addAtBeggining(node *&head, int data)
{
        node *newNode = new node(data);
        if (head == NULL)
        {
                head = newNode;
                return;
        }
        else
        {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
        }
}

void addAtEnd(node *&head, int data)
{
        node *newNode = new node(data);
        if (head == NULL)
        {
                head = newNode;
                return;
        }
        else
        {
                node *prevNode = head;
                while (prevNode->next != NULL)
                {
                        prevNode = prevNode->next;
                }
                prevNode->next = newNode;
                newNode->prev = prevNode;
        }
}

void deleteNode(node *&head, int data)
{
        if (head == NULL)
        {
                cout << "No node to delete!" << endl;
                return;
        }
        else if (data == head->data)
        {
                node *temp = head;
                head = head->next;
                delete temp;
        }
        else
        {
                node *prevNode = head;
                while (prevNode->next->data != data)
                {
                        prevNode = prevNode->next;
                }
                node *nodeToDelete = prevNode->next;
                prevNode->next = nodeToDelete->next;
                nodeToDelete->next->prev = prevNode;
                delete nodeToDelete;
                return;
        }
}

int main()
{

        return 0;
}