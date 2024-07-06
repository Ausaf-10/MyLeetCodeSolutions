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
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return NULL;
        int s = 0;
        if (root1 && root2){
            s += root1->val + root2->val;
        }
        else if (root1){
            s+=root1->val;
        }
        else{
            s+=root2->val;
        }
        TreeNode* node = new TreeNode(s);
        if (root1 && root2){
            node->left = solve(root1->left, root2->left);
        }
        else if (root1){
            node->left = solve(root1->left, root2);
        }
        else{
            node->left = solve(root1, root2->left);
        }

        if (root1 && root2){
            node->right = solve(root1->right, root2->right);
        }
        else if (root1){
            node->right = solve(root1->right, root2);
        }
        else{
            node->right = solve(root1, root2->right);
        }
        return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};