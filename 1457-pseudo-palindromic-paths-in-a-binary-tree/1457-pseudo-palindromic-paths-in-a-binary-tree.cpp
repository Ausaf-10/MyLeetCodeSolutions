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
    int findPseduoPalindromesDFs(TreeNode* root,vector<int> &freqArray)
    {
        if(root == nullptr)
            return 0;
        freqArray[root->val]++;
        int left = findPseduoPalindromesDFs(root->left,freqArray);
        int right = findPseduoPalindromesDFs(root->right,freqArray);
        if(!root->left && !root->right)
        {
            int oddCount  = 0;
            for(int i=1; i<=10; i++)
                if(freqArray[i] & 1) oddCount++;
            freqArray[root->val]--; 
            return oddCount <= 1;
        }
        freqArray[root->val]--; 
        return left + right;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freqArray(11,0);
        return findPseduoPalindromesDFs(root,freqArray);
    }
};