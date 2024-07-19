class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i=0; i<n; i++){
            if (mp.find(arr[i]) != mp.end()){
                if (abs(i-mp[arr[i]]) <= k) return true;
            }
            mp[arr[i]]=i;
        }
        return false;
    }
};