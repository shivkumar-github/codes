// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
// https://leetcode.com/problems/balanced-binary-tree/
// a tree is balanced when for every node the height of left part and right part do not differ more than 1
#include <bits/stdc++.h>
/* A binary tree node structure

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

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }// instead we will try to calculate height and isBalanced simultaneously to reduce the time comlexity
    
    pair<bool,int> solve(Node* root){
        if(!root) return {true,0}; // the node is empty that is further both heights are 0 i.e. tree is balanced and height is 0
        
        pair<bool,int> p1 = solve(root->left); // calculating height and isBalnced for left and right part of node
        pair<bool,int> p2 = solve(root->right);
        bool ans = p1.first && p2.first && (p1.second - p2.second <= 1 && p1.second - p2.second >= -1); // tree is balanced when left part is balanced, right part is balanced and difference between hights of both parts is between -1 to 1
        return {ans, max(p1.second,p2.second)+1}; // return ans and height for current root node
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return solve(root).first;
    } // TC O(N) where N is the number of nodes and space complexity is O(N) (as it will take space O(height) which in the worst case for skewed tree where no of nodes is height)
};

// METHOD: 2 Using special height function
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
    // else we can just write a solution where if that part of tree is not balanced then the height will be returned as -1 else if the part of tree is balanced then the actual height will be returned
    int height(TreeNode* root){
        if(!root) return 0;
        int op1 = height(root->left);
        if(op1 == -1) return -1;
        int op2 = height(root->right);
        if(op2 == -1) return -1; // if height of any part is -1 then that part is not balanced hence return -1;
        if(abs(op1-op2) <= 1)
            return max(op1,op2) + 1; // when both are not -1 and difference between height is not greater than 1 then return the height else return -1
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(height(root) == -1) return false;
        return true;
    }
};
