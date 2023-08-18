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
    void fun(TreeNode* root, int sum, int target,vector<int>& ds, vector<vector<int>>&ans){
        if (root == NULL) return ;
        sum+=root->val;
        ds.push_back(root->val);
        fun(root->left, sum, target,ds,ans);
        fun(root->right, sum, target,ds,ans);

        if (root->left == NULL && root->right == NULL){
            if (sum == target){
                ans.push_back(ds);
            }
        }
        
        sum-=root->val;
        ds.pop_back();
        return ;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ds;
        vector<vector<int>> ans;
        fun(root,0,targetSum,ds,ans);
        return ans;
    }
};