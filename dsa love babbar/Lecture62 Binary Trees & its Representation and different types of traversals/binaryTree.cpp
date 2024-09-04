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

// data accept karo dynamically root node ko assign karo aur base case after that and then left and then right 
// NLR traversal used in this method and when N uske data ko accept karo
node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL; // why null -> indicates all data is inserted 
    }

    // calling buildTree recursively to build tree from left of the node
    cout << "Enter data for inserting in left of " << root->data << endl;
    root->left = buildTree(root->left);

    // calling buildTree recursively to build tree from right of the node
    cout << "Enter data for inserting in right of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

// level wise traverse karna hai
/*
approach ->>
    ->> pehle root ko dalo aur ek null dalo 
    ->> null ka istemal ek pause ki tarah karo jaise hi null ayein vaise endl daldo aur agar phir bhi list empty nahi hui iska matlab aur levels bachi hui hai 
    ->> To agli level ke liye ek endl daldo
    ->> uske baad har ek level ke har ek element ka left right queue mein dalo
*/
void levelOrderTraversal(node *root)
{
    queue<node *> q; // -->> more about queue is written at the bottom of the code
    q.push(root);
    q.push(NULL); //-> as first level always have only one element

    while (!q.empty())
    {
        // cout<< "hey" << endl;
        node *temp = q.front();
        q.pop();
        if (temp == NULL) //-> purana level complete traversal ho chuka hai
        {
            cout << endl; // jaise null ajayein vaise enter mardo
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL); // ek null milne ke baad 
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left) // agar null nahi hai to que mein daldo (NULL = 0 hota hai) if pushed when null then it will be considered as end of a level
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        } // alternate very similar code is written in practice file which is written in practice file
    } // TC = O(N) where N is total nodes
    // SC = O(N) as sc = O(no of nodes in last level) = (N+1)/2;
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                lvl.push_back(temp->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> lvl;
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                lvl.push_back(temp->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};

/*
Traversals :-

    ->> L matlab left part mein jao
    ->> R matlab right part mein jao
    ->> N matlab node ko print kardo

1. inorder traversal :-
    ->> node in matlab Left aur Right ke bich mein hoga
    ->> LNR -> Left then Node(print the node) then Right
    ->> apply LNR to each node
    ->> when N then print that node

2. preorder traversal :-
    ->> node pre matlab left aur right ke pehle hoga
    ->> NLR -> Left then Node(print the node) then Right
    ->> apply LNR to each node
    ->> when N then print that node

3. postorder traversal :-
    ->> node post matlab left aur right ke baad hoga
    ->> LRN -> Left the Right then Node (print the node)
    ->> apply LNR to each node
    ->> when N then print that node
*/

// in order matlab node hai vo bich mein hoga
void inorder(node *root)
{
    // base case in recursion
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // base case in recursion
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

void buildFromLevelOrder(node *&root)
{
    queue<node *> q; // level order matlab queue ayega
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // creating a tree
    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order Traversal

    // cout << "Printing the level order traversal :" << endl;
    // levelOrderTraversal(root);
    // cout << "Inorder traversal of the following tree is  : " << endl;
    // inorder(root);
    // cout << endl
    //      << "Preorder traversal of the following tree is : " << endl;
    // preorder(root);
    // cout << endl
    //      << "Postorder traversal of the following tree is : " << endl;
    // postorder(root);
    // return 0;
}

/*
queue is a linear data structure based on FIFO principle (First In First Out) just like any line we
*/