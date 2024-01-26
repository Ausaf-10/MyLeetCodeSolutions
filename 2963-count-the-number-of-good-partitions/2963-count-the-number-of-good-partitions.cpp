const int mod = 1e9+7;
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for (int i=0; i<n; i++) mp[arr[i]] = i;
        
        int ans = 1, j = mp[arr[0]];
        for (int i=0; i<n; i++){
            if (i > j){
                ans = ans * 2 % mod;
            }
            j = max(j, mp[arr[i]]);
        }
                          
        return ans;
                          
    }
};