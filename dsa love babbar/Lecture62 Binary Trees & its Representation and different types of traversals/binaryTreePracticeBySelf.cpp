/*
self practicing for binary tree

    ->> Binary tree is a non linear data structure
    ->> each node is linked to two or less than two nodes in a binary tree
*/

#include <iostream>
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

// *** are the important steps
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // ***

    while (!q.empty())
    {
        // node *temp = q.front();
        if (q.front() == NULL)
        {
            q.pop(); // ***we have to write temp here because if we do not pop the null here then the queue will never be empty and loop will run infinite
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << q.front()->data << " ";
            if (q.front()->leftNode)
            {
                q.push(q.front()->leftNode);
            }
            if (q.front()->rightNode)
            {
                q.push(q.front()->rightNode);
            }
            q.pop();
        }
    }
}

// using NLR here while building this tree using this approach
node *buildTree(node *root) // we are returning the root so no need to take reference of root pointer
{
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1) // base case for the recursion
    {
        return NULL;
    }

    cout << "Enter the data for left node of node: " << root->data << endl;
    root->leftNode = buildTree(root->leftNode);
    cout << "Enter the data for right node of node: " << root->data << endl;
    root->rightNode = buildTree(root->rightNode);
    return root;
}

// LNR
void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->leftNode);
    cout << root->data << " ";
    inorderTraversal(root->rightNode);
}

void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorderTraversal(root->leftNode);
        preorderTraversal(root->rightNode);
    }
}

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->leftNode);
    postorderTraversal(root->rightNode);
    cout << root->data << " ";
}

// level order matlab queue ayega
void buildFromLevelOrderTraversal(node *&root)
{
    cout << "Enter data for root node: " << endl;
    int data;
    cin >> data;

    // base case ->> when to stop ..when user enters data = -1
    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front(); // we should use temp wala method because then we don't have to think where to pop, if we don't use temp then we have to think where to pop
        // root->rightNode = buildFromLevelOrderTraversal(temp->rightNode); // ->> this approach is not right because it takes us down and down so can not take input levelwise
        // root->rightNode = buildFromLevelOrderTraversal(temp->rightNode);

        cout << "Enter the data for left node of " << q.front()->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            q.front()->leftNode = new node(leftData);
            q.push(q.front()->leftNode);
        }

        cout << "Enter the data for right node of " << q.front()->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            q.front()->rightNode = new node(rightData);
            q.push(q.front()->rightNode);
        }
        q.pop();
    }
}

int main()
{
    node *root = NULL;
    // building tree using buidlfromlevel order which accepts inputs levelwise
    buildFromLevelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);

    // building tree using buildtree which accpets inputs using NLR
    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);
    // cout << endl << "Inorder traversal in the given binary tree will be: " << endl;
    // inorderTraversal(root);
    // cout << endl << "Preorder traversal in the given binary tree will be: " << endl;
    // preorderTraversal(root);
    // cout << endl << "Postorder traversal in the given binary tree will be: " << endl;
    // postorderTraversal(root);

    return 0;
}