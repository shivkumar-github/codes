// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/ --> leetcode
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, TreeNode *&p, TreeNode *&q, vector<TreeNode *> &crpth, vector<vector<TreeNode *>> &pths)
    {
        if (!root)
            return;
        crpth.push_back(root);
        if (root->val == p->val || root->val == q->val)
        {
            pths.push_back(crpth);
            if (pths.size() == 2)
                return; // if both are found then return else have to keep on
        }
        solve(root->left, p, q, crpth, pths);
        solve(root->right, p, q, crpth, pths);
        crpth.pop_back();
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        vector<vector<TreeNode *>> pths;
        vector<TreeNode *> crpth;
        solve(root, p, q, crpth, pths);
        TreeNode *prvans = root;
        for (int i = 0; i < pths[0].size() && i < pths[1].size(); i++)
        {
            if (pths[0][i]->val != pths[1][i]->val)
                return prvans;
            prvans = pths[0][i];
        }
        return prvans;
    }
};

// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card ->gfg
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    /* void solve(Node* root, int p, int q, vector<Node*>& crpth, vector<vector<Node*>>& pths){
        if(!root) return;
        crpth.push_back(root);
        if(root->data == p || root->data == q) {
            pths.push_back(crpth);
            if(pths.size() == 2) return; // if both are found then return else have to keep on
        }
        solve(root->left, p, q, crpth, pths);
        solve(root->right, p, q, crpth, pths);
        crpth.pop_back();
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(!root) return NULL;
        vector<vector<Node*>> pths;
        vector<Node*> crpth;
        solve(root, p, q, crpth, pths);
        Node* prvans = root;
        for(int i = 0;i<pths[0].size() && i<pths[1].size();i++){
            if(pths[0][i]->data != pths[1][i]->data) return prvans;
            prvans = pths[0][i];
        }
        return prvans;
    }
    // TC and SC - O(N)
     */
    //    method 2 -
    Node *lca(Node *root, int n1, int n2)
    {
        if (!root) return NULL; // check for null first to avoid segmentation faults
        if(root->data == n1 || root->data == n2) return root;
        Node* right = lca(root->left, n1, n2);
        Node* left = lca(root->right, n1, n2);
        if (!left && !right) return NULL;
        if (right && !left) return right;
        if (!right && left) return left;
        if(right && left) return root;
        return NULL;
    }
// TC - O(N);
// SC - O(N); - O(height) but considering worst case of skew tree when height is equal to n
};

//{ Driver Code Starts.

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d ", &a, &b);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.lca(root, a, b)->data << endl;
    }
    return 0;
}

// } Driver Code Ends
