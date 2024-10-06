// https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>
class Solution {
public:
    void preorder(TreeNode* root, long long int pth, vector<int>& pths) {
        if (!root)
            return;
        pth = pth * 10 + (root->val);
        if (!root->left && !root->right) {
            pths.push_back(pth);
            return;
        }
        preorder(root->left, pth, pths);
        preorder(root->right, pth, pths);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> pths;
        preorder(root, 0, pths);
        int ans = 0;
        for (auto it : pths)
            ans += it;
        return ans;
    }
};
// TC - 