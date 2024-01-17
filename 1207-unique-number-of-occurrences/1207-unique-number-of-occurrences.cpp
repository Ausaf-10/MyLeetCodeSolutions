class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp, freq;
        for (auto it : arr){
            mp[it]++;
        }
        for (auto it : mp){
            freq[it.second]++;
        }
        int cnt = 0;
        for (auto it : freq){
            cnt+=it.first;
        }
        return cnt == arr.size() ? true : false;
    }
};