class Solution {
public:
    void solve(int indx, int n, vector<int>& ds, vector<int>& nums, unordered_map<int,bool>& vis, vector<vector<int>>& ans){
        if (ds.size() == n){
            ans.push_back(ds);
            return ;
        }
        for (int i=0; i<n; i++){
            if (!vis[nums[i]]){
                vis[nums[i]] = true;
                ds.push_back(nums[i]);
                solve(i+1, n, ds, nums, vis, ans);
                ds.pop_back();
                vis[nums[i]]= false;
            }
        }

        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int,bool> vis;
        for (int i=0; i<nums.size(); i++) vis[nums[i]] = false;
        solve(0,n, ds, nums, vis, ans);
        return ans;
    }
};