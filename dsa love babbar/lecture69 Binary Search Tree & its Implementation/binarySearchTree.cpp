/*
in Binary search tree for every node, every node on the left side of that node is smaller than the root node and every node on the right side of the root node is greater than that node
*/

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
        int data;
        node *left;
        node *right;
        node(int data)
        {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};

void insertIntoBST(node *&root, int data)
{
        if (root == NULL)
        {
                root = new node(data);
                return;
        }
        if (data > root->data)
        {
                // root ke right part mein insert karna hai
                insertIntoBST(root->right, data);
        }
        else
        {
                // root ke left part mein insert karna hai
                insertIntoBST(root->left, data);
        }
}

void takeInput(node *&root)
{
        int data;
        cin >> data;
        while (data != -1)
        {
                insertIntoBST(root, data);
                cin >> data;
        }
}

void levelOrderTraversal(node *root)
{

        queue<node *> q; // push the node directly
        q.push(root);
        q.push(NULL); // as first level have only one node
        while (!q.empty())
        {
                node *temp = q.front();
                q.pop();
                if (temp == NULL) // - purana level complete traverse ho chuka hai (we insert null to detect presence of level comletion and )
                {
                        cout << endl;
                        if (!q.empty())
                        {
                                // q is not still empty
                                q.push(NULL);
                        }
                }
                else
                {
                        cout << temp->data << " ";
                        // NULL key word is treated as 0 in pointers
                        if (temp->left)
                        {
                                q.push(temp->left);
                        }
                        if (temp->right)
                        {
                                q.push(temp->right);
                        }
                }
        }
}

void inorder(node *root)
{
        if (root == NULL)
        {
                return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
}

void postorder(node *root)
{
        if (root == NULL)
        {
                return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
}

void preorder(node *root)
{
        if (root == NULL)
        {
                return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
}

// finding element in binary search tree
node *find(node *root, int data)
{

        // recursive approach
        // if (root == NULL)
        // {
        //         return NULL;
        // }
        // if (data <root->data)
        // {
        //         return find(root->left, data)
        // }
        // else if (data>root->data)
        // {
        //         return find(root->right, data);
        // }
        // else{
        //         return root;
        // }

        // non - recursive approach
        // three possible cases
        // 1. empty tree
        if (root == NULL)
        {
                return NULL;
        }
        // 2. data is present in tree
        while (root)
        {
                if (data == root->data)
                {
                        return root;
                }
                else if (data > root->data)
                {
                        root = root->right;
                }
                else
                {
                        root = root->left;
                }
        }
        // 3. if node with such data is not present in tree
        return NULL;
}

node *findMini(node *root)
{
        // // here also there will be three cases
        // //1. empty tree
        // if (root == NULL)
        // {
        //         return NULL;
        // }
        // // more nodes on the left
        // else if (root->left)
        // {
        //         return findMini(root->left);
        // }
        // // no nodes remaining on left
        // else{
        //         return root;
        // }

        // non recursive approach
        if (root == NULL)
        {
                return NULL;
        }
        // tab tak left mein jao jab tak left mein left mein aur nodes hain
        while (root->left)
        {
                root = root->left;
        }
        return root;
}

node *findMaxi(node *root)
{
        // // recursive approach
        // //1. case empty  tree
        // if (root == NULL)
        // {
        //         return NULL;
        // }
        // //2. more right nodes exist
        // if (root->right)
        // {
        //         return findMaxi(root->right);
        // }
        // //3. no right node exists more hence root is our answer
        // else{
        //         return root;
        // }

        // non recursive approach
        if (root == NULL)
        {
                return NULL;
        }
        while (root->right)
        {
                root = root->right;
        }
        return root;
}

node *deleteNode(node *&root, int data)
{
        // base case
        if (root == NULL)
        {
                return NULL;
        }
        if (root->data == data)
        { // element found
                // while performing deletion there are 3 cases for that node to delete

                // 1. no child nodes
                // delete node, return NULL
                if (root->right == NULL && root->left == NULL)
                {
                        delete root;
                        return NULL; // important to delete null
                }

                // 2. single child node - root ko delete karke uski agah child node daldo
                // a. left child
                if (root->left != NULL && root->right == NULL)
                {
                        node *temp = root->left;
                        delete root;
                        return temp;
                }

                // b. right child
                if (root->right != NULL && root->left == NULL)
                {
                        node *temp = root->right;
                        delete root;
                        return temp;
                }

                // 3. two child nodes
                // you have two options
                // 1. left ka maximum node - predecessor
                // 2. right ka minimu node - successor
                // you can choose either of them
                if (root->left != NULL & &root->right != NULL)
                {
                        int mini = findMini(root->right)->data;
                        root->data = mini;
                        root->right = deleteNode(root->right, mini);
                        return root;
                }
        }
        else if (data < root->data)
        {
                root->left = deleteNode(root->left, data);
                return root;
        }
        else if (data > root->data)
        {
                root->right = deleteNode(root->right, data);
                return root;
        }
}

int main()
{
        node *root = NULL;
        cout << "Enter your data to create BST : " << endl;
        // 10 8 21 7 27 5 4 3 -1
        // 50 20 70 10 30 90 110 -1
        takeInput(root);

        cout << endl
             << "Printing level order traversal : " << endl;
        levelOrderTraversal(root);

        cout << endl
             << "Printing preorder : " << endl;
        preorder(root);

        cout << endl
             << "Printing inorder : " << endl;
        inorder(root);

        cout << endl
             << "Printing postorder : " << endl;
        postorder(root);
        cout << endl;

        cout << "min value is : " << findMini(root)->data << endl;
        cout << "maxi value is : " << findMaxi(root)->data << endl;

        // Deletion
        root = deleteNode(root, 70);
        cout << root->data << endl;

        cout << "Printing the BST : " << endl;
        levelOrderTraversal(root);

        cout << "Printing inorder " << endl;
        inorder(root);

        return 0;
}