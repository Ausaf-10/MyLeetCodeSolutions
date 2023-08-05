class Solution {
public:
    int recursion(int indx, int n){
        if (indx <= 1) return 1;
        int ans = 0;
        for (int i = 1; i<=indx; i++){
            ans+=recursion(i-1, n) * recursion(indx-i, n);
        }
        return ans;
    }
    int memoization(int indx, vector<int>& dp, int n){
        if (indx <= 1) return 1;
        if (dp[indx]!=-1) return dp[indx];
        int ans = 0;
        for (int i = 1; i<=indx; i++){
            ans+=memoization(i-1, dp, n) * memoization(indx-i, dp, n);
        }
        return dp[n] = ans;
    }
    int tabulation(int n){
        vector<int> dp(n+1,0);
        dp[0] = 1, dp[1] = 1;
        // i-> Represent the Number of Nodes
        for (int i=2; i<=n; i++){
            for (int j=1; j<=i; j++){
                // j-> Which nodes u take to be root node till ith number 
                dp[i] += dp[j-1]*dp[i-j];
            }
        }

        return dp[n];
    }
    int numTrees(int n) {
        return tabulation(n);
    }
};