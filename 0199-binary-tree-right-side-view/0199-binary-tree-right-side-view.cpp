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

    void rightView(TreeNode* root, int level, vector<int>& ds){
        // if (root == NULL) return ;
        if (ds.size() == level) ds.push_back(root->val);
        if (root->right!=NULL) rightView(root->right,level+1,ds);
        if (root->left!=NULL) rightView(root->left,level+1,ds);

        return ;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        rightView(root,0,ans);

        return ans;
    }
};