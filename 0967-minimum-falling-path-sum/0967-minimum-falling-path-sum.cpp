class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& grid, int n){
        if (row == 0) return grid[row][col];
        int up = INT_MAX , upperLeft = INT_MAX, upperRight = INT_MAX;
        if (row > 0 ) up = recursion(row-1,col,grid,n);
        if (col > 0) upperLeft = recursion(row-1,col-1,grid,n);
        if (col < n-1) upperRight = recursion(row-1,col+1,grid,n);
        return grid[row][col] + min(up,min(upperRight,upperLeft));
    }

    int memoization(int row, int col, vector<vector<int>>& grid, int n, vector<vector<int>>& dp ){
        if (row == 0) return grid[row][col];
        if (dp[row][col]!=-1) return dp[row][col];

        int up = INT_MAX , upperLeft = INT_MAX, upperRight = INT_MAX;
        
        if (row > 0 ) up = memoization(row-1,col,grid,n,dp);
        if (col > 0) upperLeft = memoization(row-1,col-1,grid,n,dp);
        if (col < n-1) upperRight = memoization(row-1,col+1,grid,n,dp);
        
        return dp[row][col] = grid[row][col] + min(up,min(upperRight,upperLeft));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        // vector<vector<int>> memoizationDP(n, vector<int>(n,-1));

        // vector<vector<int>> tabulationDP(n, vector<int>(n,0));
        // for (int j=0; j<n; j++){
        //     tabulationDP[0][j] = matrix[0][j];
        // }

        // for (int row=1; row<n; row++){
        //     for (int col = 0; col < n; col++){
        //         int up = INT_MAX , upperLeft = INT_MAX, upperRight = INT_MAX;
            
        //         if (row > 0 ) up = tabulationDP[row-1][col];
        //         if (col > 0) upperLeft = tabulationDP[row-1][col-1];
        //         if (col < n-1) upperRight = tabulationDP[row-1][col+1];
        //         tabulationDP[row][col] = matrix[row][col] + min(up,min(upperRight,upperLeft));
        //     }
            
        // }

        vector<int> prev(n,0);
        for (int j = 0; j < n; j++){
            prev[j] = matrix[0][j];
        }
        for (int row = 1; row < n; row++){
            vector<int> temp(n,0);
            for (int col = 0; col < n; col++){
                int upperLeft = INT_MAX, upperRight = INT_MAX;
            
                int up = prev[col];
                if (col > 0) upperLeft = prev[col-1];
                if (col < n-1) upperRight = prev[col+1];
                temp[col] = matrix[row][col] + min(up,min(upperRight,upperLeft));
            }
            prev = temp;
        }

        for (int j= 0; j < n; j++){
            mini = min(mini, prev[j]);   
        }

        return mini;

        // for (int j=0; j<n; j++){
        //     mini = min(mini,memoization(n-1,j,matrix,n,memoizationDP));
        // }
        // return mini;
    }
};