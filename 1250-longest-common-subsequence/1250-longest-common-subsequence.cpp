class Solution {
public:
    int n,m;
    int recursion(string s1, string s2, int indx1, int indx2){
        if (indx1 == 0 || indx2 == 0) return 0;
        int pick = -1e9, notPick = -1e9;
        if (s1[indx1-1] == s2[indx2-1]){
            pick = 1 + recursion(s1, s2, indx1-1, indx2-1);
        }
        else{
            int one = 0 + recursion(s1, s2, indx1-1, indx2);
            int two = 0 + recursion(s1, s2, indx1, indx2-1);
            notPick = max(one, two);
        }
        return max(pick, notPick);
    }
    int tabulation(string s1, string s2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int indx1=1; indx1<=n; indx1++){
            for (int indx2=1; indx2<=m; indx2++){
                int pick = -1e9, notPick = -1e9;
                if (s1[indx1-1] == s2[indx2-1]){
                    pick = 1 + dp[indx1-1][indx2-1];
                }
                else{
                    int one = 0 + dp[indx1-1][indx2];
                    int two = 0 + dp[indx1][indx2-1];
                    notPick = max(one, two);
                }
                dp[indx1][indx2] = max(pick, notPick);
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string s1, string s2) {
        n = s1.size(), m = s2.size();
        // return recursion(s1, s2, n, m);
        return tabulation(s1, s2);
    }
};