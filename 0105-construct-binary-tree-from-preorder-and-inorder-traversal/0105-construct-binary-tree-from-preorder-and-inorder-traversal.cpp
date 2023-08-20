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
    TreeNode* solve(vector<int>& preorder, int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&mp){
        if (preStart > preEnd || inStart > inEnd) return NULL;

        int inRoot = mp[preorder[preStart]];
        int nelem = inRoot - inStart;

        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = solve(preorder, preStart+1, preStart+nelem, inorder,inStart,inRoot-1,mp);
        root->right = solve(preorder,preStart+nelem+1,preEnd, inorder, inRoot+1, inEnd, mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for (int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preStart =0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;
        return solve(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);

    }
};