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
    // SC: O(1)  -> USING MORRIS TRAVERSAL
   void flatten(TreeNode* root) {
        TreeNode* cur = root;
        
        while (cur){
            if (cur->left!=NULL){
                TreeNode* prev = cur->left;
                while (prev->right!=NULL){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur->right;
                    cur->right = cur->left;
                    cur->left = NULL;
                }
            }
            cur = cur->right;
        }

        return ;
    }
};