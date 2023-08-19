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
using ll = long long int;

class Solution {
public:
    void solve(TreeNode* root, unordered_map<ll,ll>& mp ,int target, ll prefixSum, ll& cnt){
        if (root == NULL) return ;
        // mp[prefixSum]++;
        prefixSum+=root->val;

        ll rem = prefixSum - target;
        if (mp.find(rem) != mp.end()){
            cnt+=mp[rem];
        }
        
        mp[prefixSum]++;
        solve(root->left, mp, target, prefixSum, cnt);
        solve(root->right, mp, target, prefixSum, cnt);

        mp[prefixSum]--;
        if (mp[prefixSum] == 0) mp.erase(prefixSum);
        prefixSum-=root->val;
        return ;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,ll> mp; // PREFIXX SUM -> OCCURENCE
        ll prefixSum = 0, cnt = 0;
        mp[0] = 1;
        solve(root, mp, targetSum, prefixSum, cnt);
        return cnt;
    }
};