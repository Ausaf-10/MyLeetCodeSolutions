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
    bool check(TreeNode* root, TreeNode* subRoot){
        if (root == NULL || subRoot == NULL){
            if (!root && !subRoot) return true;
            return false;
        } 
        return root->val == subRoot->val && check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if (!root) return false;
        bool lt,rt,my;
        if (root->val == subRoot->val){
            my = check(root, subRoot);
        }
        lt = solve(root->left, subRoot);
        rt = solve(root->right, subRoot);
        return lt || rt || my;
        
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};