class Solution {
public:
    int recursion(int n){
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        return recursion(n-1) + recursion(n-2) + recursion(n-3);
    }

    int memoization(int n, vector<int>& dp){
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (dp[n] != -1) return dp[n]; 
        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp) + memoization(n-3, dp);
    }

    int tabulation(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }

    int tribonacci(int n) {
        if (n == 0 ) return 0;
        if (n == 1 || n == 2)  return 1;
        return tabulation(n);
    }
};