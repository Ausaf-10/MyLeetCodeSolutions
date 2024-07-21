class Solution {
public:
    int n;
    int minChanges(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> diffArray(n/2, 0), limits(n/2,0);
        for (int i=0; i<n/2; i++){
            int diff = abs(arr[i] - arr[n-i-1]);
            diffArray[i] = diff;
            vector<int> temp = {arr[i], arr[n-i-1]};
            sort(temp.begin(), temp.end());
            limits[i] = max(temp[1], k-temp[0]);
        }
        unordered_map<int, int> mp;
        for (auto it : diffArray){
            mp[it]++;
        }
        int ans = 1e9;
        sort(limits.begin(), limits.end());
        for (auto it : mp){
            int diff = it.first;
            int lb = lower_bound(limits.begin(), limits.end(), diff) - limits.begin();
            int res = n/2 - it.second;
            ans = min(ans, res+lb);
        }
        return ans;

    }
};