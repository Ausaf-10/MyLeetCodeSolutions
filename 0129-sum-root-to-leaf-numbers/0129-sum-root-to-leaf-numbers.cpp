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
    bool isLeaf(TreeNode* root){
        if (!root->left & !root->right) return true;
        return false; 
    }
    void rootToLeaf(TreeNode* root, vector<int>& path, vector<vector<int>>& ans){
        if (!root) return ;
        path.push_back(root->val);
        rootToLeaf(root->left, path, ans);
        rootToLeaf(root->right, path, ans);
        if (isLeaf(root)){
            ans.push_back(path);
        }
        path.pop_back();

        return ;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> ans;
        rootToLeaf(root, path, ans);
        int res = 0;
        for (int i=0; i<ans.size(); i++){
            int number = 0;
            for (int j=0; j<ans[i].size(); j++){
                int num = ans[i][j];
                number = number * 10 + num;

            }
            res+=number;
        }
        return res;
    }
};