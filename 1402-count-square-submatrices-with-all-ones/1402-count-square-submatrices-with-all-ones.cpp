// DP ON SQUARES 
// IN SUCH KIND OF PROBLEMS WE GENERALLY DONT DO RECURSION AND INSTEAD DO A TABULATION APPROACH
// COPY THE 0th ROW AND 0th COLOUMN AND THEN TAKE THE MIN OF UP,LEFT,DIAG LEFT AND ADD 1

class Solution {
public:
    int countSquares(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        int sum = 0;

        for (int i=0; i<n; i++) dp[i][0] = mat[i][0];   // 0th COL 
        for (int j=0; j<m; j++) dp[0][j] = mat[0][j];     // 0th ROW
       
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++){
                if (mat[i][j] == 0) dp[i][j] = 0;
                else{
                    int up = dp[i-1][j], left = dp[i][j-1], upLeft = dp[i-1][j-1];
                    dp[i][j] = 1 + min(up,min(left,upLeft));
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                sum+=dp[i][j];
            }
        }

        return sum;
    }
};