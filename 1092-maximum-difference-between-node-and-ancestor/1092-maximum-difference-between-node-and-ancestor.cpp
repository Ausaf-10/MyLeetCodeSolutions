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
    void solve(TreeNode* root, int mini, int maxi, int &diff){
        
        if (maxi != -1e9 && mini != 1e9){
            diff = max(diff, abs(root->val - mini));
            diff = max(diff, abs(root->val - maxi));
        }

        if (root->left) solve(root->left, min(mini, root->val), max(root->val, maxi), diff);
        if (root->right) solve(root->right, min(mini, root->val), max(root->val, maxi), diff);

        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = 1e9, maxi = -1e9, ans = -1e9;
        solve(root, mini, maxi, ans);
        return ans;
    }
};