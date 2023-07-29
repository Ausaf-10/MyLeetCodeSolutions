class Solution {
public:
    int recursion(int n){
        if (n == 0) return 1;
        int first = recursion(n-1);
        int two = 0;
        if (n > 1) two = recursion(n-2);
        return first + two;
    }

    int memoization(int n, vector<int>& dp){
        if (n == 0) return 1;
        if (dp[n]!=-1) return dp[n];
        int first = memoization(n-1,dp);
        int two = 0;
        if (n > 1) two = memoization(n-2,dp);
        return dp[n] = first + two;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // dp[0] = 1;
        // for (int i=1; i<=n; i++){
        //     int first = dp[i-1];
        //     int two = 0;
        //     if (i > 1) two = dp[i-2];
        //     dp[i] = first + two;
        // }
        // return dp[n];

        // return memoization(n,dp);

        int prev  = 1, prev2 = 0;
        
        for (int i=1; i<=n ; i++){
            int cur = prev + prev2;
            prev2 = prev , prev = cur;
        }

        return prev;
    }
};