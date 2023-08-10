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
    TreeNode* construct(vector<int>&arr, int start, int end){
        if (start > end) return NULL;
        int maxi = -1e9, indx = -1;
        for (int i=start; i<=end; i++){
            if (arr[i] > maxi){
                maxi = arr[i], indx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = construct(arr, start, indx-1);
        root->right = construct(arr, indx+1, end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
};