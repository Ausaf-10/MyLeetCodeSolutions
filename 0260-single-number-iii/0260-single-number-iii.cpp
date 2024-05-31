class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for (auto it : arr) mp[it]++;
        for (auto it : mp){
            if (it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};