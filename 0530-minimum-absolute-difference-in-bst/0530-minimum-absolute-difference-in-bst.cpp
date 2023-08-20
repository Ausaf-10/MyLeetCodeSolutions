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
    void solve(TreeNode* root, int& mini, TreeNode*& preVal){
        if (root == NULL) return ;
        solve(root->left, mini, preVal);
       
        if (preVal!=NULL){
            mini = min(mini, abs(root->val - preVal->val));
        }
        preVal = root;
        solve(root->right, mini, preVal);

        return ;
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
       
        TreeNode* preVal = NULL;
       
        solve(root,minDiff,preVal);
       
        return minDiff;
    }
};