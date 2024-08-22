class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto it: arr) mp[it]++;
        for (int i=1; i<=2001; i++){
            if (mp.find(i) == mp.end()){
                k--;
            }
            if (k == 0) return i;
        }
        return -1;
    }
};