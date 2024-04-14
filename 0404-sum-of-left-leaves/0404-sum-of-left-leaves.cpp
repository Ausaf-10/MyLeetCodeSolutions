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
    void preorder(TreeNode* root, int& sum){
        if (!root) return ;
        if (root->left && !root->left->left && !root->left->right) sum+=root->left->val;
        preorder(root->left, sum);
        preorder(root->right, sum);
        return ;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preorder(root, sum);
        return sum;
    }
};