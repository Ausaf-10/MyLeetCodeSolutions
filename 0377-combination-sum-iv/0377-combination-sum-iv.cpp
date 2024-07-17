class Solution {
public:
    int n;
    int solve(int var_sum, vector<int>& arr){
        if (var_sum == 0) return 1;
        int ans = 0;
        for (int i=0; i<n; i++){
            if (arr[i] > var_sum) continue;
            ans += solve(var_sum-arr[i], arr);
        }
        return ans;
    }
    int tabulation(vector<int>& arr, int target){
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int var_sum = 1; var_sum<=target; var_sum++){
            long long ans = 0;
            for (int i=0; i<n; i++){
                if (arr[i] > var_sum) continue;
                ans = ans + dp[var_sum-arr[i]];
            }
            dp[var_sum] = ans;
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& arr, int target) {
        n = arr.size();
        return tabulation(arr, target);
    }
};