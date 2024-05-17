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
        return !root->left && !root->right;
    }
    TreeNode* fun(TreeNode* root, int target){
        if (!root) return NULL;
        TreeNode* lt = fun(root->left, target);
        TreeNode* rt = fun(root->right, target);
        root->left = lt, root->right = rt;
        if (isLeaf(root)){
            if (root->val == target) return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return fun(root, target);
    }
};