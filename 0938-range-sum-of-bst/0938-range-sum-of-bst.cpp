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
    int preorder(TreeNode* root, int low, int high){
        if (root == NULL) return 0;
        int curVal = (low <= root->val && root->val <= high) ? root->val : 0;
            
        int leftSum = preorder(root->left, low, high);
        int rightSum = preorder(root->right, low, high);
        
        return curVal + leftSum + rightSum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root,low,high);

    }
};