https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

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
            for(int i = 0;i<size;i++){
                pair<int,Node*> p = q.front();
                q.pop();
                mp[p.first][lvl].push_back(p.second->data);
                if(p.second->left)
                    q.push({p.first-1,p.second->left});
                if(p.second->right)
                    q.push({p.first+1,p.second->right});
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


// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/