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
    int countNode(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }
    bool completeBinaryTree(TreeNode* root,int i,int cnt){
        if (root == NULL) return true;
        if (i >= cnt) return  false;

        bool l = completeBinaryTree(root->left,2*i+1,cnt);
        bool r = completeBinaryTree(root->right,2*i+2,cnt);

        return (l && r);
    }
    bool isCompleteTree(TreeNode* root) {
        int cnt = countNode(root);
        return completeBinaryTree(root,0,cnt);
    }
};