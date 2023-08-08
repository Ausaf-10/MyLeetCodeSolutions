class Solution {
public:
    int recursion(int row, int col){
        if (row == 0 && col == 0) return 1;
        int up = 0, left = 0;
        if (row > 0) up = recursion(row-1, col);
        if (col > 0) left = recursion(row, col-1);
        return up + left;
    }
    int memoization(int row, int col, vector<vector<int>>& dp){
        if (row == 0 && col == 0) return 1;
        if (dp[row][col]!=-1) return dp[row][col];
        int up = 0, left = 0;
        if (row > 0) up = memoization(row-1, col, dp);
        if (col > 0) left = memoization(row, col-1, dp);
        return dp[row][col] = up + left;
    }
    int tabulation(int n , int m){
        vector<vector<int>> dp(n, vector<int>(m,0));
        for (int row=0;row<n; row++){
            for (int col=0; col<m; col++){
                if (row == 0 && col == 0) dp[row][col] = 1;
                else{
                    int up = 0, left = 0;
                    if (row > 0) up = dp[row-1][col];
                    if (col > 0) left = dp[row][col-1];
                    dp[row][col] = up + left;
                }
            }
        }

        return dp[n-1][m-1];
    }
    int uniquePaths(int m, int n) {
        return tabulation(m,n);
    }
};