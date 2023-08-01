class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
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

        int len = dp[n][m];

        string ans="";
        int i=n, j = m;
        while (i>0 && j>0){
            if (str1[i-1] == str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                ans+=str1[i-1]; 
                i--;
            }
            else{
                ans+=str2[j-1]; 
                j--;
            }
        }
        while (i > 0){
            ans+=str1[i-1];  
            i--;
        } 
        while (j > 0){
            ans+=str2[j-1];  
            j--;
        } 

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};