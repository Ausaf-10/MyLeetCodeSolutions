class Solution {
public: 
    int n,m;
    // ROW: N-1->0, COL: M-1->0
    int recursion(vector<vector<int>>& grid, int row, int col){
        if (col < 0  || col >= m) return 1e9;
        if (row == 0) return grid[0][col];

        int up = recursion(grid, row-1, col) + grid[row][col];
        int upLeft = recursion(grid,row-1,col-1) + grid[row][col];
        int upRight = recursion(grid,row-1,col+1) + grid[row][col];
       
        return min(up,min(upLeft,upRight));  
    }

    int memoization(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &dp){
        if (col < 0  || col >= m) return 1e9;
        if (row == 0) return grid[0][col];

        if (dp[row][col]!=-1) return dp[row][col];

        int up = memoization(grid, row-1, col, dp) + grid[row][col];
        int upLeft = memoization(grid,row-1,col-1, dp) + grid[row][col];
        int upRight = memoization(grid,row-1,col+1, dp) + grid[row][col];
       
        return dp[row][col] = min(up,min(upLeft,upRight));  
    }

    int tabulation(vector<vector<int>>& grid){
        int mini = 1e9;
        vector<vector<int>> tabulationDP(n, vector<int>(n,0));
        for (int j=0; j<m; j++){
            tabulationDP[0][j] = grid[0][j];
        }
        for (int row=1; row<n; row++){
            for (int col=0; col<m; col++){
                int up = tabulationDP[row-1][col];
                int upperLeft = 1e9, upperRight = 1e9;
                if (col > 0) upperLeft = tabulationDP[row-1][col-1];
                if (col < n-1) upperRight = tabulationDP[row-1][col+1];
                tabulationDP[row][col] = grid[row][col] + min(up,min(upperRight,upperLeft));
                    
            }
        }
        for (int j=0; j<m; j++){
            mini = min(mini, tabulationDP[n-1][j]);
        }
        return mini;

    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        // int mini = 1e9;
        return tabulation(grid);

    }
};