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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        bool leftToRight = true; // L -> R 
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // int indx = (leftToRight) ? i : (size-i-1);
                int indx;
                if (leftToRight == true) indx = i;
                else if (leftToRight == false) indx = (size-i-1);

                level[indx] = node->val;

                if (node->left!=NULL) q.push(node->left);
                if (node->right!=NULL) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
};