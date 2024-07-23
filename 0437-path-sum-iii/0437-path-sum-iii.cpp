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
        prefixSum+=root->val;

        if (prefixSum == target) cnt++;

        ll rem = prefixSum - target;
        if (mp.find(rem) != mp.end()){
            cnt+=mp[rem];
        }
        
        mp[prefixSum]++; // cnt badha do!
        solve(root->left, mp, target, prefixSum, cnt);
        solve(root->right, mp, target, prefixSum, cnt);

        mp[prefixSum]--; // jab wapas ayenge toh iska ek count kam hojayega and do not remove straight away bass ek cnt kam hoga!! 
        if (mp[prefixSum] == 0) mp.erase(prefixSum); // aur agar yeh poora zero hojayage tab aap remove kr skte ho !
        prefixSum-=root->val; // iss node ki value ko decrement kr denge!
        return ;
    }
    int pathSum(TreeNode* root, int targetSum) {

        // THIS QUESTION IS SIMILAR TO COUNT SUBARRAYS WITH SUM EQUAL K

        unordered_map<ll,ll> mp; // PREFIXX SUM -> OCCURENCE
        ll prefixSum = 0, cnt = 0;
        // mp[0] = 1;
        solve(root, mp, targetSum, prefixSum, cnt);
        return cnt;
    }
};