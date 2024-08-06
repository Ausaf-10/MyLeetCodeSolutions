class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for (auto it : s) mp[it]++;
        int start = mp.begin()->second;
        for (auto it : mp){
            if (it.second != start) return false;
        }
        return true;
    }
};