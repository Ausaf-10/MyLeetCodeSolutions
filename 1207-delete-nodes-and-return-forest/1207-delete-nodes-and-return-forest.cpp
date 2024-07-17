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
    void fun(TreeNode* root, unordered_set<int> &st, vector<TreeNode*>& ans){
        if (!root) return ;
        fun(root->left, st, ans);
        fun(root->right, st, ans);
        if (root->left){
            if (st.count(root->left->val)){
                root->left = NULL;
            }
        }
        if (root->right){
            if (st.count(root->right->val)){
                root->right = NULL;
            }
        }
        if (st.count(root->val)){
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
        }
        return ;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return {};
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        fun(root, st, ans);
        if (!st.count(root->val)) ans.push_back(root);
        return ans;
    }
};