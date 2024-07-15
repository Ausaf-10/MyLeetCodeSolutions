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
    vector<TreeNode*> solve(int start, int end){
        if (start > end) return {NULL};
        vector<TreeNode*> ans;
        for (int i=start; i<=end; i++){
            vector<TreeNode*> Left = solve(start, i-1);
            vector<TreeNode*> Right = solve(i+1, end);
            for (auto nodeL: Left){
                for (auto nodeR: Right){
                    TreeNode* root = new TreeNode(i);
                    root->left = nodeL, root->right = nodeR;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};