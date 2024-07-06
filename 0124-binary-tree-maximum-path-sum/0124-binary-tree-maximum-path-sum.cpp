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
    int solve(TreeNode* root, int &maxi){
        if (!root) return 0;
        int lh = solve(root->left, maxi);
        int rh = solve(root->right, maxi);
        maxi = max(maxi, lh+rh+root->val);
        return max(0, max(lh,rh) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        int a = solve(root, maxi);
        return maxi;
    }
};