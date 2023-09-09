class Solution {
public:
    // indx: n -> 0
    int recursion(int n){
        if (n <= 1) return 1;
        return recursion(n-1) + recursion(n-2);
    }

    int memoization(int n, vector<int>& dp){
        if (n <= 1) return 1;
        if (dp[n]!=-1) return dp[n];
        return memoization(n-1, dp) + memoization(n-2, dp);
    }
    int tabulation(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 1, dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // dp[0] = 1;
        // for (int i=1; i<=n; i++){
        //     int first = dp[i-1];
        //     int two = 0;
        //     if (i > 1) two = dp[i-2];
        //     dp[i] = first + two;
        // }
        // return dp[n];

        // return memoization(n,dp);

        // int prev  = 1, prev2 = 0;
        
        // for (int i=1; i<=n ; i++){
        //     int cur = prev + prev2;
        //     prev2 = prev , prev = cur;
        // }

        // return prev;

        return tabulation(n);
    }
};