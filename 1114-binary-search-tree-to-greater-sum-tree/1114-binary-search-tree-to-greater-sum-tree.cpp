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
    void solve(TreeNode* root, int& sum){
        if (!root) return ;
        solve(root->right, sum);
        root->val = root->val + sum;
        sum = root->val;
        solve(root->left, sum);
        return ;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return root;
        int s = 0;
        solve(root, s);
        return root;
    }
};