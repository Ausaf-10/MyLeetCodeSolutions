class Solution {
public:
    bool pallindrome(string& str, int i, int j, vector<vector<int>>& dp){
        if (i > j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (str[i] != str[j]) return dp[i][j] = false;
        return dp[i][j] = pallindrome(str, i+1, j-1, dp);
    }
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (pallindrome(s, i, j, dp)){
                    cnt++;
                }
            }   
        }
        return cnt;
    }
};