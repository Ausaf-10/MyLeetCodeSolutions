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
    pair<int,int> solve(TreeNode* root){
        if (root == NULL){
            pair<int,int> p = {0,0};
            return p;
        }
        if (root->left==NULL && root->right == NULL){
            pair<int,int> p = {root->val, 0};
            // with = root->val, without = 0;
            return p;
        }
        pair<int,int> lt = solve(root->left);
        pair<int,int> rt = solve(root->right);

        int with = root->val + rt.second + lt.second;
        int without = max(lt.first,lt.second) + max(rt.first,rt.second);
        pair<int,int> p = {with,without};
        
        return p;
    }
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) return root->val;

        pair<int,int> p = solve(root);
        return max(p.first,p.second);
    }
};