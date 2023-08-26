class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        int sum = 0;

        for (int i=0; i<n; i++) dp[i][0] = mat[i][0]-'0';   // 0th COL 
        for (int j=0; j<m; j++) dp[0][j] = mat[0][j]-'0';     // 0th ROW
       
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++){
                if (mat[i][j] == '0') dp[i][j] = 0;      // AGAR 0 HAI TOH KOI SQUARE ISS ROW OR COL PE NHI MILEGA ! 
                else{
                    // AGAR 1 HAI TOH CHECK KRO JO BHI MIN HOGA WOH CONSIDER KIYA JAYEGA OTHERWISE MAX AGAR LENGE TOH RECTANGLE BHI MIL JAYENGE 
                    int up = dp[i-1][j], left = dp[i][j-1], upLeft = dp[i-1][j-1];
                    dp[i][j] = 1 + min(up,min(left,upLeft));          
                                                                        
                }
            }
        }

        int maxi = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi*maxi;
    }
};