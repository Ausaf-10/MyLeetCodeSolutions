class Solution {
public:
    bool checkPallindrome(string& str, int i, int j, vector<vector<int>>& dp){
        if (i > j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (str[i]!=str[j]) return dp[i][j] = false;
        return dp[i][j] = checkPallindrome(str, i+1, j-1, dp);
    }
    string longestPalindrome(string s) {
        int n = s.size(), maxi = 0, start = 0;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (checkPallindrome(s,i,j, dp)){
                    if ( j-i+1 > maxi){
                        maxi = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxi);
    }
};