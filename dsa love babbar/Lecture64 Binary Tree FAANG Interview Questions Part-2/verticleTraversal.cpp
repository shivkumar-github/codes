// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends

//METHOD: 1 Wrong method 
// class Solution
// {
// public:
//     void traverse(Node *root, vector<vector<int>> &mp, int lvl)
//     {
//         if (!root)
//             return;
//         // cout << lvl << " " << mp.size() << endl;
//         if (lvl >= mp.size())
//             mp.resize((lvl + 1));
//         mp[lvl].push_back(root->data);
//         traverse(root->left, mp, lvl - 1);
//         traverse(root->right, mp, lvl + 1);
//     }
//     void findMin(Node* root, int &minlvl, int lvl){
//         if(!root)
//             return;
//         if(lvl < minlvl)
//             minlvl = lvl;
//         findMin(root->left, minlvl, lvl-1);
//         findMin(root->right,minlvl,lvl+1);
//     }
//     vector<int> verticalOrder(Node *root)
//     {
//         int cnt = 0;
//         Node *temp = root;
//         int minilvl = 0;
//         findMin(root, minilvl,0);
//         int lvl = (minilvl < 0) ? 0 - minilvl : 0; // if minilvl is less than 0 then negative of that is level of root or level of root is 0
//         vector<vector<int>> mp;
//         traverse(root, mp, lvl);
//         vector<int> trvrs;
//         for (int i = 0; i < mp.size(); i++)
//             for (int j = 0; j < mp[i].size(); j++)
//                 trvrs.push_back(mp[i][j]);

//         return trvrs;
//     }
// };

// METHOD: 2 Correct Method (By using level order traversal)
class Solution
{
    public:
    vector<int> verticalOrder(Node *root)
    {
        vector<int> trvrs;
        if(!root) return trvrs;
        map<int, map<int,vector<int>>> mp;// verticle ,map of lvl , nodes in that level at that verticle

        // performing level order traversal
        queue<pair<int, Node*>> q;
        q.push({0,root});
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){ // for loop for maintaining lvl variable correctly
                pair<int,Node*> temp = q.front();
                q.pop();
                int hd = temp.first;
                Node *frNd = temp.second;
                mp[hd][lvl].push_back(frNd->data);
                if(frNd->left)
                    q.push({hd-1,frNd->left});
                if(frNd->right)
                    q.push({hd+1,frNd->right});
            }
            lvl++;
        }
        for(auto i : mp){
            for(auto j : i.second){
                for(auto k : j.second){
                    trvrs.push_back(k);
                }
            }
        }
        return trvrs;
    }
}; // Time Complexity - DOUBT:  In question it is given that the time complexity must be O(N) but as we are traversing through each node and performing insertion operation in map 



// void traverse(Node* root, map<int,vector<int>>& mp, int lvl){
//     if(!root) return;

//     traverse(root->left, mp, lvl-1);
//     traverse(root->right, mp, lvl+1);
// }
// vector<int> verticalOrder(Node *root)
// {
//     int lvl = 0;
//     Node*temp = root;
//     while(temp){
//         if(temp->left) {
//             temp= temp->left;
//             lvl++;
//         }
//         else temp = temp->right;
//     }
//     map<int,vector<int>> mp;
//     traverse(root, mp, lvl);
//     vector<int> trvrs;
//     for(int i = 0;i<mp.size();i++)
//         for(int j = 0;j<mp[i].size();j++)
//             trvrs.push_back(mp[i][j]);

//     return trvrs;
// }//time complexity O(nlogn) hence gives tle(n for rec and logn for searching in mp)




//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends