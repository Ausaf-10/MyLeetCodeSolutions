class Solution {
public:
    // TC: O(2^N*M), SC:O(N-1 + M-1)
    int recursion(int row, int col, int n, int m){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        int upwards = recursion(row-1,col,n,m);
        int left =  recursion(row,col-1,n,m);
        return upwards + left;
    }

    // MEMOIZATION -> TC:O(N*M), SC:O(N*M) + O(N-1 + M-1)
    int memoization(int row, int col, int n, int m, vector<vector<int>> &dp){
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0 ) return 0;
        if (dp[row][col]!=-1) return dp[row][col];
        
        int upwards = memoization(row-1,col,n,m,dp);
        int left =  memoization(row,col-1,n,m,dp);
        
        return dp[row][col] = upwards + left;
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int> (n,-1));


        // TABULATION -> TC:O(N*M), SC:O(N*M)
        // vector<vector<int>> dp(m, vector<int> (n,0));
        // for (int row=0; row < m; row++){
        //     for (int col = 0; col<n; col++){
        //         if (row == 0 && col == 0) dp[0][0] = 1;
        //         else{
        //             int left = 0, upwards = 0;
        //             if (row > 0) upwards = dp[row-1][col];
        //             if (col > 0)  left = dp[row][col-1];
        //             dp[row][col] = left + upwards;
        //         }
        //     }
        // }

        // return dp[m-1][n-1];

        // SPACE OPTIMIZATION
        vector<int> prev(n,0);
        for (int row=0; row < m; row++){
            vector<int> temp(n,0);
            for (int col = 0; col<n; col++){
                if (row == 0 && col == 0) temp[0] = 1;
                else{
                    int left = 0, upwards = 0;
                    if (row > 0) upwards = prev[col];
                    if (col > 0)  left = temp[col-1];
                    temp[col] = left + upwards;
                }
            }
            prev = temp;
        }

        return prev[n-1];
    }
};