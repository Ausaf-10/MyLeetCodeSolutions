class Solution {
public:
    
    int recursion(int indx){
        if (indx == 0) return 1;
        int pick = 0;
        if (indx > 1) pick = recursion(indx - 2);
        int notPick = recursion(indx - 1);
        return notPick + pick;
    }

    int memoization(int indx, vector<int>& dp){
        if (indx <= 1) return 1;
        int lt = memoization(indx-1, dp);
        int rt = memoization(indx-2, dp);
        return dp[indx] = lt+rt;
    }
    int tabulation(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        for (int indx=1; indx<=n; indx++){
            int pick = 0;
            if (indx > 1) pick = dp[indx - 2];
            int notPick = dp[indx - 1];
            dp[indx] = pick + notPick;
        }
        return dp[n];
    }
    int spaceOptimization(int n){
        int p1 = 1, p2 = 1;
        for (int i=2; i<=n; i++){
            int temp = p1 + p2;
            p2 = p1, p1 = temp;
        }
        return p1;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        return tabulation(n);
    }
};