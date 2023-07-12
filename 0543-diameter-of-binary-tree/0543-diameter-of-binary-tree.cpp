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
    int maxDepth(TreeNode* root){
        if (root == NULL) return 0; 
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh,rh);
    }
    void findMax(TreeNode* root, int& mx){
        if (root == NULL) return; 
        int lt = maxDepth(root->left);
        int rt = maxDepth(root->right);
        mx = max(mx,lt+rt);
        findMax(root->left,mx);
        findMax(root->right,mx);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0 ;
        int mx = 0;
        findMax(root,mx);
        return mx;
    }

};