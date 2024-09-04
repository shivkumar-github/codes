/*

*/

#include <iostream>
using namespace std;

class node
{
public:
        int data;
        node *next;
        node()
        {
                this->data = -1;
                this->next == NULL;
        }
        node(int data)
        {
                this->data = data;
                this->next = NULL;
        }

};

void insertNode(node*& head, int el, int data){
        node *newNode = new node(data);
        if (head == NULL){
                head = newNode;
        }
        
        
}


int main()
{

        return 0;
}