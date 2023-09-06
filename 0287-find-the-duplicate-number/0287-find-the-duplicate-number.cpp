class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for (auto it : arr) mp[it]++;

        for (auto it : mp){
            if (it.second > 1) return it.first;
        }

        return -1;
    }
};