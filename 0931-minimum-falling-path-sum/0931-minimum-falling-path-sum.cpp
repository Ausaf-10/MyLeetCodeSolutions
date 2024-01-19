class Solution {
public:
    int n,m;
    int recursion(vector<vector<int>>& mat, int row, int col){
        if (col < 0 || col >= m ) return 1e9;
        if (row == 0)   return mat[0][col];

        int leftUp = recursion(mat, row-1, col-1);
        int up = recursion(mat, row-1, col);
        int rightUp = recursion(mat, row-1, col+1);

        return mat[row][col] + min(leftUp, min(up, rightUp));
    }
    int memoization(vector<vector<int>>& mat, int row, int col, vector<vector<int>>& dp){
        if (col < 0 || col >= m ) return 1e9;
        if (row == 0) return mat[0][col];

        if (dp[row][col] != -1) return dp[row][col];

        int leftUp = memoization(mat, row-1, col-1, dp);
        int up = memoization(mat, row-1, col, dp);
        int rightUp = memoization(mat, row-1, col+1, dp);

        return dp[row][col] = mat[row][col] + min(leftUp, min(up, rightUp));
    }
    int tabulation(vector<vector<int>>& mat){
        vector<vector<int>> dp(n, vector<int>(m,0));
        for (int j=0; j<m; j++){
            dp[0][j] = mat[0][j];
        }
        
        int mini = 1e9;
        
        for (int row=1; row<n; row++){
            for (int col=0; col<m; col++){
                int leftUp = 1e9, rightUp = 1e9;
                if (col-1 >= 0) leftUp = dp[row-1][col-1];
                int up = dp[row-1][col];
                if (col+1 < m) rightUp = dp[row-1][col+1];

                dp[row][col] = mat[row][col] + min(leftUp, min(up, rightUp));
            }
            
        }
        
        for (int j=0; j<m; j++) mini = min(mini, dp[n-1][j]);
        
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // int mini = 1e9;
        // for (int j=0; j<m; j++){
        //     mini = min(mini, tabulation(mat));
        // }
        // return mini;
        return tabulation(mat);
    }
};