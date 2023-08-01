class Solution {
public:
    int recursion(int indx1, int indx2,string str1, string str2){
        if (indx2 < 0) return 1;
        if (indx1 < 0) return 0;
        if (str1[indx1] == str2[indx2]){
            return recursion(indx1-1, indx2, str1, str2) + recursion(indx1-1, indx2-1, str1, str2);
        }
        return recursion(indx1-1, indx2, str1, str2);
    }

    int memoization(int indx1, int indx2,string str1, string str2, vector<vector<int>>& dp){
        if (indx2 == 0) return 1;
        if (indx1 == 0) return 0;
        if (dp[indx1][indx2]!=-1) return dp[indx1][indx2];
        
        if (str1[indx1-1] == str2[indx2-1]){
            return dp[indx1][indx2] = memoization(indx1-1, indx2, str1, str2, dp) + memoization(indx1-1, indx2-1, str1, str2, dp);
        }
        return dp[indx1][indx2] = memoization(indx1-1, indx2, str1, str2, dp);
    }

    int tabulation(string str1, string str2){
        int n = str1.size(), m = str2.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));
        // BASE CASE
        for (int j=1; j<=m; j++) dp[0][j] = 0;
        for (int i=0; i<=n; i++) dp[i][0] = 1;

        for (int indx1 = 1; indx1<=n; indx1++){
            for (int indx2 = 1; indx2<=m; indx2++){
                if (str1[indx1-1] == str2[indx2-1]){
                    dp[indx1][indx2] = (dp[indx1-1][indx2] + dp[indx1-1][indx2-1])%(int)(1e9+7);
                    // dp[indx1][indx2]+=dp[indx1-1][indx2-1];
                }
            
                else dp[indx1][indx2] =dp[indx1-1][indx2];
            }
            
        }

        return dp[n][m];
    }

    int numDistinct(string s, string t) {
        return tabulation(s, t);
    }
};