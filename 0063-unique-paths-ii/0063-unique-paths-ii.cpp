class Solution {
public:
    int recursion(int row, int col, int numRows, int numCol, vector<vector<int>>& obstacleGrid){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        if (obstacleGrid[row][col] == 1) return 0;

        int up = recursion(row-1,col,numRows,numCol,obstacleGrid);
        int left = recursion(row,col-1,numRows,numCol,obstacleGrid);

        return up + left;

    }

    int memoization(int row, int col, int numRows, int numCol, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        if (obstacleGrid[row][col] == 1) return 0;

        if (dp[row][col] != -1) return dp[row][col];

        int up = memoization(row-1,col,numRows,numCol,obstacleGrid,dp);
        int left = memoization(row,col-1,numRows,numCol,obstacleGrid,dp);

        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> memoizationDP(n,vector<int>(m,-1));
        return memoization(n-1,m-1, n, m, obstacleGrid,memoizationDP);
        // return recursion(n-1,m-1, n, m, obstacleGrid);
    }
};