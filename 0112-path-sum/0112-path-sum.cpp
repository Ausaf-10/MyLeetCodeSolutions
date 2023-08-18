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
    bool fun(TreeNode* root, int sum, int target){
        if (root == NULL) return false;
        sum+=root->val;

        bool lt = fun(root->left, sum, target);
        bool rt = fun(root->right, sum, target);

        if (root->left == NULL && root->right == NULL){
            if (sum == target) return true;
        }
        
        sum-=root->val;

        return lt || rt;

        // return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (!root->left && !root->right) return root->val == targetSum;

        return fun(root,0,targetSum);
    }
};