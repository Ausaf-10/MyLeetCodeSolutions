class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (auto& ele : arr){
            if (mp.find(ele) != mp.end()) return true;
            mp[ele]++;
        }
        return false;
    }
};