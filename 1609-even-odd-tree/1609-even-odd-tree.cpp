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
    bool checkSortedDecreasing(vector<int>& arr){
        for (int i=1; i<arr.size(); i++){
            if (arr[i] >= arr[i-1]) return false;
        }
        return true;
    }
    bool checkSortedIncreasing(vector<int>& arr){
        for (int i=1; i<arr.size(); i++){
            if (arr[i] <= arr[i-1]) return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        if (root->val % 2 == 0) return false;
        queue<TreeNode*> q; q.push(root);
        int level = 0;
        while (!q.empty()){
            int size = q.size();
            vector<int> ds;
            for (int i=0; i<size; i++){
                auto node = q.front(); q.pop();
                if (level % 2 == 0){
                    if (node->val % 2 == 0) return false;
                }
                else{
                    if (node->val % 2 != 0) return false;
                }
                ds.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            bool x = checkSortedIncreasing(ds);
            bool y = checkSortedDecreasing(ds);
            if (level % 2 == 0){
                if (!x) return false;
            }
            else{
                if (!y) return false;
            }
            level++;
        }
        return true;
    }
};