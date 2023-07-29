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

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        // vector<vector<int>> memoizationDP(n,vector<int>(m,-1));
        // vector<vector<int>> tabulationDP(n,vector<int>(m,0));

        // for (int i=0; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         if (i == 0 && j == 0) tabulationDP[i][j] = 1;
        //         else{
        //             int left = 0, up = 0;
        //             if (i > 0 && obstacleGrid[i-1][j]!=1) up = tabulationDP[i-1][j];
        //             if (j > 0 && obstacleGrid[i][j-1]!=1) left = tabulationDP[i][j-1];
        //             tabulationDP[i][j] = left + up;
        //         }
        //     }
        // }

        // return tabulationDP[n-1][m-1];
        
        // SPACE OPTIMIZATION
        vector<int> prev(m,0);
        for (int row = 0; row< n; row++){
            vector<int> temp(m,0);
            for (int col = 0; col< m; col++){
                if (row == 0 && col == 0) temp[col] = 1;
                else{
                    int left = 0, up = 0;
                    if (row > 0 && obstacleGrid[row-1][col]!=1) up = prev[col];
                    if (col > 0 && obstacleGrid[row][col-1]!=1) left = temp[col-1];
                    temp[col] = left + up;
                }
            }
            prev = temp;
        }
        return prev[m-1];
        // return memoization(n-1,m-1, n, m, obstacleGrid,memoizationDP);
        // return recursion(n-1,m-1, n, m, obstacleGrid);
    }
};