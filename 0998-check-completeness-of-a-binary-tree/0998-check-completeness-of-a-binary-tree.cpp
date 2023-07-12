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
    int countNodes(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool CBT(TreeNode* root, int i, int cnt){
        if (root == NULL) return true;
        if (i >= cnt) return false;
        if (CBT(root->left,2*i+1,cnt) && CBT(root->right,2*i+2,cnt)) return true;
        return false; 
    }
    bool isCompleteTree(TreeNode* root) {
        int cnt = countNodes(root);
        return CBT(root,0,cnt);
    }
};