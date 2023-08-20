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
using ll = long long int; 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root->left && !root->right) return {(double)root->val};

        vector<double> ans;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()){
            int size = q.size();
            ll sum = 0;
            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            double avg = sum/(double)size;
            ans.push_back(avg);

        }

        return ans;
    }
};