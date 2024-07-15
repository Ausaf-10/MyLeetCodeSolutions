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
    vector<TreeNode*> solve(int n){
        if (!(n&1)) return {};
        if (n == 1) return {new TreeNode(0)};
        vector<TreeNode*> res;
        for (int i=1; i<n; i++){
            vector<TreeNode*> Left = solve(i);
            vector<TreeNode*> Right = solve(n-i-1);
            for (auto nodeL : Left){
                for (auto nodeR : Right){
                    TreeNode* root = new TreeNode(0);
                    root->left = nodeL, root->right = nodeR;
                    res.push_back(root);
                }
            }
        }
        return res;
    } 

    vector<TreeNode*> memoization(int n, unordered_map<int, vector<TreeNode*>>& mp){
        if (!(n&1)) return {};
        if (n == 1) return {new TreeNode(0)};
        if (mp.find(n) != mp.end()) return mp[n];
        vector<TreeNode*> res;
        for (int i=1; i<n; i++){
            vector<TreeNode*> Left = memoization(i, mp);
            vector<TreeNode*> Right = memoization(n-i-1, mp);
            for (auto nodeL : Left){
                for (auto nodeR : Right){
                    TreeNode* root = new TreeNode(0);
                    root->left = nodeL, root->right = nodeR;
                    res.push_back(root);
                }
            }
        }
        return mp[n] = res;
    } 

    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mp;
        return memoization(n, mp);
    }
};