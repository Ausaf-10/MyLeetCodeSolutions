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
    TreeNode* construct(vector<int>& arr){
        stack<TreeNode*> stk;
        for (int i=0; i<arr.size(); i++){
            TreeNode* node = new TreeNode(arr[i]);
            while (!stk.empty() && arr[i] > stk.top()->val){
                node->left = stk.top();
                stk.pop();
            }
            if (!stk.empty()){
                stk.top()->right = node;
            }
            stk.push(node);
        }
        while (stk.size()!=1){
            stk.pop();
        }
        return stk.top();
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums);
    }
};