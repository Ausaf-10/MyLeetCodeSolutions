class Solution {
public:
    int recursion(int n){
        if (n == 0 || n == 1) return n;
        return recursion(n-1) + recursion(n-2);
    }
    int memoization(int n, vector<int>& dp){
        if (n == 0 || n == 1) return n;
        if (dp[n]!=-1) return dp[n];
        return dp[n] = recursion(n-1) + recursion(n-2);
    }
    int tabulation(int n){
        vector<int> dp(n+1,0);
        dp[0] = 0, dp[1] = 1;
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int spaceOpimization(int n){
        if (n == 0 || n == 1) return n;
        int prev2 = 0, prev = 1;
        for (int i=2; i<=n; i++){
            int c = prev + prev2;
            prev2 = prev, prev = c; 
        } 
        return prev;
    }
    int fib(int n) {
        
        return spaceOpimization(n);
    }
};