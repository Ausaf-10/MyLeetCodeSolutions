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
    void GST(TreeNode* root,int &sum){
        // WE ARE MOVING TOWARDS AS RIGHT AS POSSIBLE BECAUSE THE RIGHT WILL ALWAYS BE BIGGER
        if (root == NULL) return ;
        GST(root->right,sum);
        
        sum+=root->val;
        root->val = sum;
        
        GST(root->left,sum);
        return ;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        if (root == NULL || root->left == NULL && root->right == NULL) return root;
        GST(root,sum);
        return root;
    }
};