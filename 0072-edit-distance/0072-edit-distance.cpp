class Solution {
public:

    int recursion(int indx1, int indx2, string &str1, string &str2){
        if (indx1 < 0) return indx2+1;
        if (indx2 < 0) return indx1+1;

        if (str1[indx1] == str2[indx2]){
            return 0 + recursion(indx1-1, indx2-1, str1, str2);
        }
        else{
            return min(1+recursion(indx1,indx2-1,str1,str2),min(1+recursion(indx1-1,indx2,str1,str2),1+recursion(indx1-1,indx2-1,str1,str2)));
        }
    }

    int memoization(int indx1, int indx2, string &str1, string &str2, vector<vector<int>>& dp){
        if (indx1 == 0) return indx2;
        if (indx2 == 0) return indx1;

        if (str1[indx1-1] == str2[indx2-1]){
            return dp[indx1][indx2] = memoization(indx1-1, indx2-1, str1, str2,dp);
        }
        else{
            return dp[indx1][indx2] = min(1+memoization(indx1,indx2-1,str1,str2,dp),min(1+memoization(indx1-1,indx2,str1,str2,dp),1+memoization(indx1-1,indx2-1,str1,str2,dp)));
        }
    }

    int tabulation(string str1, string str2){
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // BASE CASE
        for (int i=0; i<=n; i++) dp[i][0] = i;
        for (int i=0; i<=m; i++) dp[0][i] = i;

        for (int indx1=1; indx1<=n; indx1++){
            for (int indx2=1; indx2<=m; indx2++){
                if (str1[indx1-1] == str2[indx2-1]){
                    dp[indx1][indx2] = memoization(indx1-1, indx2-1, str1, str2,dp);
                }
                else{
                    dp[indx1][indx2] = min(1+memoization(indx1,indx2-1,str1,str2,dp),min(1+memoization(indx1-1,indx2,str1,str2,dp),1+memoization(indx1-1,indx2-1,str1,str2,dp)));
                }
            }
        }

        return dp[n][m];
    }

    int spaceOptimization(string str1, string str2){
        int n = str1.size(), m = str2.size();
        vector<int> prev(m+1,0);
        // BASE CASE
        for (int i=0; i<=m; i++) prev[i] = i;

        for (int indx1=1; indx1<=n; indx1++){
            vector<int> temp(m+1,0);
            temp[0] = indx1;
            for (int indx2=1; indx2<=m; indx2++){
                if (str1[indx1-1] == str2[indx2-1]){
                    temp[indx2] = prev[indx2-1];
                }
                else{
                    temp[indx2] = min(1+temp[indx2-1],min(1+prev[indx2],1+prev[indx2-1]));
                }
            }
            prev = temp;
        }

        return prev[m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return spaceOptimization(word1,word2);
        // return memoization(n, m, word1, word2, dp);   
        // return recursion(n-1,m-1,word1,word2);     
    }
};