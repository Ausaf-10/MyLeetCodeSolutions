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
    int Height(TreeNode *root){
        if (root == NULL) return 0;
        int lh = Height(root->left);
        int rh = Height(root->right);
        if (lh !=0 && rh == 0) return lh+1;   
        if (lh ==0 && rh != 0) return rh+1;   
        return 1 + min(lh,rh);

    }
    int minDepth(TreeNode* root) {
        // TreeNode *node=root;
        return Height(root);
        
    }
};