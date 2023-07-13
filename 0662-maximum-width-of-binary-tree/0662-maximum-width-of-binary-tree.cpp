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
    int widthOfBinaryTree(TreeNode* root) {
        int width = INT_MIN;
        // NODE -> INDEX
        queue<pair<TreeNode*,int>> q;
        if (root == NULL) return 0;
        q.push({root,0});

        while (!q.empty()){
            
            int size = q.size();
            int first = q.front().second;
            int last = q.back().second;
            int mmin = q.front().second;

            for (int i=0; i<size; i++){
                long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                long long leftIndex = 2*cur_id+1;
                long long rightIndex = 2*cur_id+2;

                if (node->left!=NULL) q.push({node->left,leftIndex});
                if (node->right!=NULL) q.push({node->right,rightIndex});
            }
            width = max(width, last-first+1);
        }

        return width;
    }
};