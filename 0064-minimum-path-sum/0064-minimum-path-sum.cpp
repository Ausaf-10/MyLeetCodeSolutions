class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& grid){
        if (row == 0 && col == 0) return grid[0][0];
        int left = INT_MAX, up = INT_MAX;
        if (row > 0) up = recursion(row-1,col,grid);
        if (col > 0) left = recursion(row,col-1,grid);

        return grid[row][col] + min(up,left);
    }

    int memoization(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (row == 0 && col == 0) return grid[0][0];
        if (dp[row][col]!=-1) return dp[row][col];
        int left = INT_MAX, up = INT_MAX;
        if (row > 0) up = memoization(row-1,col,grid,dp);
        if (col > 0) left = memoization(row,col-1,grid,dp);

        return dp[row][col] = grid[row][col] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int> (m , -1));
        // return memoization(n-1, m-1, grid, dp);

        vector<vector<int>> tabulationDP(n, vector<int> (m , -1));
        for (int row=0; row<n; row++){
            for (int col=0; col<m; col++){
                if (row == 0 && col == 0) tabulationDP[0][0] = grid[0][0];
                else{
                    int left = INT_MAX, up = INT_MAX;
                    if (row > 0) up = tabulationDP[row-1][col];
                    if (col > 0) left = tabulationDP[row][col-1];
                    tabulationDP[row][col] = grid[row][col] + min(up,left);
                }
            }
        }
        return tabulationDP[n-1][m-1];
    }
};