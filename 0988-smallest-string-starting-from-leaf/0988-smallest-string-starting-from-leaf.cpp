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
    bool isLeaf(TreeNode* root){
        if (!root->left && !root->right) return true;
        return false;
    }
    void solve(TreeNode* root, string path, string& ans){
        if (!root) return ;
        path = char(root->val+'a') + path;
        solve(root->left, path, ans);
        solve(root->right, path, ans);
        if (isLeaf(root)){
            if (ans=="" || path < ans){
                ans = path;
            }
        }
        return ;
    }
    string smallestFromLeaf(TreeNode* root) {
        string path, ans;
        solve(root, path, ans);
        return ans;
    }
};