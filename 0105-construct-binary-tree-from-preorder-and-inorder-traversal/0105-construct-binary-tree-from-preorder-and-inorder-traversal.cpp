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
    TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& inorderMap){
        if (preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int elem = inorderMap[root->val];
        int nelem = elem - inStart;
        
        root->left = constructTree(preorder, preStart+1, preStart + nelem, inorder, inStart, elem-1, inorderMap);
        root->right = constructTree(preorder, preStart + nelem + 1, preEnd, inorder, elem+1, inEnd, inorderMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for (int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;  // ELEMENT -> INDEX
        }
        
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;
        
        return constructTree(preorder,preStart,preEnd,inorder,inStart,inEnd,inorderMap);
        
    }
};