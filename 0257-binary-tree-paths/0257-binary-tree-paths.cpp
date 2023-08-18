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
    void rootNodePath(TreeNode* root, vector<vector<int>>& ans, vector<int>& ds){
        if (root == NULL) return ;
        ds.push_back(root->val);
        
        rootNodePath(root->left, ans, ds);
        rootNodePath(root->right, ans, ds);
        
        if (root->left == NULL && root->right == NULL){
            ans.push_back(ds);
        }
       
        ds.pop_back();
        
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {""};
        if (!root->left && !root->right){
            string str = to_string(root->val);
            return {str};
        }

        vector<vector<int>> ans;
        vector<int> ds;
        rootNodePath(root, ans, ds);

        vector<string> res;

        for (int i=0; i<ans.size(); i++){
            string str = "";
            for (int j=0; j<ans[i].size(); j++){
                string s = to_string(ans[i][j]);
                if (j != ans[i].size()-1) s.append("->");
                str.append(s);
            }
            res.push_back(str);
        }

        return res;
    }
};