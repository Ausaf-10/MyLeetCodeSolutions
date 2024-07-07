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
    int n;
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, 
    int postStart, int postEnd, unordered_map<int, int>& inorderMap){
        
        if (inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int indx = inorderMap[postorder[postEnd]];    
        int nelem = indx - inStart;
    
        root->left = solve(postorder, inorder, inStart, indx-1, postStart, postStart+nelem-1, inorderMap);
        root->right = solve(postorder, inorder, indx+1, inEnd, postStart+nelem, postEnd-1, inorderMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        unordered_map<int, int> inorderMap;
        for (int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int inStart = 0, inEnd = n-1, postStart = 0, postEnd = n-1;
        return solve(postorder, inorder, inStart, inEnd, postStart, postEnd, inorderMap);
    }
};