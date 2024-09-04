// Should return true if tree is Sum Tree, else false
// https://www.geeksforgeeks.org/problems/sum-tree/1
class Solution {
  public:
    // this is a function which will return sum -1 when the tree is not sum tree
    int sum(Node* root){
        if(!root) return 0;
        int s1 = sum(root->left);
        int s2 = sum(root->right);
        if(s1 == 0 && s2 == 0) return root->data; // if both are 0 then it is leaf node which is considered as sumTree in given statement hence return sum = root->data
        if(s1 == -1 || s2 == -1 || root->data != s1 + s2) return -1; // if either of them is -1 then the tree is not sum
        return (s1 + s2 + root->data); // here both are non -1 and equal to root data hence return sum
    }
    bool isSumTree(Node* root) {
        // Your code here
        if(!root) return true;
        // sum is -1 i.e. node below the root is not sumtree
        // the sum returned is the sum of tree from that node hence the returned sum will also include the node data itself
        return sum(root) != -1; // if non -1 value is written then the sum is already equal to the root node data so return true if non zero
    } // time complexity = O(N) space complexity O(N) in worst case for skewed tree
};