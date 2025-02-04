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
    int func(TreeNode* root, int &maxi){
        if (!root) return 0;
        int lh = func(root->left, maxi);
        int rh = func(root->right, maxi);
        if (lh < 0) lh = 0;
        if (rh < 0) rh = 0;
        maxi = max(maxi, root->val + lh + rh);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxi = -1e9;
        int x = func(root, maxi);
        return maxi;
    }
};