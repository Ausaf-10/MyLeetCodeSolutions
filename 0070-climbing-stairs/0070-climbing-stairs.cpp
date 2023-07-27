class Solution {
public:
    // int fun(int n, vector<int>& dp){
    //     if (n<=0) return 0;
    //     if (n == 1 || n==2 ) return n;
    //     if (dp[n]!=-1) return dp[n];
    //     return dp[n] = fun(n-1,dp) + fun(n-2,dp);
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // dp[0] = 0, dp[1] = 1, dp[2] = 2;
        // if (n == 0 || n==1 || n==2 ) return dp[n];
        // for (int i=3; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        int a  = 1, b = 2;
        
        if (n == 1 || n == 2) return n;

        for (int i=3; i<=n ; i++){
            int c = a + b;
            a = b , b = c;
        }

        return b;
    }
};