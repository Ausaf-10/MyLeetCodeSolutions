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
    TreeNode* inorder(TreeNode* root, int k, int& cnt){
        if (root == NULL) return NULL;
        //LEFT
        TreeNode* lt = inorder(root->left,k,cnt);
       
        //ROOT
        cnt++;
        if (cnt == k) return root;
        
        //RIGHT 
        TreeNode* rt = inorder(root->right,k,cnt);
        
        if (lt == NULL) return rt;
        return lt;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        TreeNode* node = inorder(root,k,cnt);
        
        if (node!=NULL) return node->val;
        
        return -1;
    }
};