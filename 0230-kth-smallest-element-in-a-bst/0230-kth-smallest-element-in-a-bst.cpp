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
        TreeNode* lt = inorder(root->left,k,cnt);
        cnt++;
        if (cnt == k) return root;

        TreeNode* rt = inorder(root->right,k,cnt);
        if (lt) return lt;
        return rt;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        TreeNode* node = inorder(root,k,cnt);
        
        return node == NULL ? -1 : node->val;
    }
};