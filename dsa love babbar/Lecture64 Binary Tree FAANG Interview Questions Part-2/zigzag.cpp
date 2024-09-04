// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1368114037/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        bool rev = false; // to track if we have to print in reverse for curr level
        while(!q.empty()){
            int size = q.size();
            vector<int> lvl(size); // to store elements from 1 level
            int lvlind = rev?size-1:0; // assign value to index according to the rev
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                lvl[lvlind] = temp->val;
                rev?lvlind--:lvlind++; // update index depending upon value of rev
            }
            rev = rev?false:true; // change the value of rev
            ans.push_back(lvl);
        }
        return ans;
    } // TC - O(N) as we are traversing through each node
	// space complexity O(N) for ans vector
	// if total nodes are 31 then 32/2 are in last level
};