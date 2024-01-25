class Solution {
public:
    int recursion(int indx1 , int indx2, string str1, string str2){
        if (indx1 < 0 || indx2 < 0) return 0;
        // MATCH
        if (str1[indx1] == str2[indx2])
            return 1 + recursion(indx1 - 1, indx2 - 1, str1, str2);
        // NOT MATCH
        return 0 + max(recursion(indx1, indx2 - 1, str1, str2), recursion(indx1 - 1, indx2, str1, str2));
    }

    int memoization(int indx1 , int indx2, string str1, string str2, vector<vector<int>>& dp){
        if (indx1 == 0 || indx2 == 0) return 0;
        
        if (dp[indx1][indx2] != -1) return dp[indx1][indx2];

        // MATCH
        if (str1[indx1-1] == str2[indx2-1])
            return dp[indx1][indx2] = 1 + memoization(indx1 - 1, indx2 - 1, str1, str2, dp);
        // NOT MATCH
        return dp[indx1][indx2] = 0 + max(memoization(indx1, indx2 - 1, str1, str2, dp), memoization(indx1 - 1, indx2, str1, str2, dp));
    }

    int tabulation(string str1, string str2){
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        // BASE CASE
        for (int j=0; j<=m; j++ ) dp[0][j] = 0;
        for (int i=0; i<=n; i++ ) dp[i][0] = 0;

        for (int indx1 = 1; indx1 <= n; indx1++){
            for (int indx2 = 1; indx2 <= m; indx2++){
                if (str1[indx1 - 1] == str2[indx2 - 1]){
                    dp[indx1][indx2] = 1 + dp[indx1 - 1][indx2 - 1];
                }
                else dp[indx1][indx2] =max(dp[indx1][indx2 - 1],dp[indx1 - 1][indx2]);
            }
        }
        return dp[n][m];
    }

    int spaceOptimization(string str1, string str2){
        int n = str1.size();
        int m = str2.size();

        vector<int> prev(m+1,0);
        for (int j = 0; j<=m; j++) prev[j] = 0;

        for (int indx1 = 1; indx1 <= n; indx1++){
            vector<int> temp(m+1,0);
            temp[0] = 0;
            for (int indx2 = 1; indx2 <= m; indx2++){
                if (str1[indx1 - 1] == str2[indx2 - 1]){
                    temp[indx2] = 1 + prev[indx2 - 1];
                }
                else temp[indx2] =max(temp[indx2 - 1],prev[indx2]);
            }

            prev = temp;
        }

        return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size();
        // int m = text2.size();
        
        // vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));

        // return tabulation(text1, text2);
        return spaceOptimization(text1, text2);
    }
};