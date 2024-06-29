class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int row, int col, vector<vector<int>>& mat, int val){
        if (row >=0 && row<n && col>=0 && col<m && mat[row][col] > val) return true;
        return false;
    }
    int dfs(int row, int col, vector<vector<int>>& mat){
        int original = mat[row][col];
        mat[row][col] = -1;
        int left = 0, up = 0, right = 0, down = 0;
        if (col-1>=0 && mat[row][col-1] > original) left = dfs(row, col-1, mat);
        if (row-1>=0 && mat[row-1][col] > original) up = dfs(row-1, col, mat);
        if (col+1<m && mat[row][col+1] > original) right = dfs(row, col+1, mat);
        if (row+1<n && mat[row+1][col] > original) down = dfs(row+1, col, mat);
        mat[row][col] = original;
        return 1 + max(left, max(up, max(right, down)));
    }
    int memoization(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if (dp[row][col] != -1) return dp[row][col];
        int ans = 0;
        for (int i=0; i<4; i++){
            int nrow = row + dir[i][0], ncol = col + dir[i][1];
            if (isValid(nrow, ncol, mat, mat[row][col])){
                ans = max(ans, 1 + memoization(nrow, ncol, mat, dp));
            }
        }
        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int maxi = 0;
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                maxi = max(maxi, memoization(i,j,mat,dp));
            }
        }
        return maxi+1;
    }
};