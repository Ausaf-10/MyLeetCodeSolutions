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
    void solve(TreeNode* root){
        if (!root) return ;
        TreeNode* lt = root->left, *rt = root->right;
        root->left = rt, root->right = lt;
        solve(root->left);
        solve(root->right);
        return ;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root; 
        solve(root);
        return root;
    }
};