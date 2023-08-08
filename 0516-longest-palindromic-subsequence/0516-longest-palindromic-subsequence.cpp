class Solution {
public:
    int recursion(int indx1, int indx2,string str1, string str2){
        if (indx1 == 0 || indx2 == 0) return 0;

        if (str1[indx1-1] == str2[indx2- 1]){
            return 1 + recursion(indx1-1, indx2-1, str1, str2);
        }
        else return 0 + max(recursion(indx1, indx2-1, str1, str2), recursion(indx1-1,indx2,str1,str2));
    }
    int memoization(int indx1, int indx2,string str1, string str2, vector<vector<int>>& dp){
        if (indx1 == 0 || indx2 == 0) return 0;
        
        if (dp[indx1][indx2] != -1) return dp[indx1][indx2];

        if (str1[indx1-1] == str2[indx2- 1]){
            return 1 + memoization(indx1-1, indx2-1, str1, str2,dp);
        }
        else return 0 + max(memoization(indx1, indx2-1, str1, str2,dp), memoization(indx1-1,indx2,str1,str2,dp));
    }
    int tabulation(string str1, string str2){
        int n = str1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for (int j=0; j<=n; j++) dp[0][j] = 0;
        for (int j=0; j<=n; j++) dp[j][0] = 0;

        for (int indx1 = 1; indx1<=n; indx1++){
            for (int indx2 = 1; indx2<=n; indx2++){
                if (str1[indx1-1] == str2[indx2- 1]){
                    dp[indx1][indx2] = 1 + dp[indx1-1][indx2-1];
                }
                else dp[indx1][indx2] = 0 + max(dp[indx1][indx2-1], dp[indx1-1][indx2]);
            }
        }
        return dp[n][n];

    }
    int spaceOptimization(string str1, string str2){
        int n = str1.size();
        vector<int> prev(n+1,0);

        for (int j=0; j<=n; j++) prev[j] = 0;
        // for (int j=0; j<=n; j++) dp[j][0] = 0;

        for (int indx1 = 1; indx1<=n; indx1++){
            vector<int> temp(n+1,0);
            temp[0] = 0;
            for (int indx2 = 1; indx2<=n; indx2++){
                if (str1[indx1-1] == str2[indx2- 1]){
                    temp[indx2] = 1 + prev[indx2-1];
                }
                else temp[indx2] = 0 + max(temp[indx2-1], prev[indx2]);
            }
            prev = temp;
        }
        return prev[n];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string ans = "";
        for (int i=n-1; i>=0; i--) ans.push_back(s[i]);

        return spaceOptimization(s, ans);
    }
};