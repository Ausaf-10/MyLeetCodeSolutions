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
    void fun(TreeNode* root, TreeNode* parent, TreeNode* grandParent, int &sum){
        if (!root) return ;
        if (grandParent && !(grandParent->val&1)) sum+=root->val;
        fun(root->left, root, parent, sum);
        fun(root->right, root, parent, sum);
        return ;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        fun(root, NULL, NULL, sum);
        return sum;
    }
};