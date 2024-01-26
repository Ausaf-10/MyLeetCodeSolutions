using ll = long long int;
const int mod = 1e9+7; 
class Solution {
public:
    int n, m;
    bool isInvalid(int row, int col){
        if (row < 0 || row >= n || col < 0 || col>=m) return true;
        return false;
    }
    ll fun(int row, int col, int maxMove){
        
        if (isInvalid(row, col)){
            return 1;
        }

        if (maxMove == 0){
            if (isInvalid(row, col)) return 1;
            return 0;
        }

        int cnt = 0;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i=0; i<4; i++){
            
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            cnt=(cnt%mod + fun(nrow, ncol, maxMove-1))%mod;
            
        }

        return cnt;
    }

    ll memoization(int row, int col, int maxMove, vector<vector<vector<int>>>& dp){
        
        if (isInvalid(row, col)){
            return 1;
        }

        if (dp[row][col][maxMove] != -1) return dp[row][col][maxMove];

        if (maxMove == 0){
            if (isInvalid(row, col)) return 1;
            return 0;
        }

        int cnt = 0;
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i=0; i<4; i++){
            
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            cnt=(cnt%mod + memoization(nrow, ncol, maxMove-1, dp))%mod;
            
        }

        return dp[row][col][maxMove] = cnt;
    }

    int findPaths(int rows, int cols, int maxMove, int startRow, int startColumn) {
        n = rows, m = cols;
        if (maxMove == 0) return 0;
        
        vector<vector<int>> (n, vector<int>(m,-1));

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(maxMove+1,-1)));
        int cnt = memoization(startRow, startColumn, maxMove, dp);
        return cnt%mod;
    }
};