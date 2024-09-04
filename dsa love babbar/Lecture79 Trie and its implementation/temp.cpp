/*

*/

#include <iostream>
using namespace std;

class node
{
        public:
        int data;
        node(int data)
        {
                this->data = data;
        }
};

int main()
{
        node *ptr = new node(34);
        node *prt = ptr;
        prt->data = 45;
        cout<< ptr->data << endl;
        return 0;
}