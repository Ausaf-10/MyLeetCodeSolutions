class Solution {
public:
    int n;
    void recursion(vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds, unordered_map<int, int> &mp){
        if (ds.size() == n){
            ans.push_back(ds);
            return ;
        }
        for (auto it : mp){
            int ele = it.first;
            if (mp[ele] == 0) continue;
            ds.push_back(ele);
            mp[ele]--;
            recursion(arr, ans, ds, mp);
            ds.pop_back();
            mp[ele]++;
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int, int> mp;
        for (auto it : arr) mp[it]++;
        recursion(arr, ans, ds, mp);
        return ans;
    }
};