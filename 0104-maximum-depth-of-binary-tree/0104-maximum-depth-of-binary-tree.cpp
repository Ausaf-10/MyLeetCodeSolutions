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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int mx = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                int lvl = q.front().second;
                mx = max(mx,lvl);
                q.pop();

                if (node->left!=NULL) q.push({node->left,lvl+1});
                if (node->right!=NULL) q.push({node->right,lvl+1});
            }
        }

        return mx;
    }
};