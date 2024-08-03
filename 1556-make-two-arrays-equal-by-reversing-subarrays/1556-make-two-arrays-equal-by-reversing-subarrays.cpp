class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto it : target) mp[it]++;
        for (auto it : arr){
            if (mp.find(it ) == mp.end()) return false;
            mp[it]--;
        }
        for (auto it : mp){
            if (it.second != 0) return false;
        }
        return true;
    }
};