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
    void leftView(TreeNode* root, vector<int>& ds, int level){
        if (!root) return ;
        if (ds.size() == level) ds.push_back(root->val);
        leftView(root->left, ds, level+1);
        leftView(root->right, ds, level+1);
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ds;
        leftView(root, ds, 0);
        return ds.back();
    }
};