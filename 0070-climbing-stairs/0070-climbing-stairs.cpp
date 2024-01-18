class Solution {
public:
    int memoization(int n, vector<int>& dp){
        if (n <= 1) return 1;
        if (dp[n]!=-1) return dp[n];
        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    }
    int tabulation(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1, dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int constantSpace(int n){
        int prev1 = 1, prev2 = 1;
        for (int i=2; i<=n; i++){
            int sum = prev1 + prev2;
            prev2 = prev1, prev1 = sum;
        }
        return prev1;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return memoization(n,dp);
        return constantSpace(n);
    }
};