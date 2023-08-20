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
    int minDiff = INT_MAX;       
    TreeNode* preVal = NULL;

    void solve(TreeNode* root){
        if (root == NULL) return ;
        solve(root->left);
       
        if (preVal!=NULL){
            minDiff = min(minDiff, abs(root->val - preVal->val));
        }
        preVal = root;
        solve(root->right);

        return ;
    }
    int minDiffInBST(TreeNode* root) {
        
       
        solve(root);
       
        return minDiff;
    }
};