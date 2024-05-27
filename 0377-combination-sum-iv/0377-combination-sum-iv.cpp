class Solution {
public:
    int n;
    int solve(vector<int>& arr, int var_sum){
        if (var_sum == 0) return 1;
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (arr[i] > var_sum) continue;
            cnt += solve(arr, var_sum-arr[i]);
        }
        return cnt;
    }
    int memoization(vector<int>& arr, int var_sum, vector<int>& dp){
        if (var_sum == 0) return 1;
        if (dp[var_sum] != -1) return dp[var_sum];
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (arr[i] > var_sum) continue;
            cnt += memoization(arr, var_sum-arr[i], dp);
        }
        return dp[var_sum] = cnt;
    }
    int combinationSum4(vector<int>& arr, int target) {
        n = arr.size();
        vector<int> dp(target+1, -1);
        return memoization(arr, target, dp);
    }
};