// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

/* void solve(Node* root, int& k, vector<int>& pt, int& node, int& ans){
    if(!root) return;
    if(root->data == node){
        if(pt.size() >= k) ans = pt[pt.size()-k]; // if size is less than k then there is no ancestor
        return;
    }
    pt.push_back(root->data);
    solve(root->left, k, pt, node, ans);
    solve(root->right, k, pt, node, ans);
    pt.pop_back();
}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> path;
    solve(root, k, path, node, ans);
    return ans;
}
*/

Node* solve(Node* root, int& k, int node){
    if(!root) return NULL;
    if(root->data == node) {
        k--;
        // cout << "current node = " << root->data << " return value = " << root->data << " returned k value : " << k << endl;
        return root;
    }
    Node* left = solve(root->left, k, node);
    if(k == 0 && left){
        k--;
        // cout << "current node = " << root->data << " return value = " << root->data << " returned k value : " << k << endl;
        return root;
    }
    Node* right = solve(root->right, k, node);
    if(k == 0 && right){
        k--;
        // cout << "current node = " << root->data << " return value = " << root->data << " returned k value : " << k << endl;
        return root;
    }
    if(!left && !right) return NULL;
    else{ // either of them is non NULL
        k--;
        // cout << "current node = " << root->data << " return value = " << (left?left:right)->data << " returned k value : " << k << endl;
        return left?left:right;
    }
}
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    ans = solve(root, k, node)->data;
    return k<0?ans:-1;
}
