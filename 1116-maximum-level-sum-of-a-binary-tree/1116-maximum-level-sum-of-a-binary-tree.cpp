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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;

        long long maxi = LONG_MIN;
        long long indx = 1;

        queue<TreeNode*> q;
        long long level = 1;
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            long long sum = 0;

            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                sum = sum + node->val;

                if (node->left!=NULL) q.push(node->left);
                if (node->right!=NULL) q.push(node->right);
            }
            if (sum > maxi){
                maxi = sum;
                indx = level;
            }
            level++;
        }
       
        return indx;
    }
};