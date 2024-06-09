class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        vector<int> freq[n+1];
        unordered_map<int,int> mp;
        for (auto it : arr) mp[it]++;
        for (auto it : mp){
            freq[it.second].push_back(it.first);
        }
        for (int i=n; i>=0; i--){
            for (auto ele: freq[i]){
                ans.push_back(ele);
                k--;
                if (k == 0) break;
            }
            if (k == 0) break;
        }
        return ans;
    }
};