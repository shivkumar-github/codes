class Solution {
public:
    // function to add nodes at left boundry
    void left(Node* root, vector<int>& ans){
        if(!root) return;
        if(root->left || root->right) ans.push_back(root->data); //add only when it is not leaf node
        left(root->left,ans); // continue for it's left node
        if(!root->left) left(root->right,ans); // if its left was null then call for right
    }
    
    // function to add leaf nodes in required sequence
    void preorder(Node* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right){ // add only if the node is leaf node
            // now before pushing check if it has both left and right NULL
            ans.push_back(root->data);
        }
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    // function to add nodes at right boundry
    void right(Node* root, vector<int>& ans){
        if(!root) return;
        right(root->right, ans); // first iterate till last node at right boundry 
        if(!root->right) right(root->left, ans); // if right is NULL then process left
        if(root->left || root->right) // add only if it is not leaf node
            ans.push_back(root->data);
    }
    
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        // push root->data separertaly and then process root->left and root->right to avoid double occurance of root data
        ans.push_back(root->data);
        // if root is leaf node itself then return 
        if(!root->left && !root->right) return ans;
        // else add leftmost(except leaf) nodes in boundary traversal
        left(root->left, ans);
        // add leaf nodes using preorder to get the in correct sequence
        preorder(root, ans);
        // add rightmost nodes in boundary traversal
        right(root->right,ans);
        
        return ans;
    }
};

// after improving a bit (try to process distinct cases whose cases don't overlap so that it will be easier to write code)
class Solution {
public:
    // function to add nodes at left boundry
    void left(Node* root, vector<int>& ans){
        if(!root || (!root->left && !root->right)) return; // return if it is null or leaf node
        ans.push_back(root->data); 
        root->left?left(root->left,ans):left(root->right,ans); // continue with left node or if left is null then continue with right node
    }
    
    // function to add leaf nodes in required sequence
    void preorder(Node* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right){ // add only if the node is leaf node
            // now before pushing check if it has both left and right NULL
            ans.push_back(root->data);
        }
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    // function to add nodes at right boundry
    void right(Node* root, vector<int>& ans){
        if(!root || (!root->left && !root->right)) return;
        root->right?right(root->right,ans):right(root->left,ans); // traverse for right node or if right is null then traverse to left node
        ans.push_back(root->data); // after traversal push the root node data
    }
    
    vector<int> boundary(Node *root)
    {
        // there will be three types of nodes in boundary traveral 1. nodes at left boundry(execpt leaf) 2. nodes at right boundry(except leaf) 3. leaf nodes
        vector<int> ans;
        if(!root) return ans;
        // push root->data separertaly and then process root->left and root->right to avoid double occurance of root data
        ans.push_back(root->data);
        
        // left nodes
        left(root->left, ans);
        
        // add leaf nodes using preorder to get the in correct sequence
        preorder(root->left, ans);
        preorder(root->right, ans);
        
        // add rightmost nodes in boundary traversal
        right(root->right,ans);
        
        return ans;
    }
};