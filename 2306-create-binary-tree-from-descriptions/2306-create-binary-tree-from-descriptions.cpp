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
    int fun(unordered_map<int, int>& mp, int node){
        if (mp.find(node) == mp.end()) return node;
        return fun(mp, mp[node]);
    }
    TreeNode* getRoot(unordered_map<int, vector<vector<int>>>& mp, int node){
        if (mp.find(node) == mp.end()) return new TreeNode(node);
        TreeNode* root = new TreeNode(node);
        for (auto it : mp[node]){
            if (it[1] == 1){
                root->left = getRoot(mp, it[0]);
            }
            else{
                root->right = getRoot(mp, it[0]);
            }
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> childParent;
        unordered_map<int, vector<vector<int>>> mp;
        for (auto it : descriptions){
            int child = it[1], parent = it[0];
            mp[parent].push_back({child, it[2]});
            childParent[child] = parent;
        }
        int node = childParent.begin()->first; 
        int root = fun(childParent, node);
        return getRoot(mp, root);
    }
};