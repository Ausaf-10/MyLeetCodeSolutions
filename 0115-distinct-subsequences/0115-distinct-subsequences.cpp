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

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return memoization(n, m, s, t, dp);
    }
};