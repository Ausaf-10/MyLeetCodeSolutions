class Solution {
public:
    int recursion(int row, int col, int n, int m){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        int upwards = recursion(row-1,col,n,m);
        int left =  recursion(row,col-1,n,m);
        return upwards + left;
    }

    int memoization(int row, int col, int n, int m, vector<vector<int>> &dp){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        if (dp[row][col]!=-1) return dp[row][col];
        
        int upwards = memoization(row-1,col,n,m,dp);
        int left =  memoization(row,col-1,n,m,dp);
        
        return dp[row][col] = upwards + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return memoization(m-1, n-1, m, n, dp);
    }
};