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
        int lh = Height(root->left); // FIND THE LEFT HEIGHT
        int rh = Height(root->right); // FIND THE RIGHT HEIGHT
        if (lh !=0 && rh == 0) return lh+1;  // IF RIGHT IS 0 THEN DONT THEN ADD THE ONE WHICH IS NOT 0
        if (lh ==0 && rh != 0) return rh+1;   
        return 1 + min(lh,rh);

    }
    int minDepth(TreeNode* root) {
        // TreeNode *node=root;
        return Height(root);
        
    }
};