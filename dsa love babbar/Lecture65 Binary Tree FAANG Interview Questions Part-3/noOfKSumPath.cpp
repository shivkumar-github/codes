// https://www.geeksforgeeks.org/problems/k-sum-paths/1
class Solution {
  public:
    void solve(Node* root, int k, vector<int> path, int& count){
        if(!root) return;
        path.push_back(root->data);
        
        // left
        solve(root->left, k, path, count);
        solve(root->right, k, path, count);
        
        // checking for K sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0;i--){
            sum +=path[i];
            if(sum == k) count++;
        }
        path.pop_back();
    }
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, path, count);
        return count;
    }
};
// DOUBT: time complexity - O(N^2)?