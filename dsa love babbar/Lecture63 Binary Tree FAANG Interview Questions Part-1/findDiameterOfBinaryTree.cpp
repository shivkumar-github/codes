/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/

#include<bits/stdc++.h>
using namespace std;

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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // TreeNode*
        int ans = 0;
        // We can observe that the path passes throught atleast one node acting as root node 
        // So for any binary tree there are three options either it is passing through root node or root->left or root->right (look at explantion image)
        // 1. so when it(the longest path between nodes) is passing throught root
        int ans1 = height(root->left) + height(root->right);
        int ans2 = diameterOfBinaryTree(root->left); // 2. passing through left node of the root node (i.e. path exists in left tree)
        ans = max(ans1,ans2);
        int ans3 = diameterOfBinaryTree(root->right); // passing through right node of the root node(path exists in right tree)
        ans = max(ans,ans3);// return maximum of all three
        return ans;
    }// but in this approach we are iterating repeatedly for finding the height and for finding the diameter but we can find diameter of left(or right) part and height of left(or right) part together  and reduce time complexity from O(N^2) to O(N)
};// space complexity O(height) -> in worst case of skewed tree O(N)
// time complexity O(N^2) (calculate using method to calculate time complexity of recursive methods)

class Solution {
public:
    // in this approach we calculate the height simultaneously with the diameter which reduces no of visits = 1 per node hence time complexity becomes O(N) from O(N^2)
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0}; // when node is null both the height and diameter are 0
        int ans = 0;

        pair<int,int> p1 = solve(root->left);
        pair<int,int> p2 = solve(root->right);

        ans = max(p1.first,p2.first);
        int ans3 = p1.second+p2.second;
        ans = max(ans,ans3);

        // height of tree from curr root is max of left and right and +1
        int height = max(p1.second,p2.second)+1;
        return {ans,height};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }// space complexity O(height)->O(N)
	// time complexity O(N) where N is the number of nodes in the tree
};