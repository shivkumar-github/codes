// https://leetcode.com/problems/same-tree/
// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; // if both are null then return true;
        if(!p || !q) return false; // if only one of them is null then return false
        bool ans = isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && (p->val == q->val);
        // if left and right trees of both nodes are identical and both have same data then return true;
            return ans;
    }// time complexity O(N) where N is number of nodes and space complexity is (occupied by recursion stack) O(N) (O(height) which will be O(N) in skewed tree)
};


// MEHTOD: in this method the sum returns the value of sum of tree below that node (excluding the node itself)
class Solution {
  public:
    // this is a function which will return sum -1 when the tree is not sum tree
    int sum(Node* root){
        if(!root) return 0;
        
        int s1 = sum(root->left);
        if(s1 == -1) return -1;
        int s2 = sum(root->right);
        if(s2 == -1) return -1;
        
        if(root->left) s1 += root->left->data;
        if(root->right) s2 += root->right->data;
        
        if(s1 == 0 && s2 == 0) return 0; // if both are 0 then it is leaf node which is considered as sumTree in given statement hence return sum = 0
        if(root->data != s1 + s2) return -1; // if the node's data is not equal to the sum of its children, it's not a sum tree
        return (s1 + s2); // return the sum of the tree below that node (excluding the node itself)
    }
    
    bool isSumTree(Node* root) {
        if(!root) return true;
        int ans = sum(root);
        return ans != -1 && ans == root->data;
    }
};