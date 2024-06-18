class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto ele : arr) mp[ele]++;
        for (auto it : mp){
            if (it.second > 1) return true;
        }
        return false;
    }
};