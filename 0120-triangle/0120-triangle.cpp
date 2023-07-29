class Solution {
public:
    int recursion(int row, int col,vector<vector<int>>& grid, int n){
        if (row == n - 1) return grid[row][col];
        int down = recursion(row+1,col,grid,n);
        int diagonal = recursion(row+1,col+1,grid,n);
        return grid[row][col] + min(down,diagonal);
    }

    int memoization(int row, int col, vector<vector<int>>& grid, int n,vector<vector<int>>& dp){
        if (row == n - 1) return grid[row][col];
        if (dp[row][col]!=-1) return dp[row][col];
        int down = memoization(row+1,col,grid,n,dp);
        int diagonal = memoization(row+1,col+1,grid,n,dp);
        return dp[row][col] = grid[row][col] + min(down,diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // vector<vector<int>> memoizationDP (n , vector<int>(n,-1));
        vector<vector<int>> tabulationDP (n , vector<int>(n,0));
        // TABULATION
        
        // 1. WRITE THE BASE CASE
        // for (int j=0; j<n; j++){
        //     tabulationDP[n-1][j] = triangle[n-1][j];
        // }
        // // 2. START AFTER THE BASE CASE
        // for (int row = n-2; row >= 0; row--){
        //     for (int col = row ; col >= 0; col--){
                
        //         int down = tabulationDP[row+1][col];
        //         int diagonal = tabulationDP[row+1][col+1];
        //         tabulationDP[row][col] = triangle[row][col] + min(down,diagonal);
                
        //     }
        // }
        // return tabulationDP[0][0];
        vector<int> prev(n,0);
        for (int j=0; j<n; j++){
            prev[j] = triangle[n-1][j];
        }

        for (int row = n-2; row >= 0; row--){
            vector<int> temp(n,0);
            for (int col = row ; col >= 0; col--){
                int down = prev[col];
                int diagonal = prev[col+1];
                temp[col] = triangle[row][col] + min(down,diagonal);
            }
            prev = temp;
        }

        return prev[0];
        // return memoization(0,0,triangle,n, memoizationDP);
    }
};