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
    void getLeaves(TreeNode* root, vector<int>& ds){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            ds.push_back(root->val);
            return ;
        }
        getLeaves(root->left, ds);
        getLeaves(root->right, ds);

        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        if (leaves1.size() != leaves2.size()) return false;
        for (int i=0; i<leaves1.size(); i++){
            if (leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};