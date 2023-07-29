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

        vector<vector<int>> memoizationDP (n , vector<int>(n,-1));

        return memoization(0,0,triangle,n, memoizationDP);
    }
};