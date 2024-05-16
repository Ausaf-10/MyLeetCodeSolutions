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
    bool fun(TreeNode* root){
        if (!root->left && !root->right) return root->val;
        bool lt = fun(root->left);
        bool rt = fun(root->right);
        if (root->val == 2){
            return lt || rt;
        }
        return lt && rt;
    }
    bool evaluateTree(TreeNode* root) {
        return fun(root);
    }
};