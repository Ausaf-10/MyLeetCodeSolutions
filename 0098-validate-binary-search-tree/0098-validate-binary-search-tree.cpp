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
    bool validBST(TreeNode* root,long long low,long long high){
        if (root == NULL) return true;
        if (root->val >= high || root->val <= low) return false;
        
        bool lt = validBST(root->left, low, root->val);
        bool rt = validBST(root->right, root->val, high);
        
        if (lt==true && rt==true) return true;
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root,LONG_MIN,LONG_MAX);
    }
};