class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
        vector<pair<int,int>> pairs;
        unordered_map<int, int> mp;
        auto cmp=[&](pair<int,int> a, pair<int, int> b){
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        };
        for (auto it : arr) mp[it]++;
        for (auto it : mp){
            pairs.push_back({it.first, it.second});
        }
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> ans;
        for (auto it : pairs){
            int freq = it.second, no = it.first;
            for (int i=0; i<freq; i++){
                ans.push_back(no);
            }
        }
        return ans;
    }
};