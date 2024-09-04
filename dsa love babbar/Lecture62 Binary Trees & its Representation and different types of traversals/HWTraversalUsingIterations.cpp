/*
HOME WORK
    Implement traversals using iterations instead of recursion
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *leftNode;
    node *rightNode;
    node(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};

void buildTree(node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return;
    }
    else
    {
        root = new node(data);
        cout << "Enter the data for left node " << root->data << endl;
        buildTree(root->leftNode);
        cout << "Enter the data for right node " << root->data << endl;
        buildTree(root->rightNode);
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->leftNode);
        cout << root->data << " ";
        inorder(root->rightNode);
    }
}

// // LNR
// void inorderTraversal(node *root)
// {
//     queue<node *> q;
//     node *temp = root;
//     int count = 0;
//     do
//     {
//         q.push(temp);
//         temp = temp->leftNode;
//         // stack.push(root);
//         // root = root->leftNode;

//         // count++;
//         // if (root->leftNode == NULL)
//         // {
//         // do
//         // {
//         // root = root->rightNode;
//         // } while (root->rightNode == NULL);
//         // }

//     } while (temp->leftNode != NULL && temp->rightNode == NULL);
//     while (!q.empty())
//     {
//         cout << stack.top()->data << " ";
//         stack.pop();
//     }
// }

// void iterativeInorder(node* root) {
//     stack<node*> nodeStack;
//     node* temp = root;
//     while (temp != nullptr || !nodeStack.empty()) {
//         while (temp != nullptr) {
//             nodeStack.push(temp);
//             temp = temp->leftNode;
//         }

//         temp = nodeStack.top();
//         nodeStack.pop();

//         cout << temp->data << " ";

//         temp = temp->rightNode;
//     }
// }

void iterativeInorder(node *root)
{
    stack<node *> nodeStack; // stack lagega kyunki humein jin nodes ko pass kar rahe hai unko store karna hai
                             // aur humein akhir mein dala hua element pehle nikalna hai (LIFO) isliye stack ka use kiya
    node *temp = root;
    while (!nodeStack.empty() || temp != NULL)
    {
        while (temp != NULL)
        {
            nodeStack.push(temp);
            temp = temp->leftNode;
        }
        temp = nodeStack.top();
        nodeStack.pop();
        cout << temp->data << " ";
        temp = temp->rightNode;
    }
}

void iterativePreorder(node *root)
{
    node *temp = root;
    stack<node *> nodeStack;
    while (temp != nullptr || !nodeStack.empty())
    {
        while (temp != NULL)
        {
            nodeStack.push(temp);
            cout << temp->data << " ";
            temp = temp->leftNode;
        }
        temp = nodeStack.top();
        nodeStack.pop();
        temp = temp->rightNode;
    }
}

void iterativePostorder(node *root)
{
    node *temp = root;
    node *printNode = NULL;
    stack<node *> nodeStack;
    while (temp != NULL || !nodeStack.empty())
    {
        while (temp != NULL)
        {
            nodeStack.push(temp);
            temp = temp->leftNode;
        }
        if (printNode != NULL)
        {
            cout << printNode->data << " ";
        }

        printNode = nodeStack.top();
        temp = nodeStack.top();
        nodeStack.pop();
        temp = temp->rightNode;
    }
}

int main()
{
    node *root;
    buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // iterativeInorder(root);
    // ans = 7 3 11 1 17 5

    // iterativePreorder(root);
    // 1 3 7 11 5 17

    iterativePostorder(root);
    // 7 11 3 17 5 1

    return 0;
}