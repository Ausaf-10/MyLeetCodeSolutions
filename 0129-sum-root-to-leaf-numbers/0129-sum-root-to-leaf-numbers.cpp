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
    void rootToLeafPaths(TreeNode* root, vector<int>& ds, vector<vector<int>>& ans){
        if (root == NULL) return ;
        ds.push_back(root->val);
        rootToLeafPaths(root->left, ds, ans);
        rootToLeafPaths(root->right, ds, ans);

        if (!root->left && !root->right){
            ans.push_back(ds);
        }

        ds.pop_back();

        return ;
    }
    int sumNumbers(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        vector<int> ds;
        vector<vector<int>> ans;
        rootToLeafPaths(root,ds,ans);
       
        vector<int> temp;
        for (int i=0; i<ans.size(); i++){
            int number = 0;
            for (int j=0; j<ans[i].size(); j++){
                number = number*10 + ans[i][j]; 
            }
            temp.push_back(number);
        }

        int sum = 0;
        for (auto it : temp) sum+=it;

        return sum;
    }
};