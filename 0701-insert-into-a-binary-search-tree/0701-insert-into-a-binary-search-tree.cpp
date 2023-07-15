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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL){
            TreeNode* root = new TreeNode(val);
            return root;
        }
        TreeNode* cur = root;
        while (true){
            if (val >= cur->val){
                if (cur->right!=NULL) cur = cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if (cur->left!=NULL) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            
        }
        
        return root;
    }
};