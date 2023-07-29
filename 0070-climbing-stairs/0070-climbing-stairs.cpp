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
        vector<int> dp(n+1,-1);
        // dp[0] = 0, dp[1] = 1, dp[2] = 2;
        // if (n == 0 || n==1 || n==2 ) return dp[n];
        // for (int i=3; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        return memoization(n,dp);

        // int a  = 1, b = 2;
        
        // if (n == 1 || n == 2) return n;

        // for (int i=3; i<=n ; i++){
        //     int c = a + b;
        //     a = b , b = c;
        // }

        // return b;
    }
};