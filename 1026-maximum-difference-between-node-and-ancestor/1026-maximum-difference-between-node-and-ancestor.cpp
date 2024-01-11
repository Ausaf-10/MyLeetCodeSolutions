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
    int fun(TreeNode* root, int maxi, int mini){
        if (!root) return abs(maxi-mini);
      
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
    
        int leftValue = fun(root->left,maxi,mini);
        int rightValue = fun(root->right,maxi,mini);

        return max(leftValue, rightValue);
    }
    int maxAncestorDiff(TreeNode* root) {
        return fun(root, -1e9, 1e9);
    }
};