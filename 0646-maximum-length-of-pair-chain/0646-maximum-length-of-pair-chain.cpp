class Solution {
public: 
    bool compare(vector<int>& a, vector<int>& b){
        if (a[1] < b[0]) return true;
        return false;
    }
    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size(), maxi = 1;
        auto cmp = [&](vector<int> a, vector<int> b){
            return a[1] < b[1];
        };
        sort(arr.begin(), arr.end(),cmp);
        vector<int> dp(n,1);    
        for(int i=1; i<n; i++){
            for(int prev_index = 0; prev_index <i; prev_index ++){
                if( compare(arr[prev_index], arr[i]) && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};