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
        if (mini == 1e9 && maxi == -1e9){
            if (root->left) solve(root->left, min(mini, root->val), max(maxi, root->val), diff);
            if (root->right) solve(root->right, min(mini, root->val), max(maxi, root->val), diff);
            return ;
        }
        int dif1 = abs(root->val - maxi);
        int dif2 = abs(root->val - mini);
        diff = max(diff, max(dif1, dif2));
        if (root->left) solve(root->left, min(mini, root->val), max(maxi, root->val), diff);
        if (root->right) solve(root->right, min(mini, root->val), max(maxi, root->val), diff);
        return ;
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = 1e9, maxi = -1e9, ans = -1e9;
        solve(root, mini, maxi, ans);
        return ans;
    }
};