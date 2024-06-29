const int mod = 1e9+7;
using ll = long long int;
class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int row, int col, vector<vector<int>>& mat, int val){
        if (row >=0 && row<n && col>=0 && col<m && mat[row][col] > val) return true;
        return false;
    }
    int memoization(int row, int col, vector<vector<int>>& mat, vector<vector<int>> &dp){
        if (dp[row][col] != -1) return dp[row][col];
        ll ans = 0;
        for (int i=0; i<4; i++){
            int nrow = row + dir[i][0], ncol = col + dir[i][1];
            if (isValid(nrow, ncol, mat, mat[row][col])){
                ans = ans + 1;
                ans = ans + memoization(nrow, ncol, mat, dp);
                ans = ans%mod;
            }
        }
        return dp[row][col] = ans%mod;
    }
    int countPaths(vector<vector<int>>& mat) {
        ll cnt = 0;
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cnt += 1;
                cnt += memoization(i,j,mat, dp);
                cnt=cnt%mod;
            }
        }
        return cnt;
    }
};